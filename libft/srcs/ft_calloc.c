/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:21:20 by itahri            #+#    #+#             */
/*   Updated: 2024/03/23 18:58:02 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	char	*ptr;
	size_t	i;

	if (((long int)nmeb * (long int)size) < 0)
		return (NULL);
	else if (nmeb >= U_INT_MAX || size >= U_INT_MAX)
		return (NULL);
	ptr = malloc(size * nmeb);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < nmeb * size)
		ptr[i++] = '\0';
	return ((void *)ptr);
}
