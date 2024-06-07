/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-22 23:39:07 by itahri            #+#    #+#             */
/*   Updated: 2024/05/20 23:22:26 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	is_min(size_t size, size_t len)
{
	if (size <= len)
		return (size);
	return (len);
}

size_t	min(size_t size, size_t dest_len)
{
	if (size < dest_len)
		return (size);
	else
		return (dest_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (dst[i])
		i++;
	len = i;
	j = 0;
	if (size <= ft_strlen(src))
	{
		if (is_min(size, len) == size)
			return (size + ft_strlen(src));
		while (src[j] && i < size - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
		return (min(size, len) + ft_strlen(src));
	}
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ft_strlen(src) + min(size, len));
}
