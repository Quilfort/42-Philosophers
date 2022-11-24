/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pthread_protect.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 08:42:19 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/24 08:42:20 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_mutex_init(t_vars *vars, pthread_mutex_t *mutex)
{
	if (!mutex)
		return ;
	if (pthread_mutex_init(mutex, NULL) != 0)
		error_message(vars, "unable to initialize mutex");
}
