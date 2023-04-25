/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:49:39 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/25 17:10:40 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init(t_data *data)
{
	data->start_time = current_time();
	pthread_mutex_init(&data->stop_mutex, NULL);
	data->stop = 0;
	return (0);
}

int deinit(t_data *data)
{
	pthread_mutex_destroy(&data->stop_mutex);
	return (0);
}