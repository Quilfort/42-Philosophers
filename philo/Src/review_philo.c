/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   review_philo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 13:06:54 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/30 10:37:50 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_philo_served(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->number_of_philosphers)
	{
		pthread_mutex_lock(&vars->lock_data);
		if (vars->philo[i].servings < vars->amount_of_servings)
		{
			pthread_mutex_unlock(&vars->lock_data);
			return (true);
		}
		pthread_mutex_unlock(&vars->lock_data);
		i++;
	}
	pthread_mutex_lock(&vars->lock_data);
	vars->active = false;
	pthread_mutex_unlock(&vars->lock_data);
	return (false);
}

static int	is_philo_death(t_vars *vars)
{
	int		i;
	long	diff;
	long	current;

	i = 0;
	current = time_of_day();
	while (i < vars->number_of_philosphers)
	{
		pthread_mutex_lock(&vars->lock_data);
		diff = current - vars->philo[i].last_meal;
		if (diff > vars->time_to_die)
		{
			pthread_mutex_unlock(&vars->lock_data);
			pthread_mutex_lock(&vars->lock_data);
			vars->active = false;
			pthread_mutex_unlock(&vars->lock_data);
			print_message(vars, &vars->philo[i], "died");
			return (false);
		}
		pthread_mutex_unlock(&vars->lock_data);
		i++;
	}
	return (true);
}

void	review_preformance(t_vars *vars)
{
	while (true)
	{
		if (vars->amount_of_servings >= 0)
		{
			if (is_philo_served(vars) == false)
				break ;
		}
		if (is_philo_death(vars) == false)
			break ;
		usleep(10);
	}
}
