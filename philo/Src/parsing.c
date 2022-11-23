/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 11:39:51 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/23 20:23:18 by quilfort      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(t_vars *vars, t_philo *philo)
{
	int	i;

	i = 0;
	vars->mutex = malloc(sizeof(pthread_mutex_t) * (vars->number_of_philosphers +1));
	if(!vars->mutex)
	{
		free(philo);
		philo = NULL;
		return ;
	}
	while (i < vars->number_of_philosphers)
	{
		philo->id = i + 1;
		philo->last_meal = time_of_day();
		philo_mutex_init(vars, &vars->mutex[i]);
		i++;
	}
	printf("This is %d\n", i);
	philo->servings = 0;
	philo_mutex_init(vars, &vars->mutex[i]);
}

int	parse_arguments(int argc, char *argv[], t_vars *vars)
{
	vars->number_of_philosphers = ft_atoi(argv[1]);
	if (vars->number_of_philosphers == 0)
	{
		printf("Must use at least 1 philosophers\n");
		return (false);
	}
	vars->time_to_die = ft_atoi(argv[2]) * 1000;
	vars->time_to_eat = ft_atoi(argv[3]) * 1000;
	vars->time_to_sleep = ft_atoi(argv[4]) * 1000;
	vars->amount_of_servings = -1;
	if (argc > 5)
		vars->amount_of_servings = ft_atoi(argv[5]);
	return (true);
}

int	check_arguments(int argc, char *argv[])
{
	int	i;
	int	k;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (false);
	}
	while (argv[i] != NULL)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			if ((argv[i][k] >= '0') && (argv[i][k] <= '9'))
				k++;
			else
			{
				printf("Numberic error\n");
				return (false);
			}
		}
		i++;
	}
	return (true);
}
