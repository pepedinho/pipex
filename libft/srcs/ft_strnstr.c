/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:26:28 by itahri            #+#    #+#             */
/*   Updated: 2024/05/20 13:26:30 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		temp_i;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			temp_i = i;
			while (haystack[temp_i] == needle[j] && needle[j] && temp_i < len)
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

/*
#include <stdio.h>
#include <bsd/string.h>
int main(void)
{
	char  haystack[30] = "aaabcabcdje test";
	printf("return : %s\n", ft_strnstr(haystack, "cd", 8));
	printf("return : %s\n", strnstr(haystack, "cd", 8));
}
*/
