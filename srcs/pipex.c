/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:47:45 by itahri            #+#    #+#             */
/*   Updated: 2024/06/13 19:53:25 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	infile(t_element *current, char **envp)
{
	current->command_path = get_command_path(envp, current->command[0]);
	if (!current->command_path)
		exit(EXIT_FAILURE);
	infile_command(envp, current, current->fd);
	exit(EXIT_FAILURE);
}

void	inter(t_element *current, t_element *before, char **envp)
{
	current->command_path = get_command_path(envp, current->command[0]);
	if (!current->command_path)
		exit(EXIT_FAILURE);
	inter_command(envp, current, before->fd, current->fd);
	exit(EXIT_FAILURE);
}

void	outfile(t_element *current, t_element *before, char **envp)
{
	(close(current->fd[WRITE]), close(current->fd[READ]));
	current->command_path = get_command_path(envp, current->command[0]);
	if (!current->command_path)
		exit(EXIT_FAILURE);
	outfile_command(envp, current, before->fd);
	exit(EXIT_FAILURE);
}

void	closing_cond(t_element *current, t_element *before, pid_t pid, int i)
{
	waitpid(pid, NULL, 0);
	close(current->fd[WRITE]);
	if (i > 0 && current->input)
	{
		close(before->fd[READ]);
		close(current->fd[READ]);
	}
	else if (i > 0)
		close(before->fd[READ]);
}

void	monitor(t_element *current, t_element *before, char **envp, int i)
{
	if (current->input && i == 0)
		infile(current, envp);
	else if (!current->input)
		inter(current, before, envp);
	else if (current->input && i > 0)
		outfile(current, before, envp);
}
