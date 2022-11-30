/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 08:58:06 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/30 09:21:42 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_vars	*vars;

	if (check_arguments(argc, argv) == false)
		return (1);
	vars = ft_calloc(1, sizeof(t_vars));
	if (!vars)
		return (1);
	if (parse_arguments(argc, argv, vars) == false)
		return (1);
	vars->active = true;
	vars->philo = NULL;
	init_philo(vars);
	create_threads(vars);
	review_preformance(vars);
	wait_join_threads(vars);
	clean_threads(vars);
	return (0);
}
