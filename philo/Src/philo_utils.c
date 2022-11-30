/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 08:51:42 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/30 08:54:28 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	time_of_day(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	philo_sleep(unsigned long millisecond)
{
	unsigned long	current;

	current = time_of_day();
	while (time_of_day() - current < millisecond)
		usleep(100);
}

long	ft_atoi_long(const char *str)
{
	long	negative;
	long	i;
	long	num;

	i = 0;
	negative = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * negative);
}

size_t	ft_strlen(char *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*output;
	size_t	i;

	i = 0;
	output = malloc(count * size);
	if (!output)
		return (NULL);
	while (i < (count * size))
	{
		((char *)output)[i] = '\0';
		i++;
	}
	return (output);
}
