/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:56:22 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/20 17:51:48 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main (int argc, char **argv)
{
	t_data	data;

	if (argc < 4)
		return (0);
	init(&data);
	read_inputs(&data, argv);
	create_philosphers(&data, argv);
	
	return (0);
}