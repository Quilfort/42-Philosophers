/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 08:53:04 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/23 17:31:07 by qfrederi      ########   odam.nl         */
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

typedef struct s_philo
{
	int			id;
	int			servings;
	long		last_meal;
	void		*right_fork;
	void		*left_fork;
	pthread_t	thread;

}	t_philo;

typedef struct s_vars
{
	int				active;
	int				number_of_philosphers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				amount_of_servings;
	pthread_mutex_t	*mutex;
	t_philo			*philo;
}	t_vars;

typedef struct s_philo_data
{
	t_vars		*vars;
	t_philo		*philo;
}	t_philo_data;

	// parsing.c
int		check_arguments(int argc, char *argv[]);
int		parse_arguments(int argc, char *argv[], t_vars *vars);

	// philo_utils
int		ft_atoi(const char *str);

#endif 