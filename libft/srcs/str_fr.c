/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_fr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:44:32 by itahri            #+#    #+#             */
/*   Updated: 2024/05/25 22:20:42 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	str_fr(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}
