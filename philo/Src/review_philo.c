/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   review_philo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 13:06:54 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/28 12:24:19 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_philo_served(t_vars *vars)
{
	int	i;

	if (vars->number_of_philosphers < 0)
		return (0);
	i = 0;
	while (i < vars->number_of_philosphers)
	{
		if (vars->philo[i].servings < vars->amount_of_servings)
			return (true);
		i++;
	}
	vars->active = false;
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
		diff = current - vars->philo[i].last_meal;
		if (diff > vars->time_to_die)
		{
			vars->active = false;
			print_message(vars, &vars->philo[i], "died");
			return (true);
		}
		i++;
	}
	return (false);
}

void	review_preformance(t_vars *vars)
{
	while (true)
	{
		if (is_philo_served(vars) == false)
			break ;
		if (is_philo_death(vars) == true)
			break ;
		usleep(10);
	}
	usleep(10);
}
