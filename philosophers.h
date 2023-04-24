/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:59:28 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/24 17:04:03 by jalbers          ###   ########.fr       */
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
	int		*forks;
}	t_data;
typedef struct p_args {
	t_data			*data;
	int 			philo_id;
	int 			eat_count;
	pthread_mutex_t	fork;
	int				fork_state_1;
	pthread_mutex_t	*neighbours_fork;
	int				*fork_state_2;
}	t_args;
int 	init(t_data *data);
int		read_inputs(t_data *data, char **argv);
int		text_to_num(char *argv);
int		current_time();
int		t_stamp(t_data *data);
int		create_philosphers_and_forks(t_data *data, char **argv);
int		philo_died(t_args *p_args);
int		insert_num(int num, char *sentence, int i);
int 	error_check(int argc, char **argv);
int 	eat(t_args *p_args);
int		philo_is_eating(t_args *p_args);
#endif