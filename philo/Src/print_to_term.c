/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_to_term.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 10:17:05 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/24 10:43:01 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_message(t_vars *vars, char *message)
{
	vars->active = false;
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

void	print_messsage(t_vars *vars, t_philo *philo, char *string)
{
	pthread_mutex_lock(&vars->mutex[vars->number_of_philosphers]);
	if (vars->active)
		printf("%lu %d %s\n", time_of_day(), philo->id, string);
	pthread_mutex_unlock(&vars->mutex[vars->number_of_philosphers]);
}
