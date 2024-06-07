/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_fr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:30:22 by itahri            #+#    #+#             */
/*   Updated: 2024/05/25 22:26:44 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_fr(va_list args, int cas)
{
	unsigned int	arg;

	arg = va_arg(args, unsigned int);
	if (cas == 1)
		ft_putnbr_base(arg, "0123456789abcdef");
	else
		ft_putnbr_base(arg, "0123456789ABCDEF");
	return (convert_len(arg, "0123456789abcdef"));
}
