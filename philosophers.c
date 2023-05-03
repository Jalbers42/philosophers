/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:56:22 by jalbers           #+#    #+#             */
/*   Updated: 2023/05/03 15:57:11 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	error_check(argc, argv);
	init(&data);
	read_inputs(&data, argv);
	// if (data->population == 1)
	// 	single_philo();
	if (create_philosphers_and_forks(&data, argv) != 0)
		printf("Error: Unable to create philosophers and forks.\n");
	deinit(&data);
	return (0);
}
