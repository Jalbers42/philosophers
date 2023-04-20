/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:22:31 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/20 13:10:48 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int					g_variable = 0;
pthread_mutex_t 	mutex;

void	*function()
{
	pthread_mutex_lock(&mutex);
	g_variable++;
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
	// printf("TEST\n");
	return (0);
}

void	*func2()
{
	// int	value = 2;
	int *result = malloc(sizeof(int));
	// *result = value;
	*result = 2;
	// pthread_mutex_lock(&mutex);
	// pthread_mutex_unlock(&mutex);
	printf("result addr: %p\n", result);
	return ((void *) result);
}

int main()
{
	// pthread_t	ids[10];
	// int			i;

	// pthread_mutex_init(&mutex, NULL);
	// i = 0;
	// while (i < 10)
	// {
	// 	pthread_create(&ids[i], NULL, &function, NULL);
	// 	i++;
	// }
	// i = 0;
	// while (i < 10)
	// {
	// 	pthread_join(ids[i], NULL);
	// 	i++;
	// }
	pthread_t   id;
	int			*get;
	
	pthread_create(&id, NULL, &func2, NULL);
	pthread_join(id,(void **) &get);
	// pthread_mutex_destroy(&mutex);
	printf("get value: %i\n", *get);
	printf("get addr: %p\n", get);
	free (get);
	return (0);
}











