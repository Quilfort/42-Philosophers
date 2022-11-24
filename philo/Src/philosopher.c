/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 08:42:29 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/24 12:04:25 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*place_philo(t_vars *vars, t_philo *philo)
{
	int	i;

	i = 0;
	philo[i].left_fork = &vars->mutex[vars->number_of_philosphers - 1];
	while (i < vars->number_of_philosphers)
	{
		philo[i].right_fork = &vars->mutex[i];
		if (i)
			philo[i].left_fork = &vars->mutex[i - 1];
		i++;
	}
	return (0);
}

static void	eating(t_vars *vars, t_philo *philo)
{
	if (vars->active == false)
		return ;
	if (philo->id % 2)
	{
		philo_mutex_lock(vars, (pthread_mutex_t *)philo->right_fork);
		print_message(vars, philo, "has taken a fork");
		if (vars->number_of_philosphers == 1)
			return ;
		philo_mutex_lock(vars, (pthread_mutex_t *)philo->left_fork);
		print_message(vars, philo, "has taken a fork");
	}
	else
	{
		philo_mutex_lock(vars, (pthread_mutex_t *)philo->left_fork);
		print_message(vars, philo, "has taken a fork");
		philo_mutex_lock(vars, (pthread_mutex_t *)philo->right_fork);
		print_message(vars, philo, "has taken a fork");
	}
	print_message(vars, philo, "is eating");
	philo->last_meal = time_of_day();
	philo->servings += 1;
	philo_mutex_lock(vars, (pthread_mutex_t *)philo->right_fork);
	philo_mutex_lock(vars, (pthread_mutex_t *)philo->left_fork);
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
		//thinking
		//sleeping
	}
	return (NULL);
}
