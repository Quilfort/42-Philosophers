/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 08:58:06 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/22 09:10:59 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{

	if (argc < 5 || argc > 6)
	{
		printf("Too much arguments\n");
		return (0);
	}	
	printf("%s\n", argv[1]);
	return (0);
}
