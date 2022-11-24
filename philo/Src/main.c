/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 08:58:06 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/24 12:52:11 by qfrederi      ########   odam.nl         */
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
	vars->active = true;
	vars->philo = NULL;
	init_philo(vars);
	place_philo(vars);
	create_threads(vars);
	wait_join_threads(vars);
	clean_threads(vars);
	return (0);
}
