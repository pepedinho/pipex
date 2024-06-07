/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-23 02:14:33 by itahri            #+#    #+#             */
/*   Updated: 2024-03-23 02:14:33 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		last_index;
	char	*ptr;
	char	cast_c;

	i = 0;
	last_index = -1;
	ptr = (char *)s;
	cast_c = (char)c;
	while (ptr[i])
	{
		if (ptr[i] == cast_c)
			last_index = i;
		i++;
	}
	if (last_index >= 0)
		return (&ptr[last_index]);
	if (ptr[i] == cast_c)
		return (&ptr[i]);
	return (NULL);
}
