/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:21:41 by itahri            #+#    #+#             */
/*   Updated: 2024/03/24 16:24:46 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_size(int nb)
{
	size_t	count;

	count = 1;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	if (nb >= 10)
		count += nb_size(nb / 10);
	return (count);
}

char	*ft_itoa(int n)
{
	size_t			i;
	size_t			j;
	size_t			nb_len;
	unsigned int	nbr;
	char			*result;

	nb_len = nb_size(n);
	result = ft_calloc(sizeof(char), nb_len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		nbr = (unsigned int)(-n);
		result[i++] = '-';
	}
	else
		nbr = n;
	j = nb_len - 1;
	while (i++ < nb_len)
	{
		result[j--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (result);
}
