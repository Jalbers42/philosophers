/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:35:52 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/25 18:02:25 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	end(t_data *data, int change)
{
	pthread_mutex_lock(&data->stop_mutex);
	if (data->stop == 0)
	{
		if (change == 1)
			data->stop = 1;
		pthread_mutex_unlock(&data->stop_mutex);
		return (0);
	}
	pthread_mutex_unlock(&data->stop_mutex);
	return (1);
}

int	routine(t_args *p_args, int time, int eat_time, int sleep_time)
{
	if (p_args->state == 0 && start_eating(p_args, time) == 0)
	{
		p_args->last_meal = time;
		p_args->state = 1;
	}
	else if (p_args->state == 1 && (time - p_args->last_meal) >= eat_time)
	{
		stop_eating(p_args);
		philo_is_sleeping(p_args, time);
		p_args->state = 2;
		p_args->last_sleep = time;
	}
	else if (p_args->state == 2 && (time - p_args->last_sleep) >= sleep_time)
	{
		philo_is_thinking(p_args, time);
		p_args->state = 0;
	}
	return (0);
}

void	*life(void *args)
{
	t_args	*p_args;
	t_data	*data;
	int		time;

	p_args = (t_args *)args;
	data = p_args->data;
	time = t_stamp(p_args->data);
	while ((time - p_args->last_meal) < data->time_to_die && end(data, 0) == 0)
	{
		routine(p_args, time, data->eat_time, data->sleep_time);
		time = t_stamp(p_args->data);
	}
	if (end(p_args->data, 1) == 0)
		philo_died(p_args, time);
	return (NULL);
}
