/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:29:12 by itahri            #+#    #+#             */
/*   Updated: 2024/06/07 21:25:38 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, const char *argv[], char **envp)
{
	int		  i;
	int		  j;
	char	  **path_tab;
	t_queue	  *queue;
	t_element *current;
	char	  *content;

	queue = args_manag(argv, argc);
	current = queue->first;
	j = 0;
	while (current)
	{
		i = 0;
		while(current->command[i])
		{
			if (i == 0)
				ft_printf("command : %s\n", current->command[i++]);
			else
				ft_printf("arg : %s\n", current->command[i++]);
		}
		if (j % 2 == 0)
			ft_printf("input : %s \n", current->input);
		else 
			ft_printf("output : %s \n", current->input);
		ft_printf("-------------------------------\n");
		current = current->next;
		j++;
	}
	content = infile_content(queue->first->input);
	if (!content)
		return (free_queue(queue), EXIT_FAILURE);
	ft_printf("%s", content);
	free(content);
	free_queue(queue);
	path_tab = get_env_path(envp);	
	//i = 0;
	//while (path_tab[i])
	//	ft_printf("[%s]\n", path_tab[i++]);
	i = 0;
	while (path_tab[i])
		free(path_tab[i++]);
	free(path_tab);
	return (0);
}
