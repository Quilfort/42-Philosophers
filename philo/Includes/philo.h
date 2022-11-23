/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 08:53:04 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/23 08:56:15 by qfrederi      ########   odam.nl         */
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

typedef int				t_int32;
typedef unsigned int	t_uint32;
typedef long			t_int64;
typedef unsigned long	t_uint64;

# define PHILO_H

	// philo_utils
int		ft_atoi(const char *str);

#endif 