/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:29:49 by itahri            #+#    #+#             */
/*   Updated: 2024/06/07 20:30:07 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_queue	*init_queue(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(*queue));
	if (!queue)
		return (NULL);
	queue->first = NULL;
	return (queue);
}

void  put_on_queue(t_queue *queue, const char *input, const char **command)
{
	t_element *new;
	t_element *current;


	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->input = (char *)input;
	new->command = (char **)command;
	new->next = NULL;
	if (queue->first)
	{
		current = queue->first;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else
		queue->first = new;
}

void  get_out_queue(t_queue *queue)
{
	t_element *current;

	if (!queue)
		return ;

	if (queue->first)
	{
		current = queue->first;
		queue->first = current->next;
		free(current);
	}
}

void  free_queue(t_queue *queue)
{
	t_element *current;
	t_element *next;

	if (!queue)
		exit(EXIT_FAILURE);
	current = queue->first;
	while (current)
	{
		next = current->next;
		free(current->command);
		free(current);
		current = next;
	}
	free(queue);
}
