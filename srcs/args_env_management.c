/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_env_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:08:38 by itahri            #+#    #+#             */
/*   Updated: 2024/06/07 20:02:17 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char  **get_env_path(char **envp)
{
	int	  i;
	char  **path_tab;

	i = 0;
	while (envp[i])
	{
		if(ft_strstr(envp[i], "PATH") && envp[i][0] == 'P' && envp[i][3] == 'H')
			break ;
		i++;
	}
	path_tab = ft_split(envp[i], ':');
	if (!path_tab)
		return (NULL);
	return (path_tab);
}

const char **stock_args(const char **argv)
{
	int	i;
	int	j;
	const char **command_and_arg;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
		i++;
	command_and_arg = malloc(sizeof(char *) * (i + 1));
	if (!command_and_arg)
		return (NULL);
	j = 0;
	while (j < i)
	{
		command_and_arg[j] = argv[j];
		j++;
	}
	command_and_arg[j] = NULL;
	return (command_and_arg);
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
	i+=2;
	while(i + 2 < argc)
	{
		arg_plus_command = ft_split(argv[i], ' ');
		if (!arg_plus_command)
			return(NULL);
		put_on_queue(queue, NULL, (const char **)arg_plus_command);
		i++;
	}
	arg_plus_command = ft_split(argv[i], ' ');
	if (!arg_plus_command)
		return (NULL);
	put_on_queue(queue, argv[i + 1], (const char **)arg_plus_command);
	return (queue);
}
