/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 08:58:06 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/23 08:42:16 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arguments(int argc, char *argv[])
{
	int	i;
	int	k;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (false);
	}
	while (argv[i] != NULL)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			if ((argv[i][k] >= '0') && (argv[i][k] <= '9'))
				k++;
			else
			{
				printf("Numberic error\n");
				return (false);
			}
		}
		i++;
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	if (check_arguments(argc, argv) == false)
		return (0);
	printf("%s\n", argv[1]);
	return (0);
}
