/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-23 20:24:42 by itahri            #+#    #+#             */
/*   Updated: 2024-03-23 20:24:42 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*result;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		size = 1;
	else if (len >= ft_strlen(s) && start <= ft_strlen(s))
		size = ft_strlen(&s[start]) + 1;
	else if (start + len > ft_strlen(s))
		size = (len + start) - (start);
	else
		size = len + 1;
	result = malloc(sizeof(char) * size);
	if (!result)
		return (NULL);
	i = start;
	j = 0;
	while (start < ft_strlen(s) && s[i] && j < len)
		result[j++] = s[i++];
	result[j] = '\0';
	return (result);
}
