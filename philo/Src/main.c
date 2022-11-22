/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 08:58:06 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/11/22 11:19:10 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	only_digit(char *string)
{
	int	i;

	i = 0;

	while (string[i] != '\0')
	{
		printf("this is string[i] = %c\n", string[i]);
		if ((string[i] >= '0') && (string[i] <= '9'))
			i++;
		else
			return (false);
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;

	if (argc < 5 || argc > 6)
	{
		printf("Check your arguments\n");
		return (0);
	}
	while (argv[i] != NULL)
	{
		if (only_digit(argv[i]) == false)
		{
			printf("There is a character\n");
			return (0);
		}
		i++;
	}
	printf("%s\n", argv[1]);
	return (0);
}
