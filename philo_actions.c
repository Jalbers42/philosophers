/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:14:39 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/24 17:37:34 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int eat(t_args *p_args)
{
	if (p_args->data->population == 1)
		return (1);
	pthread_mutex_lock(&p_args->fork);
	pthread_mutex_lock(p_args->neighbours_fork);
	if (p_args->fork_state_1 == 0 && *p_args->fork_state_2 == 0)
	{
		p_args->fork_state_1 = 1;
		*p_args->fork_state_2 = 1;
		printf("%i %i has taken a fork\n", t_stamp(p_args->data), p_args->philo_id);
	}
	else
	{
		pthread_mutex_unlock(&p_args->fork);
		pthread_mutex_unlock(p_args->neighbours_fork);
		return (1);
	}
	pthread_mutex_unlock(&p_args->fork);
	pthread_mutex_unlock(p_args->neighbours_fork);
	philo_is_eating(p_args);
	pthread_mutex_lock(&p_args->fork);
	pthread_mutex_lock(p_args->neighbours_fork);
	p_args->fork_state_1 = 0;
	*p_args->fork_state_2 = 0;
	pthread_mutex_unlock(&p_args->fork);
	pthread_mutex_unlock(p_args->neighbours_fork);
	return (0);
}