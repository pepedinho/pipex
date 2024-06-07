/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-23 22:56:10 by itahri            #+#    #+#             */
/*   Updated: 2024-03-23 22:56:10 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_in_set(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	malloc_size(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s1);
	if (!len)
		return (1);
	i = 0;
	j = 0;
	while (is_in_set(set, s1[i]))
		i++;
	if (s1[i] && !is_in_set(set, s1[i]))
	{
		while (is_in_set(set, s1[len - (j + 1)]))
			j++;
	}
	return (len - (i + j) + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*result;

	result = malloc(sizeof(char) * malloc_size(s1, set));
	if (!result)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	while (is_in_set(set, s1[i]))
		i++;
	while (is_in_set(set, s1[j]))
		j--;
	while (i < j + 1 && s1[i])
	{
		result[k] = s1[i];
		i++;
		k++;
	}
	result[k] = '\0';
	return (result);
}
/*
int main()
{
	char *s1 = ft_strtrim("   xxx   xxx", " x");

	printf("result: |%s\n", s1);
}
*/
