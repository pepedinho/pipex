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

int	infile_command(char **envp, t_element *elem, int *fd)
{
	char  *path;
	int	  infile;
	
	path = get_command_path(envp, elem->command[0]);
	if (!path)
		return (ft_printf("error\n"), -1);
	infile = open(elem->input, O_RDWR);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	(close(fd[0]), close(fd[1]), close(infile));
	//ft_printf("debug child before execve\n");
	execve(path, elem->command, envp);
	//ft_printf("debug child after execve\n");
	return (0);
}

int	intermediate_command(char **envp, t_element *elem, int fd_in, int fd_out)
{
	char  *path;

	path = get_command_path(envp, elem->command[0]);
	if (!path)
		return (ft_printf("error\n"), -1);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	(close(fd_in), close(fd_out));
	wait(NULL);
	if (execve(path, elem->command, envp) == -1)
		return (ft_printf("error during execution\n"), -1);
	return (0);
}

int outfile_command(char **envp, t_element *elem, int *fd)
{
	char  *path;
	int	  outfile;
	
	ft_printf("debug outfile_command : %s | outfile = %s\n", elem->command[0], elem->input);
	path = get_command_path(envp, elem->command[0]);
	if (!path)
		return (ft_printf("error\n"), -1);
	outfile = open(elem->input, O_CREAT | O_WRONLY, 0644);
	if (outfile < 0)
		return (ft_printf("error when open outfile : %s", elem->input), -1);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	(close(fd[1]), close(fd[0]), close(outfile));
	//ft_printf("debug parent before execve\n");
	wait(NULL);
	execve(path, elem->command, envp);
	//ft_printf("debug parent after execve\n");
	return (0);
}
