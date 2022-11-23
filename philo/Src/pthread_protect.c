#include "philo.h"

void	philo_mutex_init(t_vars *vars, pthread_mutex_t *mutex)
{
	if (!mutex)
		return ;
	if (pthread_mutex_init(mutex, NULL) != 0)
		error_message(vars, "unable to initialize mutex");
}
