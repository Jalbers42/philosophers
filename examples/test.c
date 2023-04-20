/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:07:00 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/20 14:31:12 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int primes[10] = {0, 1, 2, 3, 4, 5, 66, 7, 8, 9};

void	*write_num(void *arg)
{
	int num  = *(int*)arg;
	printf("%i\n", num);
	return (NULL);
}

int	main()
{
	pthread_t	ids[10];
	int			i;
	
	i = 0;
	while (i < 10)
	{
		pthread_create(&ids[i], NULL, &write_num, &primes[i]);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		pthread_join(ids[i], NULL);
		i++;
	}
	return (0);
}