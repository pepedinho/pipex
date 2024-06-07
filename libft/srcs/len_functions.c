/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:51:41 by itahri            #+#    #+#             */
/*   Updated: 2024/05/30 13:25:51 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_len(long long int nbr, char *base)
{
	int	i;
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		i++;
	while (nbr != 0)
	{
		nbr /= base_len;
		i++;
	}
	return (i);
}

int	dec_len(unsigned int nbr)
{
	int				len;
	unsigned int	temp;

	temp = nbr;
	len = 0;
	while (temp != 0)
	{
		temp = temp / 10;
		len++;
	}
	return (len);
}