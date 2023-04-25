/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:02:46 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/25 17:47:49 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	initialize_mutexes(t_data *data, t_args *p_args)
{
	int	i;

	i = 0;
	while (i < data->population)
	{
		pthread_mutex_init(&p_args[i].fork, NULL);
		p_args[i].fork_state_1 = 0;
		i++;
	}
	return (0);
}

int	create_threads(t_data *data, char **argv, pthread_t *people, t_args *p_args)
{
	int	i;

	initialize_mutexes(data, p_args);
	i = 0;
	while (i < data->population)
	{
		p_args[i].data = data;
		p_args[i].id = i + 1;
		p_args[i].state = 0;
		p_args[i].last_meal = 0;
		p_args[i].last_sleep = 0;
		if (argv[i + 5])
			p_args[i].eat_count = text_to_num(argv[i + 5]);
		if (i == 0)
		{
			p_args[i].neighbours_fork = &p_args[data->population - 1].fork;
			p_args[i].fork_state_2 = &p_args[data->population - 1].fork_state_1;
		}
		else
		{
			p_args[i].neighbours_fork = &p_args[i - 1].fork;
			p_args[i].fork_state_2 = &p_args[i - 1].fork_state_1;
		}
		pthread_create(people + i, NULL, &life, (void *) &p_args[i]);
		i++;
	}
	return (0);
}

// This function creates the philosophers as threads, starting their
// live function and giving them their ID, eat_count and the data
int	create_philosphers_and_forks(t_data *data, char **argv)
{
	pthread_t		*people;
	t_args			*p_args;
	int				i;

	people = malloc(data->population * sizeof(pthread_t));
	p_args = malloc(data->population * sizeof(t_args));
	// memset(p_args, 0, data->population * sizeof(t_args));
	create_threads(data, argv, people, p_args);
	i = 0;
	while (i < data->population)
		pthread_join(people[i++], NULL);
	i = 0;
	while (i < data->population)
		pthread_mutex_destroy(&p_args[i++].fork);
	free (people);
	free (p_args);
	return (0);
}
