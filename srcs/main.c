/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:29:12 by itahri            #+#    #+#             */
/*   Updated: 2024/06/07 22:43:01 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <unistd.h>

int main(int argc, const char *argv[], char **envp)
{
	int		  i;
	int		  j;
	char	  *path;
	t_queue	  *queue;
	t_element *current;
	char	  *content;

	queue = args_manag(argv, argc);
	current = queue->first;
	j = 0;
	while (current)
	{
		i = 0;
		while(current->command[i])
		{
			if (i == 0)
				ft_printf("command : %s\n", current->command[i++]);
			else
				ft_printf("arg : %s\n", current->command[i++]);
		}
		if (j % 2 == 0)
			ft_printf("input : %s \n", current->input);
		else 
			ft_printf("output : %s \n", current->input);
		ft_printf("-------------------------------\n");
		current = current->next;
		j++;
	}
	content = infile_content(queue->first->input);
	if (!content)
		return (free_queue(queue), EXIT_FAILURE);
	ft_printf("%s", content);
	free(content);
	path = get_command_path(envp, queue->first->command);
	if (path)
	{
		ft_printf("path find : %s\n", path);
		free(path);
	}
	else
		ft_printf("aucun path find");
	free_queue(queue);

	//i = 0;
	//while (path_tab[i])
	//	ft_printf("[%s]\n", path_tab[i++]);
	return (0);
}
