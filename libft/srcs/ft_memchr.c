/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:09:39 by itahri            #+#    #+#             */
/*   Updated: 2024/03/23 16:57:31 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*n_s;

	n_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (n_s[i] == (unsigned char)c)
			return (&n_s[i]);
		i++;
	}
	return (NULL);
}
