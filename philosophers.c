/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:56:22 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/25 17:09:35 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main (int argc, char **argv)
{
	t_data	data;

	error_check(argc, argv);
	init(&data);
	read_inputs(&data, argv);
	create_philosphers_and_forks(&data, argv);
	deinit(&data);
	return (0);
}