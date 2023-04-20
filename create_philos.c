/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:02:46 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/20 17:54:26 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*live(void *args)
{
	t_philo_args	*philo_args;
	philo_args = (t_philo_args *)args;
	printf("%i %i IS ALIVE! I need to eat %i times.\n",current_time() - philo_args->data->start_time, philo_args->philo_id, philo_args->eat_count);
	return (NULL);
}

// This function creates the philosophers as threads, starting their
// live function and giving them their ID and eat_count as parameters
// Would it be better to malloc all args as an array first???
int	create_philosphers(t_data *data, char **argv)
{
	pthread_t		*people;
	t_philo_args	*philo_args;
	int				i;

	people = malloc(data->population * sizeof(pthread_t));
	philo_args = malloc(data->population * sizeof(t_philo_args));
	memset(philo_args, 0, data->population * sizeof(t_philo_args));
	i = 0;
	while (i < data->population)
	{
		philo_args[i].data = data;
		philo_args[i].philo_id = i;
		if (argv[i + 4])
			philo_args[i].eat_count = text_to_num(argv[i + 4]);
		pthread_create(people + i, NULL, &live, (void *) &philo_args[i]);
		i++;
	}
	i = 0;
	while (i < data->population)
	{
		pthread_join(people[i], NULL);
		i++;
	}
	free (people);
	free (philo_args);
	return (0);
}
// // This function creates the philosophers as threads, starting their
// // live function and giving them their ID and eat_count as parameters
// // Would it be better to malloc all args as an array first???
// int	create_philosphers(t_data *data, char **argv)
// {
// 	pthread_t		people[data->population];
// 	t_philo_args	*philo_args;
// 	int				i;

// 	i = 0;
// 	while (i < data->population)
// 	{
// 		philo_args = malloc(sizeof(t_philo_args));
// 		philo_args->philo_id = i;
// 		if (argv[i + 4])
// 			philo_args->eat_count = text_to_num(argv[i + 4]);
// 		pthread_create(people + i, NULL, &live, (void *) philo_args);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < data->population)
// 	{
// 		pthread_join(people[i], NULL);
// 		i++;
// 	}
// 	return (0);
// }