/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:35:52 by jalbers           #+#    #+#             */
/*   Updated: 2023/05/03 18:08:17 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	end(t_data *data, int change)
{
	pthread_mutex_lock(&data->stop.mutex);
	if (data->stop.state == -1 || data->stop.state >= data->population)
	{
		data->stop.state = -1;
		pthread_mutex_unlock(&data->stop.mutex);
		return (-1);
	}
	else if (change == -1)
		data->stop.state = -1;
	else if (change == 1)
		data->stop.state++;
	pthread_mutex_unlock(&data->stop.mutex);
	return (0);
}

int	hungry(t_args *p_args, int time)
{
	if (p_args->eat_count == 0)
		return (1);
	else if ((time - p_args->last_meal) == p_args->data->time_to_die - 1)
		return (1);
	return (0);
}

int	get_action(t_args *p_args, int time)
{
	int		eat_time;
	int		sleep_time;

	eat_time = p_args->data->eat_time;
	sleep_time = p_args->data->sleep_time;
	if (p_args->state == 0 && hungry(p_args, time) == 1)
		return (1);
	else if (p_args->state == 1 && (time - p_args->last_meal) >= eat_time)
	{
		if (p_args->eat_count == p_args->eat_target && p_args->eat_target != 0)
			end(p_args->data, 1);
		return (2);
	}
	else if (p_args->state == 2 && (time - p_args->last_sleep) >= sleep_time)
		return (3);
	return (0);
}

void	*life(void *args)
{
	t_args	*p_args;
	t_data	*data;
	int		time;
	int		action;

	p_args = (t_args *)args;
	data = p_args->data;
	time = 0;
	while ((time - p_args->last_meal) < data->time_to_die && end(data, 0) == 0)
	{
		action = get_action(p_args, time);
		if (action == 1 && take_forks(p_args, time) == 1)
			philo_is_eating(p_args, time);
		else if (action == 2 && release_forks(p_args) == 1)
			philo_is_sleeping(p_args, time);
		else if (action == 3)
			philo_is_thinking(p_args, time);
		usleep(100);
		time = get_time(data);
	}
	if (end(p_args->data, -1) != -1)
		philo_died(p_args, time);
	return (NULL);
}
