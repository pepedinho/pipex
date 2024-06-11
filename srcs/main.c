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

int main(int argc, const char *argv[], char **envp)
{
	t_queue	  *queue;
	t_element *current;
	pid_t	  pid;
	t_element *before;
	int		  i;
	int		  last_pid;

	queue = args_manag(argv, argc);
	if (!queue)
		return (-1);
	i = 0;
	current = queue->first;
	current->fd = malloc(sizeof(int) * 2);
	if (!current->fd)
		exit(EXIT_FAILURE);
	pipe(current->fd);
	before = current;
	ft_printf("[0] fd[0] = %d | fd [1] = %d\n", current->fd[0], current->fd[1]);
	pid = fork();
	if (pid == 0)
		infile_command(envp, current, current->fd);
	current = current->next;
	while (current && pid != 0)
	{
		last_pid = pid;
		pid = fork();
		wait(NULL);
		//ft_printf("\n[1]debug while \n\tpid : %d\n\ti : %d\n\t current command : %s\n\t current input : %s\n", pid, i + 1, current->command[0], current->input);
		///ft_printf("[1.1]debug condition\n\t argc : %d\n\t current : %s\n", argc, current->next ? "true" : "false");
		if (pid == 0)
			break ;
		ft_printf("pid :  %d current -> %s\n", pid, current->command[0]);
		ft_printf("command : %s\n", current->command[0]);
		before = current;
		ft_printf("command : %s\n", current->command[0]);
		current = current->next;
		if (current)
			ft_printf("command : %s\n", current->command[0]);
		if (current)
			ft_printf("pid :  %d | current -> %s\n", pid, current->command[0]);
		i++;
	}
	if (pid == 0)
	{
		//ft_printf("[2]debug condition pid = %d i = %d command = %s\n", pid, i, current->command[0]);
		if (argc >= 5)
		{
			wait(NULL);
			current->fd = malloc(sizeof(int) * 2);
			if (!current)
				return (-1);
			if (pipe(current->fd) == -1)
			{
				wait(NULL);
				ft_printf("ERROR PIPE\n");
			}
			ft_printf("[3]debug pipe command = %s |fd[0] = %d|fd[1] = %d | i = %d\n", current->command[0], current->fd[0], current->fd[1], i);
		}
		wait(NULL);
		//ft_printf("[bef 4]pid = %d | current->input = %s | i = %d\n", pid, current->input ? "true" : "false", i);
		if (!current->input)
		{
			wait(NULL);
			ft_printf("debug current input :  %s | next input : %s\n", current->input, current->next->input);
			ft_printf("[4]debuf no input command = %s\n", current->command[0]);
			ft_printf("\t|before fd[0] = %d| current fd[1] = %d\n", before->fd[0], current->fd[1]);
			(close(current->fd[1]), close(before->fd[0]));
			intermediate_command(envp, current, before->fd[1], current->fd[0]);
			exit (EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			//ft_printf("[5]debug ELSE\n");
			if (current->input)
			{
				wait(NULL);
				ft_printf("[bef outfile] fd[0] = %d | fd[1] = %d\n", current->fd[0], current->fd[1]);
				outfile_command(envp, current, current->fd);
				exit(EXIT_FAILURE);
			}
		}
	}
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
