/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   use_threads.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 09:11:30 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/30 09:31:21 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_vars *vars)
{
	int				i;
	t_philo_data	*arg;

	i = 0;
	while (i < vars->number_of_philosphers)
	{
		arg = malloc(sizeof(t_philo_data));
		if (!arg)
			return ;
		arg->vars = vars;
		arg->philo = &vars->philo[i];
		pthread_create(&vars->philo[i].thread, NULL, add_philo_to_thread, \
						(void *) arg);
		i++;
	}
}

void	wait_join_threads(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->number_of_philosphers && vars->philo)
	{
		philo_pthread_join(vars->philo[i].thread);
		i++;
	}
}

void	clean_threads(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->number_of_philosphers)
	{
		philo_mutex_destroy(&vars->mutex[i]);
		i++;
	}
	philo_mutex_destroy(vars->mutex);
	free(vars->mutex);
	free(vars->philo);
	free(vars);
}
