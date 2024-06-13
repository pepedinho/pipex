/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:47:19 by itahri            #+#    #+#             */
/*   Updated: 2024/06/13 19:54:50 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_all(t_element *elem)
{
	t_element	*current;

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
	int	infile;

	infile = open(elem->input, O_RDWR);
	dup2(infile, STDIN_FILENO);
	dup2(fd[WRITE], STDOUT_FILENO);
	(close_all(elem), close(infile));
	execve(elem->command_path, elem->command, envp);
	return (0);
}

int	inter_command(char **envp, t_element *elem, int *bef_fd, int *cur_fd)
{
	dup2(bef_fd[READ], STDIN_FILENO);
	dup2(cur_fd[WRITE], STDOUT_FILENO);
	close_all(elem);
	if (execve(elem->command_path, elem->command, envp) == -1)
		return (ft_printf("error during execution\n"), -1);
	return (0);
}

int	outfile_command(char **envp, t_element *elem, int *fd)
{
	int	outfile;

	outfile = open(elem->input, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		return (ft_printf("error when open outfile : %s", elem->input), -1);
	dup2(fd[READ], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	(close(outfile), close_all(elem), close(fd[READ]));
	execve(elem->command_path, elem->command, envp);
	return (0);
}
