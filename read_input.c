/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:57:00 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/25 17:39:54 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int input_data(t_data *data, int arg_num, int number)
{
	if (arg_num == 1)
		data->population = number;
	else if (arg_num == 2)
		data->time_to_die = number;
	else if (arg_num == 3)
		data->eat_time = number;
	else if (arg_num == 4)
		data->sleep_time = number;
	return (0);
}

int	text_to_num(char *argv)
{
	int i;
	int number;
	i = 0;
	number = 0;
	while (argv[i])
	{
		number *= 10;
		number += argv[i] - '0';
		i++;
	}
	return (number);
}

int	read_inputs(t_data *data, char **argv)
{
	int	i;
	int number;

	i = 1;
	while (i <= 4)
	{
		number = text_to_num(argv[i]);
		input_data(data, i, number);
		i++;
	}
	return (0);
}