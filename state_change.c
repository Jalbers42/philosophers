/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:43:16 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/24 15:46:03 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

int	philo_died(t_args *p_args)
{
	char	*sentence;
	int		digits;
	int		i;

	digits = len(t_stamp(p_args->data)) + len(p_args->philo_id) + 8;
	sentence = malloc(digits * sizeof(char));
	i = 0;
	i = insert_num(t_stamp(p_args->data), sentence, i);
	sentence[i++] = ' ';
	i = insert_num(p_args->philo_id, sentence, i);
	sentence[i++] = ' ';
	i = insert_string(sentence, i, "died");
	sentence[i++] = '\n';
	sentence[i] = '\0';
	write(1, sentence, digits);
	free(sentence);
	return (0);
}

int	philo_is_eating(t_args *p_args)
{
	char	*sentence;
	int		digits;
	int		i;

	digits = len(t_stamp(p_args->data)) + len(p_args->philo_id) + 13;
	sentence = malloc(digits * sizeof(char));
	i = 0;
	i = insert_num(t_stamp(p_args->data), sentence, i);
	sentence[i++] = ' ';
	i = insert_num(p_args->philo_id, sentence, i);
	sentence[i++] = ' ';
	i = insert_string(sentence, i, "is eating");
	sentence[i++] = '\n';
	sentence[i] = '\0';
	write(1, sentence, digits);
	free(sentence);
	usleep(p_args->data->time_to_eat * 1000);
	return (0);
}
