/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 08:58:06 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/30 09:58:32 by qfrederi      ########   odam.nl         */
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
	if (create_philo(vars) == false)
	{
		printf("Could not create philosophers\n");
		return (1);
	}
	if (create_threads(vars) == false)
	{
		clean_threads(vars);
		return (1);
	}
	review_preformance(vars);
	wait_join_threads(vars);
	clean_threads(vars);
	return (0);
}
