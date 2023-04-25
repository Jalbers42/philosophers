/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:14:39 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/25 18:06:31 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	update_fork_state(t_args *p_args, int num)
{
	p_args->fork_state_1 = num;
	*p_args->fork_state_2 = num;
	return (0);
}

int	start_eating(t_args *p_args, int counter)
{
	if (p_args->data->population == 1)
		return (1);
	pthread_mutex_lock(&p_args->fork);
	pthread_mutex_lock(p_args->neighbours_fork);
	if (p_args->fork_state_1 == 0 && *p_args->fork_state_2 == 0)
	{
		update_fork_state(p_args, 1);
		philo_has_taken_forks(p_args, counter);
	}
	else
	{
		pthread_mutex_unlock(&p_args->fork);
		pthread_mutex_unlock(p_args->neighbours_fork);
		usleep(1);
		return (1);
	}
	pthread_mutex_unlock(&p_args->fork);
	pthread_mutex_unlock(p_args->neighbours_fork);
	philo_is_eating(p_args, counter);
	return (0);
}

int	stop_eating(t_args *p_args)
{
	pthread_mutex_lock(&p_args->fork);
	pthread_mutex_lock(p_args->neighbours_fork);
	update_fork_state(p_args, 0);
	pthread_mutex_unlock(&p_args->fork);
	pthread_mutex_unlock(p_args->neighbours_fork);
	return (0);
}
