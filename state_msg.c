/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:43:16 by jalbers           #+#    #+#             */
/*   Updated: 2023/04/25 18:05:51 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_died(t_args *p_args, int counter)
{
	char	*sentence;
	int		characters;
	int		i;

	characters = len(counter) + len(p_args->id) + 7;
	sentence = malloc((characters + 1) * sizeof(char));
	i = 0;
	i = insert_num(counter, sentence, i);
	sentence[i++] = ' ';
	i = insert_num(p_args->id, sentence, i);
	sentence[i++] = ' ';
	i = insert_string(sentence, i, "died");
	sentence[i++] = '\n';
	sentence[i] = '\0';
	write(1, sentence, characters);
	free(sentence);
	return (0);
}

int	philo_is_eating(t_args *p_args, int counter)
{
	char	*sentence;
	int		characters;
	int		i;

	characters = len(counter) + len(p_args->id) + 12;
	sentence = malloc((characters + 1) * sizeof(char));
	i = 0;
	i = insert_num(counter, sentence, i);
	sentence[i++] = ' ';
	i = insert_num(p_args->id, sentence, i);
	sentence[i++] = ' ';
	i = insert_string(sentence, i, "is eating");
	sentence[i++] = '\n';
	sentence[i] = '\0';
	write(1, sentence, characters);
	free(sentence);
	return (0);
}

int	philo_has_taken_forks(t_args *p_args, int counter)
{
	char	*sentence;
	int		characters;
	int		i;

	characters = len(counter) + len(p_args->id) + 17;
	sentence = malloc((characters + 1) * sizeof(char));
	i = 0;
	i = insert_num(counter, sentence, i);
	sentence[i++] = ' ';
	i = insert_num(p_args->id, sentence, i);
	sentence[i++] = ' ';
	i = insert_string(sentence, i, "has taken fork");
	sentence[i++] = '\n';
	sentence[i] = '\0';
	write(1, sentence, characters);
	write(1, sentence, characters);
	free(sentence);
	return (0);
}

int	philo_is_sleeping(t_args *p_args, int counter)
{
	char	*sentence;
	int		characters;
	int		i;

	characters = len(counter) + len(p_args->id) + 14;
	sentence = malloc((characters + 1) * sizeof(char));
	i = 0;
	i = insert_num(counter, sentence, i);
	sentence[i++] = ' ';
	i = insert_num(p_args->id, sentence, i);
	sentence[i++] = ' ';
	i = insert_string(sentence, i, "is sleeping");
	sentence[i++] = '\n';
	sentence[i] = '\0';
	write(1, sentence, characters);
	free(sentence);
	return (0);
}

int	philo_is_thinking(t_args *p_args, int counter)
{
	char	*sentence;
	int		characters;
	int		i;

	characters = len(counter) + len(p_args->id) + 14;
	sentence = malloc((characters + 1) * sizeof(char));
	i = 0;
	i = insert_num(counter, sentence, i);
	sentence[i++] = ' ';
	i = insert_num(p_args->id, sentence, i);
	sentence[i++] = ' ';
	i = insert_string(sentence, i, "is thinking");
	sentence[i++] = '\n';
	sentence[i] = '\0';
	write(1, sentence, characters);
	free(sentence);
	return (0);
}
