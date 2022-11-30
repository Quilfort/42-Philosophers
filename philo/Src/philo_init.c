/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 09:04:38 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/30 12:07:56 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	place_forks(t_vars *vars)
{
	int	i;

	i = 0;
	vars->philo[i].left_fork = &vars->mutex[vars->number_of_philosphers - 1];
	while (i < vars->number_of_philosphers)
	{
		vars->philo[i].right_fork = &vars->mutex[i];
		if (i != 0)
			vars->philo[i].left_fork = &vars->mutex[i - 1];
		i++;
	}
}

int	clean_mutex(t_vars *vars, int i)
{
	while (i >= 0)
	{
		pthread_mutex_destroy(&vars->mutex[i]);
		i--;
	}
	free(vars->mutex);
	free(vars->philo);
	free(vars);
	return (false);
}

static bool	init_philo(t_vars *vars)
{
	int	i;

	i = 0;
	vars->philo = ft_calloc(vars->number_of_philosphers, sizeof(t_philo));
	if (!vars->philo)
		return (false);
	vars->mutex = ft_calloc(vars->number_of_philosphers, \
		sizeof(pthread_mutex_t));
	if (!vars->mutex)
	{
		free(vars->philo);
		vars->philo = NULL;
		return (false);
	}
	return (true);
}

bool	create_philo(t_vars *vars)
{
	int	i;

	if (init_philo(vars) == false)
		return (false);
	i = 0;
	while (i < vars->number_of_philosphers)
	{
		vars->philo[i].id = i + 1;
		vars->philo[i].last_meal = time_of_day();
		if (philo_mutex_init(vars, &vars->mutex[i]) == false)
			return (clean_mutex(vars, i - 1));
		i++;
	}
	if (philo_mutex_init(vars, &vars->lock_data) == false)
		return (clean_mutex(vars, i - 1));
	if (philo_mutex_init(vars, &vars->lock_print) == false)
		return (clean_mutex(vars, i - 1));
	place_forks(vars);
	return (true);
}
