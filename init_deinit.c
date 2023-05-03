/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_deinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:49:39 by jalbers           #+#    #+#             */
/*   Updated: 2023/05/03 18:05:35 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init(t_data *data)
{
	data->start_time = current_time();
	pthread_mutex_init(&data->stop.mutex, NULL);
	data->stop.state = 0;
	return (0);
}

int	deinit(t_data *data)
{
	pthread_mutex_destroy(&data->stop.mutex);
	return (0);
}
