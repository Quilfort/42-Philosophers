/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 08:58:06 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/24 12:06:13 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_vars	*vars;
	t_philo	*philo;

	if (check_arguments(argc, argv) == false)
		return (0);
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (parse_arguments(argc, argv, vars) == false)
		return (0);
	philo = (t_philo *)malloc(sizeof(t_philo));
	vars->active = true;
	init_philo(vars, philo);
	place_philo(vars, philo);
	create_threads(vars, philo);
	wait_join_threads(vars, philo);
	clean_threads(vars, philo);
	printf("This is vars philo = %d\n", vars->number_of_philosphers);
	printf("This is vars last meal = %ld\n", philo->last_meal);
	return (0);
}
