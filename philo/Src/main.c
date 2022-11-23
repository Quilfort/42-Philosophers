/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 08:58:06 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/23 12:06:43 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_vars	*vars;

	if (check_arguments(argc, argv) == false)
		return (0);
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (parse_arguments(argc, argv, vars) == false)
		return (0);
	printf("This is vars philo = %d\n", vars->number_of_philosphers);
	printf("This is vars time to eat = %d\n\n", vars->time_to_eat);
	return (0);
}
