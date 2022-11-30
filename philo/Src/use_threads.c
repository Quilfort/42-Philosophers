/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   use_threads.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 09:11:30 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/30 09:57:15 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_vars *vars)
{
	int				i;
	t_philo_data	*arg;

	i = 0;
	while (i < vars->number_of_philosphers)
	{
		arg = malloc(sizeof(t_philo_data));
		if (!arg)
			return (false);
		arg->vars = vars;
		arg->philo = &vars->philo[i];
		pthread_create(&vars->philo[i].thread, NULL, add_philo_to_routine, \
						(void *) arg);
		i++;
	}
	return (true);
}

int	wait_join_threads(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->number_of_philosphers && vars->philo)
	{
		philo_pthread_join(vars->philo[i].thread);
		i++;
	}
	return (true);
}

void	clean_threads(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->number_of_philosphers)
	{
		pthread_mutex_destroy(&vars->mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&vars->lock_data);
	pthread_mutex_destroy(&vars->lock_print);
	free(vars->mutex);
	free(vars->philo);
	free(vars);
}
