/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   use_threads.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 09:11:30 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/24 09:47:37 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_vars *vars, t_philo *philo)
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
		arg->philo = philo;
		pthread_create(&philo[i].thread, NULL, add_philo_to_thread, \
						(void *) arg);
		i++;
	}
}
