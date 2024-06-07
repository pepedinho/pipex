/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-22 21:30:18 by itahri            #+#    #+#             */
/*   Updated: 2024-03-22 21:30:18 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*n_src;
	unsigned char	*n_dest;

	n_src = (unsigned char *)src;
	n_dest = (unsigned char *)dest;
	i = 0;
	if (!dest && !src && n != 0)
		return (dest);
	while (i < n)
	{
		n_dest[i] = n_src[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h> 
int main()
{
	long long int res1;
	long long int res2;
	res2 = (long long int)ft_memcpy(((void*)0), ((void*)0), 3);
	res1 = (long long int)memcpy(NULL, NULL, 3);
	printf("%lld\n", res1);
	printf("%lld\n", res2);
}
*/
