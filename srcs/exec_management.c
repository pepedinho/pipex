/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:32:01 by itahri            #+#    #+#             */
/*   Updated: 2024/06/07 23:20:35 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <unistd.h>

static char  *extend(char *path, char *command)
{
	t_index	indexx;
	int		total_len;
	char	*result;

	total_len = ft_strlen(path) + ft_strlen(command);
	result = ft_calloc(total_len + 2, sizeof(char));
	if (!result)
		return (NULL);
	indexx.i = 0;
	if (ft_strstr(path, "PATH"))
	{
		while (path[indexx.i + 5])
		{
			result[indexx.i] = path[indexx.i + 5];
			indexx.i++;
		}
	}
	else
	{
		while (path[indexx.i])
		{
			result[indexx.i] = path[indexx.i];
			indexx.i++;
		}	
	}
	result[indexx.i++] = '/';
	indexx.j = 0;
	while (command[indexx.j])
	{
		result[indexx.i++] = command[indexx.j];
		indexx.j++;
	}
	return (result[indexx.i] = '\0', result);
}

static char	**path_formater(char **path_tab, char *command)
{
	int	  i;
	int	  j;
	char  **path_tab_formated;

	i = 0;
	while (path_tab[i])
		i++;
	path_tab_formated = malloc(sizeof(char *) * (i + 1));
	if (!path_tab_formated)
		return (NULL);
	i = 0;
	while (path_tab[i])
	{
		path_tab_formated[i] = extend(path_tab[i], command);
		if (!path_tab_formated[i])
		{
			j = 0;
			while (j <= i)
				free(path_tab_formated[j++]);
			return (free(path_tab_formated), NULL);
		}
		i++;
	}
	path_tab_formated[i] = NULL;
	return (path_tab_formated);
}

void  free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char  *get_command_path(char **envp, char **command)
{
	char  **path_tab;
	char  **path_tab_formated;
	char  *result;
	int	  i;

	i = 0;
	path_tab = get_env_path(envp);
	if (!path_tab)
		return (NULL);
	path_tab_formated = path_formater(path_tab, command[0]);
	if (!path_tab_formated)
		return (free_tab(path_tab), NULL);
	//debug
	while (path_tab_formated[i])
	{
		ft_printf("debug pathe %d : %s\n", i, path_tab_formated[i]);
		i++;
	}
	i = 0;
	while (path_tab_formated[i])
	{
		if (access(path_tab_formated[i], F_OK) == 0)
		{
			result = ft_strdup(path_tab_formated[i]);
			if (!result)
				return (free_tab(path_tab_formated), NULL);
			return (free_tab(path_tab_formated), free_tab(path_tab), result);
		}
		i++;
	}
	return (free_tab(path_tab_formated), free_tab(path_tab), NULL);
}
