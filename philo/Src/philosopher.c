/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 08:42:29 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/30 12:37:27 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	use_forks(t_vars *vars, t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock((pthread_mutex_t *)philo->right_fork);
		print_message(vars, philo, "has taken a fork");
		if (vars->number_of_philosphers == 1)
			return ;
		pthread_mutex_lock((pthread_mutex_t *)philo->left_fork);
		print_message(vars, philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock((pthread_mutex_t *)philo->left_fork);
		print_message(vars, philo, "has taken a fork");
		pthread_mutex_lock((pthread_mutex_t *)philo->right_fork);
		print_message(vars, philo, "has taken a fork");
	}
}

static void	eating(t_vars *vars, t_philo *philo)
{
	if (vars->active == false)
		return ;
	use_forks(vars, philo);
	if (vars->number_of_philosphers == 1)
		return ;
	print_message(vars, philo, "is eating");
	pthread_mutex_lock(&vars->lock_data);
	philo->last_meal = time_of_day();
	pthread_mutex_unlock(&vars->lock_data);
	philo_sleep(vars->time_to_eat);
	if (vars->amount_of_servings >= 0)
	{
		pthread_mutex_lock(&vars->lock_data);
		philo->servings += 1;
		pthread_mutex_unlock(&vars->lock_data);
	}
	pthread_mutex_unlock((pthread_mutex_t *)philo->right_fork);
	pthread_mutex_unlock((pthread_mutex_t *)philo->left_fork);
}

static void	thinking(t_vars *vars, t_philo *philo)
{
	if (vars->active == false)
		return ;
	print_message(vars, philo, "is thinking");
}

static void	sleeping(t_vars *vars, t_philo *philo)
{
	if (vars->active == false)
		return ;
	print_message(vars, philo, "is sleeping");
	philo_sleep(vars->time_to_sleep);
}

void	*add_philo_to_routine(void *arg)
{
	t_vars	*vars;
	t_philo	*philo;

	vars = ((t_philo_data *)arg)->vars;
	philo = ((t_philo_data *)arg)->philo;
	free(arg);
	while (vars->active == true)
	{
		eating(vars, philo);
		if (vars->number_of_philosphers == 1)
			return (NULL);
		thinking(vars, philo);
		sleeping(vars, philo);
	}
	return (NULL);
}
