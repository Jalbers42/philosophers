/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:36:09 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/20 17:49:10 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	current_time()
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_usec);
}

// unsigned int	current_time()
// {
// 	struct timeval current_time;
//     unsigned int num;

// 	gettimeofday(&current_time, NULL);

//     num = current_time.tv_sec * 1000;
//     num += current_time.tv_usec / 1000;
// 	return (num);
// }