/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 11:39:51 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/30 09:05:01 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_arguments(int argc, char *argv[], t_vars *vars)
{
	vars->number_of_philosphers = ft_atoi_long(argv[1]);
	if (vars->number_of_philosphers == 0)
	{
		printf("Must use at least 1 philosophers\n");
		return (false);
	}
	vars->time_to_die = ft_atoi_long(argv[2]);
	vars->time_to_eat = ft_atoi_long(argv[3]);
	vars->time_to_sleep = ft_atoi_long(argv[4]);
	vars->amount_of_servings = -1;
	if (argc > 5)
		vars->amount_of_servings = ft_atoi_long(argv[5]);
	return (true);
}

static int	max_min_int(char *number)
{
	if (ft_atoi_long(number) > INT_MAX)
	{
		printf("Number must be lower than Int Max\n");
		return (false);
	}
	return (true);
}

static int	argc_count(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (false);
	}
	return (true);
}

int	check_arguments(int argc, char *argv[])
{
	int	i;
	int	k;

	i = 1;
	if (argc_count(argc) == false)
		return (false);
	while (argv[i] != NULL)
	{
		k = 0;
		if (max_min_int(argv[i]) == false)
			return (false);
		while (argv[i][k] != '\0')
		{
			if ((argv[i][k] >= '0') && (argv[i][k] <= '9'))
				k++;
			else
			{
				printf("Numeric error\n");
				return (false);
			}
		}
		i++;
	}
	return (true);
}
