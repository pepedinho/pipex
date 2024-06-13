/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:47:19 by itahri            #+#    #+#             */
/*   Updated: 2024/06/09 16:02:07 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <fcntl.h>

void  close_all(t_element *elem)
{
	t_element *current;

	current = elem->first;
	while (current)
	{
		if (current->fd)
		{
			close(current->fd[READ]);
			close(current->fd[WRITE]);
		}
		current = current->next;
	}
}

int	infile_command(char **envp, t_element *elem, int *fd)
{
	//char  *path;
	int	  infile;
	
	//path = get_command_path(envp, elem->command[0]);
	//if (!path)
	//	return (ft_printf("error\n"), -1);
	infile = open(elem->input, O_RDWR);
	dup2(infile, STDIN_FILENO);
	dup2(fd[WRITE], STDOUT_FILENO);
	(close_all(elem), close(infile));
	//(close(fd[READ]), close(fd[WRITE]), close(infile));
	//ft_printf("debug child before execve\n");
	execve(elem->command_path, elem->command, envp);
	//ft_printf("debug child after execve\n");
	return (0);
}

int	intermediate_command(char **envp, t_element *elem, int *bef_fd, int *cur_fd)
{
	//char  *path;

	//path = get_command_path(envp, elem->command[0]);
	//if (!path)
	//	return (ft_printf("error\n"), -1);
	/*char buff[100];
	read(bef_fd[READ], buff, 100);
	ft_printf("debug pipe fd [%d]: %s \n", bef_fd[READ], buff);*/
	dup2(bef_fd[READ], STDIN_FILENO);
	dup2(cur_fd[WRITE], STDOUT_FILENO);
	close_all(elem);
	if (execve(elem->command_path, elem->command, envp) == -1)
		return (ft_printf("error during execution\n"), -1);
	return (0);
}

int outfile_command(char **envp, t_element *elem, int *fd)
{
	//char  *path;
	int	  outfile;

	ft_printf("YIUHOU0\n");
	ft_printf("%s\n", elem->command_path);
	//path = get_command_path(envp, elem->command[0]);
	//if (!path)
	//	return (ft_printf("error\n"), -1);
	ft_printf("YIUHOU1\n");
	outfile = open(elem->input, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		return (ft_printf("error when open outfile : %s", elem->input), -1);
	ft_printf("YIUHOU2\n");
	dup2(fd[READ], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	(close(outfile), close_all(elem), close(fd[READ]));
	//ft_printf("debug parent before execve\n");
	execve(elem->command_path, elem->command, envp);
	//ft_printf("debug parent after execve\n");
	return (0);
}
