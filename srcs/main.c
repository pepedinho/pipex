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

void  pipe_assignation(t_queue *queue)
{
	t_element *current;

	current = queue->first;
	while (current)
	{
		current->fd = malloc(sizeof(int) * 2);
		if (!current->fd)
			return ;
		if (pipe(current->fd) == -1)
			return ;
		current = current->next;
		
	}
}

int main(int argc, const char *argv[], char **envp)
{
	t_queue	  *queue;
	t_element *current;
	t_element *before;
	pid_t	  pid;
	int		  i;

	queue = args_manag(argv, argc);
	if (!queue)
		return (-1);
	pipe_assignation(queue);
	current = queue->first;
	while (current)
	{
		ft_printf("fd in = %d | fd out = %d\n", current->fd[READ], current->fd[WRITE]);
		current = current->next;
	}
	current = queue->first;
	before = current;
	i = 0;
	while (current && pid > 0)
	{
		pid = fork();
		if (pid == 0 && current->input && i == 0)
		{
			//wait(NULL);
			ft_printf("infile : fd in = %d | fd out = %d\n", current->fd[READ], current->fd[WRITE]);
			current->command_path = get_command_path(envp, current->command[0]);
			if(!current->command_path)
				return(ft_printf("path error 1\n"), -1);
			infile_command(envp, current, current->fd);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0 && !current->input)
		{
			ft_printf("inter : fd in = %d | fd out = %d\n", before->fd[READ], current->fd[WRITE]);
			current->command_path = get_command_path(envp, current->command[0]);
			if(!current->command_path)
				return(ft_printf("path error 2\n"), -1);
			intermediate_command(envp, current, before->fd, current->fd);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0 && current->input && i > 0)
		{
			//char buff[100];
			//read(before->fd[READ], buff, 100);
			//ft_printf("debug outfile pipe : %s \n", buff);
			ft_printf("outfile : fd in = %d\n", before->fd[READ]);
			(close(current->fd[WRITE]), close(current->fd[READ]));
			current->command_path = get_command_path(envp, current->command[0]);
			if(!current->command_path)
				return(ft_printf("path error 3\n"), -1);
			outfile_command(envp, current, before->fd);
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			waitpid(pid, NULL, 0);
			ft_printf("close pid : %d\n", pid);
			close(current->fd[WRITE]);
			ft_printf("closing : fd[%d]\n", current->fd[WRITE]);
			if (i > 0 && current->input)
			{
				close(before->fd[READ]);
				close(current->fd[READ]);
			}
			else if (i > 0)
			{
				close(before->fd[READ]);
				ft_printf("closing cond : fd[%d]\n", before->fd[READ]);
			}
		}
		ft_printf("pid : %d \n", pid);
		before = current;
		current = current->next;
		i++;
	}
	close_all(before);
	return (0);
	/*
	current = queue->first;
	current->fd = fd;
	pid = fork();
	if (pid == 0) //child
	{
		//ft_printf("child debug \n");		
		infile_command(envp, current, fd);
	}
	else //parent
	{
		outfile_command(envp, current->next, fd);
	}
	kill(pid, SIGKILL);
	return (0);
	*/
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
