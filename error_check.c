/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:36:00 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/25 14:53:09 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	valid_numbers_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	philo_eatcount_match(char **argv)
{
	int philo_count;
	int	i;

	if (!argv[5])
		return (0);
	philo_count = text_to_num(argv[1]);
	i = 5;
	while (argv[i])
		i++;
	if (philo_count != i - 5)
		return (1);
	return (0);
}

int error_check(int argc, char **argv)
{
	if (argc < 5)
	{
		write(1, "Error: Argument count needs to be at least 4\n", 45);
		exit(1);
	}
	else if (valid_numbers_check(argv) == 1)
	{
		write(1, "Error: Inputs do not consist of positive integers\n", 50);
		exit(1);
	}
	else if (philo_eatcount_match(argv) == 1)
	{
		write(1, "Error: Number of Philosophers does not match list of eat_counts\n", 64);
		exit(1);
	}
	return (0);
}
