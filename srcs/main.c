/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:29:12 by itahri            #+#    #+#             */
/*   Updated: 2024/06/14 04:22:32 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, const char *argv[], char **envp)
{
	t_element	*current;
	t_element	*before;
	t_queue		*queue;
	pid_t		pid;
	int			i;

	queue = args_manag(argv, argc);
	if (!queue)
		return (-1);
	pipe_assignement(queue);
	current = queue->first;
	i = 0;
	while (current && pid > 0)
	{
		pid = fork();
		if (pid == 0)
			monitor(current, before, envp, i);
		else if (pid > 0)
			closing_cond(current, before, pid, i);
		before = current;
		current = current->next;
		i++;
	}
	close_all(before);
	return (0);
}

/*
int main(int argc, const char *argv[], char **envp)
{
	int		  j;
	int		  i;
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
		while (current->command[i])
		{
			if (i == 0)
				ft_printf("command : %s\n", current->command[i]);
			else
				ft_printf("arg : %s\n", current->command[i]);
			i++;
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
	path = get_command_path(envp, queue->first->command[0]);
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
*/
