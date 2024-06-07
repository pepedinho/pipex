/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-23 01:59:02 by itahri            #+#    #+#             */
/*   Updated: 2024-03-23 01:59:02 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	char	cast_c;

	i = 0;
	cast_c = (char)c;
	ptr = (char *)s;
	while (ptr[i])
	{
		if (ptr[i] == cast_c)
			return (&ptr[i]);
		i++;
	}
	if (ptr[i] == cast_c)
		return (&ptr[i]);
	return (NULL);
}
