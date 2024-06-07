/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:35:38 by itahri            #+#    #+#             */
/*   Updated: 2024/06/07 21:15:28 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	file_content_len(char *filename)
{
	int	  fd;
	int	  count;
	int	  nb_read;
	char  buff[100];

	fd = open(filename, O_RDONLY);
	nb_read = -1;
	count = 0;
	while (nb_read != 0)
	{
		nb_read = read(fd, buff, 100);
		if (nb_read < 0)
			return (close(fd), -1);
		count += nb_read;
	}
	close(fd);
	return (count);
}

char *infile_content(char *filename)
{
	int		  fd;
	int		  nb_read;
	char	  buff[100];
	char	  *result;
	t_index	  index;

	fd = open(filename, O_RDONLY);
	result = ft_calloc(sizeof(char), (file_content_len(filename) + 1));
	if (!result)
		return (NULL);
	index.i = 0;
	nb_read = -1;
	while (nb_read != 0)
	{
		nb_read = read(fd, buff, 100);
		if (nb_read < 0)
			return (close(fd), NULL);
		index.j = 0;
		while (index.j < nb_read)
		{
			result[index.i] = buff[index.j];
			index.j++;
			index.i++;
		}
	}
	return (result[index.i] = '\0', close(fd), result);
}
