/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_env_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:08:38 by itahri            #+#    #+#             */
/*   Updated: 2024/06/07 20:03:29 by itahri           ###   ########.fr       */
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
		if(ft_strstr(envp[i], "PATH"))
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
	int		argv_count;
	const char	**command_plus_arg;

	i = 1;
	argv_count = 0;
	queue = init_queue();
	if (!queue)
		exit(EXIT_FAILURE);
	while (argv[argv_count])
		argv_count++;
	argv_count--;
	if (argv_count % 2 != 0)
		exit(EXIT_FAILURE);
	while(i < argc)
	{
		command_plus_arg = stock_args(&argv[i + 1]);
		put_on_queue(queue, argv[i], command_plus_arg);
		while (i + 2 < argc && argv[i + 2][0] ==  '-')
			i++;
		i+=2;
	}
	return (queue);
}
