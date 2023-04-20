/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:59:28 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/20 17:53:02 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define    PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>

typedef struct data {
	int		population;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		start_time;
}	t_data;
typedef struct philo_args {
	t_data	*data;
	int 	philo_id;
	int 	eat_count;
}	t_philo_args;
int 	init(t_data *data);
int		read_inputs(t_data *data, char **argv);
int		text_to_num(char *argv);
int		current_time();
int		create_philosphers(t_data *data, char **argv);
#endif