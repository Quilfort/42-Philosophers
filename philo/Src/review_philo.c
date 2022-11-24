/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   review_philo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 13:06:54 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/24 14:29:52 by qfrederi      ########   odam.nl         */
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
			return (0);
		i++;
	}
	vars->active = false;
	return (1);
}

static int	is_philo_death(t_vars *vars)
{
	int		i;
	long	diff;
	long	current;

	i = 0;
	current = time_of_day();

}

void	review_preformance(t_vars *vars)
{
	while (true)
	{
		if (is_philo_served(vars) == 1)
			break ;
	}
	usleep(10);
}
