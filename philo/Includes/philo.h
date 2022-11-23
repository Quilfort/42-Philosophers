/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 08:53:04 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/23 12:03:01 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

# define PHILO_H

typedef struct s_vars
{
	int	number_of_philosphers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	amount_of_servings;
}	t_vars;

	// parsing.c
int		check_arguments(int argc, char *argv[]);
int		parse_arguments(int argc, char *argv[], t_vars *vars);

	// philo_utils
int		ft_atoi(const char *str);

#endif 