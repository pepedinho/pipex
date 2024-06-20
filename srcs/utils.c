/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:35:54 by itahri            #+#    #+#             */
/*   Updated: 2024/06/13 19:54:55 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	extend_loop(char *path, char *command, char *result)
{
	t_index	indexx;

	indexx.i = 0;
	if (ft_strstr(path, "PATH"))
	{
		while (path[indexx.i + 5])
		{
			result[indexx.i] = path[indexx.i + 5];
			indexx.i++;
		}
	}
	else
	{
		while (path[indexx.i])
		{
			result[indexx.i] = path[indexx.i];
			indexx.i++;
		}
	}
	result[indexx.i++] = '/';
	indexx.j = 0;
	while (command[indexx.j])
		result[indexx.i++] = command[indexx.j++];
	result[indexx.i] = '\0';
}

void	pipe_assignation(t_queue *queue)
{
	t_element	*current;

	current = queue->first;
	while (current)
	{
		current->fd = malloc(sizeof(int) * 2);
		if (!current->fd)
		{
			current = current->first;
			while (current && current->fd)
				free(current->fd);
			exit(EXIT_FAILURE);
		}
		if (pipe(current->fd) == -1)
		{
			current = current->first;
			while (current && current->fd)
				free(current->fd);
			exit(EXIT_FAILURE);
		}
		current = current->next;
	}
}
