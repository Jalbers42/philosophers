/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:59:28 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/26 15:11:00 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define    PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct mutex {
	pthread_mutex_t	mutex;
	int				state;
}	t_mutex;
typedef struct data {
	int				population;
	int				time_to_die;
	int				eat_time;
	int				sleep_time;
	int				start_time;
	t_mutex			stop;
}	t_data;
typedef struct p_args {
	t_data			*data;
	int				id;
	int				state;
	int				last_meal;
	int				last_sleep;
	int				eat_count;
	int				eat_target;
	t_mutex			fork_1;
	t_mutex			*fork_2;
}	t_args;
int			init(t_data *data);
int			deinit(t_data *data);
int			read_inputs(t_data *data, char **argv);
int			text_to_num(char *argv);
int			current_time(void);
int			get_time(t_data *data);
int			create_philosphers_and_forks(t_data *data, char **argv);
int			insert_num(int num, char *sentence, int i);
int			error_check(int argc, char **argv);
int			take_forks(t_args *p_args, int counter);
int			release_forks(t_args *p_args);
int			len(int num);
int			insert_string(char *target, int index, char *string);
void		*life(void *args);
int			philo_died(t_args *p_args, int counter);
int			philo_is_eating(t_args *p_args, int counter);
int			philo_has_taken_forks(t_args *p_args, int counter);
int			philo_is_sleeping(t_args *p_args, int counter);
int			philo_is_thinking(t_args *p_args, int counter);
#endif