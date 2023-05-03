/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:36:09 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/26 10:59:44 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

int	get_time(t_data *data)
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

int	len(int num)
{
	int	count;

	count = 1;
	while (num >= 10)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	insert_string(char *target, int index, char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		target[index] = string[i];
		index++;
		i++;
	}
	return (index);
}
