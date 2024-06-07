/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:22:25 by itahri            #+#    #+#             */
/*   Updated: 2024/05/25 22:21:18 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	monitoring(va_list args, char *c)
{
	c++;
	if (*c == 'c')
		return (car_fr(args));
	else if (*c == 's')
		return (str_fr(args));
	else if (*c == 'd' || *c == 'i')
		return (int_fr(args));
	else if (*c == 'p')
		return (mem_fr(args));
	else if (*c == 'u')
		return (uns_fr(args));
	else if (*c == 'x')
		return (hex_fr(args, 1));
	else if (*c == 'X')
		return (hex_fr(args, 2));
	else if (*c == '%')
		return (write(1, "%", 1), 1);
	return (0);
}
