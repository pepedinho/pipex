/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:29:47 by itahri            #+#    #+#             */
/*   Updated: 2024/06/07 18:28:39 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"

typedef struct s_element
{
	char	  *input;
	char	  **command;
	struct s_element *next;
}			  t_element;

typedef struct s_queue
{
	t_element *first;
}			  t_queue;

typedef struct s_index
{
	int	i;
	int	j;
}		t_index;

t_queue	*init_queue(void);
void  put_on_queue(t_queue *queue, const char *input, const char **command);
void  get_out_queue(t_queue *queue);
void  free_queue(t_queue *queue);

//args_env_manahements
char  **get_env_path(char **envp);
t_queue	*args_manag(const char **argv, int argc);

//file_management
int	file_content_len(char *filename);
char *infile_content(char *filename);

//exec_management
char  *get_command_path(char **envp, char **command);

#endif
