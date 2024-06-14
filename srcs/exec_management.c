/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:32:01 by itahri            #+#    #+#             */
/*   Updated: 2024/06/13 18:56:13 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_tab(char **tab, int cas)
{
	int	i;

	if (cas == 2)
	{
		if (tab)
			free(tab);
		return ;
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*cut_n(const char *command, char sep)
{
	int		i;
	int		j;
	char	*result;

	if (!command)
		return (NULL);
	i = 0;
	while (command[i] && command[i] != sep)
		i++;
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	j = 0;
	while (j < i)
	{
		result[j] = command[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

static char	*extend(char *path, char *command)
{
	int		total_len;
	char	*result;

	total_len = ft_strlen(path) + ft_strlen(command);
	result = ft_calloc(total_len + 2, sizeof(char));
	if (!result)
		return (NULL);
	extend_loop(path, command, result);
	return (result);
}

static char	**path_formater(char **path_tab, char *command)
{
	int		i;
	char	*command_name;
	char	**path_tab_formated;

	i = 0;
	while (path_tab[i])
		i++;
	path_tab_formated = malloc(sizeof(char *) * (i + 1));
	command_name = cut_n(command, ' ');
	if (!path_tab_formated | !command_name)
		return (free_tab(path_tab_formated, 2), NULL);
	i = 0;
	while (path_tab[i])
	{
		path_tab_formated[i] = extend(path_tab[i], command_name);
		if (!path_tab_formated[i])
		{
			while (i >= 0)
				free(path_tab_formated[i--]);
			return (free(command_name), free(path_tab_formated), NULL);
		}
		i++;
	}
	path_tab_formated[i] = NULL;
	return (free(command_name), path_tab_formated);
}

char	*get_command_path(char **envp, char *command)
{
	char	**path_tab;
	char	**path_tab_formated;
	char	*result;
	int		i;

	i = 0;
	path_tab = get_env_path(envp);
	if (!path_tab)
		return (NULL);
	path_tab_formated = path_formater(path_tab, command);
	if (!path_tab_formated)
		return (free_tab(path_tab, 1), NULL);
	while (path_tab_formated[i])
	{
		if (access(path_tab_formated[i], F_OK) == 0)
		{
			result = ft_strdup(path_tab_formated[i]);
			if (!result)
				return (free_tab(path_tab_formated, 1), NULL);
			free_tab(path_tab_formated, 1);
			return (free_tab(path_tab, 1), result);
		}
		i++;
	}
	return (free_tab(path_tab_formated, 1), free_tab(path_tab, 1), NULL);
}
