/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:26:00 by itahri            #+#    #+#             */
/*   Updated: 2024/05/24 13:27:13 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char*s2, size_t n)
{
	size_t			i;
	unsigned char	*casted_s1;
	unsigned char	*casted_s2;

	casted_s1 = (unsigned char *)s1;
	casted_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (casted_s1[i] || casted_s2[i]))
	{
		if (casted_s1[i] != casted_s2[i])
			return (casted_s1[i] - casted_s2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	printf("me       : %d\n", ft_strncmp("abcdef", "abc\375xx", 5));
	printf("original : %d\n", strncmp("abcdef", "abc\375xx", 5));
}
*/
