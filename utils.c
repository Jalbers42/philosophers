/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:36:09 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/21 12:06:31 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	current_time()
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	
	return (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
}

int	t_stamp(t_data *data)
{
	return (current_time() - data->start_time);
}

int	insert_num(int num, char *sentence, int i)
{
	char	digit;

	if (num >= 10)
	{
		i = insert_num(num / 10, sentence, i);
		digit = (num % 10) + '0';
		sentence[i] = digit;
	}
	else if (num < 10)
	{
		digit = (num % 10) + '0';
		sentence[i] = digit;
	}
	return (i + 1);
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