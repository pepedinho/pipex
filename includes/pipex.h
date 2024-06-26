/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:29:47 by itahri            #+#    #+#             */
/*   Updated: 2024/06/13 19:53:16 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ 0
# define WRITE 1
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"

typedef struct s_element
{
	char				*input;
	char				**command;
	int					*fd;
	char				*command_path;
	struct s_element	*first;
	struct s_element	*next;
}						t_element;

typedef struct s_queue
{
	t_element	*first;
}				t_queue;

typedef struct s_index
{
	int	i;
	int	j;
}		t_index;

t_queue	*init_queue(void);
void	put_on_queue(t_queue *queue, const char *input, const char **command);
void	get_out_queue(t_queue *queue);
void	free_queue(t_queue *queue);

//args_env_manahements
char	**get_env_path(char **envp);
t_queue	*args_manag(const char **argv, int argc);

//exec_management
char	*get_command_path(char **envp, char *command);

//execution_funcs
int		infile_command(char **envp, t_element *elem, int *fd);
int		outfile_command(char **envp, t_element *elem, int *fd);
int		inter_command(char **envp, t_element *elem, int *bef_fd, int *cur_fd);
void	close_all(t_element *elem);

//utils
void	extend_loop(char *path, char *command, char *result);
void	pipe_assignation(t_queue *queue);

//pipex
void	infile(t_element *current, char **envp);
void	inter(t_element *current, t_element *before, char **envp);
void	outfile(t_element *current, t_element *before, char **envp);
void	closing_cond(t_element *current, t_element *before, int i);
void	monitor(t_element *current, t_element *before, char **envp, int i);

#endif
