/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 08:53:04 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/24 13:10:25 by qfrederi      ########   odam.nl         */
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
int				check_arguments(int argc, char *argv[]);
int				parse_arguments(int argc, char *argv[], t_vars *vars);
void			init_philo(t_vars *vars);

	// philo_utils
int				ft_atoi(const char *str);
unsigned long	time_of_day(void);
size_t			ft_strlen(char *string);
void			philo_sleep(unsigned long millisecond);

	//philosopher
void			*place_philo(t_vars *vars);
void			*add_philo_to_thread(void *arg);

	//print_to_term
int				error_message(t_vars *vars, char *message);
void			print_message(t_vars *vars, t_philo *philo, char *string);

	//pthread_protect
void			philo_mutex_init(t_vars *vars, pthread_mutex_t *mutex);
void			philo_mutex_lock(t_vars *vars, pthread_mutex_t *mutex);
void			philo_mutex_unlock(t_vars *vars, pthread_mutex_t *mutex);
void			philo_pthread_join(pthread_t thread);
void			philo_mutex_destroy(pthread_mutex_t *mutex);

	//review_philo.c
void			review_preformance(t_vars *vars);

	//use_threads
void			create_threads(t_vars *vars);
void			wait_join_threads(t_vars *vars);
void			clean_threads(t_vars *vars);

#endif