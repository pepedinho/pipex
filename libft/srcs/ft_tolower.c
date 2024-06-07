/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-23 01:55:47 by itahri            #+#    #+#             */
/*   Updated: 2024/06/07 17:37:32 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	t_c;

	if (c == -1)
		return (c);
	t_c = (unsigned char)c;
	if (ft_isalpha(t_c))
	{
		if (t_c >= 'A' && t_c <= 'Z')
			return (t_c + 32);
	}
	return (t_c);
}
