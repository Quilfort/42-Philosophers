/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pthread_protect.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 08:42:19 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/30 12:10:40 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_mutex_init(t_vars *vars, pthread_mutex_t *mutex)
{
	if (!mutex)
		return (false);
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		error_message(vars, "Unable to initialize Mutex");
		return (false);
	}
	return (true);
}

void	philo_pthread_join(pthread_t thread)
{
	if (!thread)
		return ;
	if (pthread_join(thread, NULL) != 0)
		printf("Unable to join Thread\n");
}
