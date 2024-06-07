/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:32:14 by itahri            #+#    #+#             */
/*   Updated: 2024/03/23 18:16:27 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		j;
	size_t		temp_i;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			temp_i = i;
			while (haystack[temp_i] == needle[j] && needle[j])
			{
				temp_i++;
				j++;
			}
			if (j == ft_strlen(needle))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
