/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:02:46 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/24 17:34:52 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	eat_check(int philo_id)
// {
// 	static int i == 0;

// 	if (philo_id % 2 == 0 && i % 2 == 0)
// 	{
// 		i++;
// 		return (1);
// 	}
// 	else if (philo_id % 2 == 1 && i % 2 == 1)
// 	{
// 		i++;
// 		return (1);
// 	}
// 	return (0);
// }

void	*live(void *args)
{
	t_args		*p_args;
	int			death_counter;
	int			last_meal;

	p_args = (t_args *)args;
	// printf("%i %i IS ALIVE! I need to eat %i times.\n", t_stamp(p_args->data), p_args->philo_id, p_args->eat_count);
	death_counter = t_stamp(p_args->data);
	last_meal = 0;
	while (death_counter < p_args->data->time_to_die)
	{
		// usleep(50);
		// if (p_args->philo_id % 2 == 1)
		if (eat(p_args) == 0)
			last_meal = t_stamp(p_args->data) - p_args->data->time_to_eat;
		death_counter = t_stamp(p_args->data) - last_meal;
		
		// death_counter = t_stamp(p_args->data) - last_meal;
	}
	philo_died(p_args);
	return (NULL);
}

int	create_threads(t_data *data, char **argv, pthread_t *people, t_args *p_args)
{
	int	i;

	i = 0;
	while (i < data->population)
	{
		pthread_mutex_init(&p_args[i].fork, NULL);
		p_args[i].fork_state_1 = 0;
		i++;
	}
	i = 0;
	while (i < data->population)
	{
		p_args[i].data = data;
		p_args[i].philo_id = i + 1;
		if (argv[i + 4])
			p_args[i].eat_count = text_to_num(argv[i + 4]);
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
		pthread_create(people + i, NULL, &live, (void *) &p_args[i]);
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
