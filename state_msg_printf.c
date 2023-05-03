/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_msg_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:43:16 by jalbers           #+#    #+#             */
/*   Updated: 2023/05/03 16:17:25 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// These functions display the changes in state of the philosophers
// Using
int	philo_died(t_args *p_args, int time)
{
	printf("%i %i died\n", time, p_args->id);
	return (0);
}

int	philo_is_eating(t_args *p_args, int time)
{
	printf("%i %i is eating\n", time, p_args->id);
	p_args->last_meal = time;
	p_args->eat_count++;
	p_args->state = 1;
	return (0);
}

int	philo_has_taken_forks(t_args *p_args, int time)
{
	printf("%i %i has taken a fork\n", time, p_args->id);
	printf("%i %i has taken a fork\n", time, p_args->id);
	return (0);
}

int	philo_is_sleeping(t_args *p_args, int time)
{
	printf("%i %i is sleeping\n", time, p_args->id);
	p_args->last_sleep = time;
	p_args->state = 2;
	return (0);
}

int	philo_is_thinking(t_args *p_args, int time)
{
	printf("%i %i is thinking\n", time, p_args->id);
	p_args->state = 0;
	return (0);
}
