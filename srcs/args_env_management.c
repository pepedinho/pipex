/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_env_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:08:38 by itahri            #+#    #+#             */
/*   Updated: 2024/06/13 18:29:59 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_env_path(char **envp)
{
	int		i;
	char	**path_tab;

	i = 0;
	while (envp[i])
	{
		if (ft_strstr(envp[i], "PATH") && envp[i][0] == 'P'
			&& envp[i][3] == 'H')
			break ;
		i++;
	}
	path_tab = ft_split(envp[i], ':');
	if (!path_tab)
		return (NULL);
	return (path_tab);
}

t_queue	*args_manag(const char **argv, int argc)
{
	int		i;
	t_queue	*queue;
	char	**arg_plus_command;

	i = 1;
	queue = init_queue();
	if (!queue)
		exit(EXIT_FAILURE);
	arg_plus_command = ft_split(argv[i + 1], ' ');
	if (!arg_plus_command)
		return (NULL);
	put_on_queue(queue, argv[i], (const char **)arg_plus_command);
	i += 2;
	while (i + 2 < argc)
	{
		arg_plus_command = ft_split(argv[i], ' ');
		if (!arg_plus_command)
			return (NULL);
		(put_on_queue(queue, NULL, (const char **)arg_plus_command), i++);
	}
	arg_plus_command = ft_split(argv[i], ' ');
	if (!arg_plus_command)
		return (NULL);
	put_on_queue(queue, argv[i + 1], (const char **)arg_plus_command);
	return (queue);
}
