/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_to_term.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 10:17:05 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/30 11:05:14 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0') && (s1[i] == s2[i]) && (i + 1 < n))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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
	if (vars->active == true || ft_strncmp(string, "died", 4) == 0)
	{
		pthread_mutex_lock(&vars->lock_print);
		printf("%lu %d %s\n", time_of_day(), philo->id, string);
		pthread_mutex_unlock(&vars->lock_print);
	}
}
