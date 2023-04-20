/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:16:44 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/20 12:28:56 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Let us create a global variable to change it in threads
int g = 0;

typedef struct thread_args {
	int thread_id;
	int message;
}	t_args;

// The function to be executed by all threads
void *myThreadFun(void *thread)
{
	t_args	*args;

	args = (t_args*)thread;
	// Store the value argument passed to this thread
	int myid = args->thread_id;

	// Let us create a static variable to observe its changes
	static int s = 0;

	// Change static and global variables
	s++; g++;

	// Print the argument, static and global variables
	printf("Thread ID: %d, Static: %d, Global: %d\n", myid, s, g);
	pthread_exit(NULL);
	return NULL;
}


int main()
{
	int			i;
	pthread_t	tid[3];
	t_args		args[3];


	// Let us create three threads
	for (i = 0; i < 3; i++)
	{
		args[i].thread_id = i;
		args[i].message = i;
		if (pthread_create(&tid[i], NULL, myThreadFun, (void*) &args[i]) != 0)
			printf("ERROR");
	}

	  // Wait for threads to finish
	for (int i = 0; i < 3; i++) {
		pthread_join(tid[i], NULL);
	}
	return 0;
}


// // Let us create a global variable to change it in threads
// int g = 0;

// typedef struct thread_args {
// 	int thread_id;
// 	int message;
// }	t_args;

// // The function to be executed by all threads
// void *myThreadFun(void *thread)
// {
// 	t_args	*args;

// 	args = (t_args*)thread;
// 	// Store the value argument passed to this thread
// 	int myid = args->thread_id;

// 	// Let us create a static variable to observe its changes
// 	static int s = 0;

// 	// Change static and global variables
// 	s++; g++;

// 	// Print the argument, static and global variables
// 	printf("Thread ID: %d, Static: %d, Global: %d\n", myid, s, g);
// 	pthread_exit(NULL);
// 	return NULL;
// }


// int main()
// {
// 	int			i;
// 	pthread_t	tid[3];
// 	t_args		args[3];


// 	// Let us create three threads
// 	for (i = 0; i < 3; i++)
// 	{
// 		args[i].thread_id = i;
// 		args[i].message = i;
// 		if (pthread_create(&tid[i], NULL, myThreadFun, (void*) &args[i]) != 0)
// 			printf("ERROR");
// 	}

// 	  // Wait for threads to finish
// 	for (int i = 0; i < 3; i++) {
// 		pthread_join(tid[i], NULL);
// 	}
// 	return 0;
// }
