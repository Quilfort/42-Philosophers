/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_to_term.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 10:17:05 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/30 10:21:20 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(t_vars *vars, char *message)
{
	vars->active = false;
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, message, ft_strlen(message));
	wait_join_threads(vars);
	clean_threads(vars);
	return (EXIT_FAILURE);
}

void	print_message(t_vars *vars, t_philo *philo, char *string)
{
	if (vars->active == true)
	{
		pthread_mutex_lock(&vars->lock_print);
		printf("%lu %d %s\n", time_of_day(), philo->id, string);
		pthread_mutex_unlock(&vars->lock_print);
	}
}
