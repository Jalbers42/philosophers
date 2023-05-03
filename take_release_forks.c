/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_release_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:14:39 by jalbers           #+#    #+#             */
/*   Updated: 2023/05/03 17:12:27 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	update_fork_state(t_args *p_args, int num)
{
	p_args->fork_1.state = num;
	p_args->fork_2->state = num;
	return (0);
}

int	take_forks(t_args *p_args, int time)
{
	pthread_mutex_lock(&p_args->fork_1.mutex);
	pthread_mutex_lock(&p_args->fork_2->mutex);
	if (p_args->fork_1.state == 0 && p_args->fork_2->state == 0)
	{
		update_fork_state(p_args, 1);
		pthread_mutex_unlock(&p_args->fork_1.mutex);
		pthread_mutex_unlock(&p_args->fork_2->mutex);
		philo_has_taken_forks(p_args, time);
		return (1);
	}
	pthread_mutex_unlock(&p_args->fork_1.mutex);
	pthread_mutex_unlock(&p_args->fork_2->mutex);
	return (0);
}

int	release_forks(t_args *p_args)
{
	pthread_mutex_lock(&p_args->fork_1.mutex);
	pthread_mutex_lock(&p_args->fork_2->mutex);
	update_fork_state(p_args, 0);
	pthread_mutex_unlock(&p_args->fork_1.mutex);
	pthread_mutex_unlock(&p_args->fork_2->mutex);
	return (1);
}
