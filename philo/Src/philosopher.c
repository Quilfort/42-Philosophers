/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 08:42:29 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/30 09:15:56 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_vars *vars, t_philo *philo)
{
	if (vars->active == false)
		return ;
	if (philo->id % 2)
	{
		philo_mutex_lock(vars, (pthread_mutex_t *)philo->right_fork);
		print_message(vars, philo, "has taken a Right fork");
		if (vars->number_of_philosphers == 1)
			return ;
		philo_mutex_lock(vars, (pthread_mutex_t *)philo->left_fork);
		print_message(vars, philo, "has taken a Left fork");
	}
	else
	{
		philo_mutex_lock(vars, (pthread_mutex_t *)philo->left_fork);
		print_message(vars, philo, "has taken a Left fork");
		philo_mutex_lock(vars, (pthread_mutex_t *)philo->right_fork);
		print_message(vars, philo, "has taken a Right fork");
	}
	print_message(vars, philo, "is eating");
	philo->last_meal = time_of_day();
	philo_sleep(vars->time_to_eat);
	philo->servings += 1;
	philo_mutex_unlock(vars, (pthread_mutex_t *)philo->right_fork);
	philo_mutex_unlock(vars, (pthread_mutex_t *)philo->left_fork);
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
}

void	*add_philo_to_thread(void *arg)
{
	t_vars	*vars;
	t_philo	*philo;

	vars = ((t_philo_data *)arg)->vars;
	philo = ((t_philo_data *)arg)->philo;
	free((t_philo_data *)arg);
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
