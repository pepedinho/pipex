/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_fr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:27:41 by itahri            #+#    #+#             */
/*   Updated: 2024/05/25 22:21:53 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uns_fr(va_list args)
{
	unsigned int	arg;

	arg = va_arg(args, unsigned int);
	ft_putnbr_base(arg, "0123456789");
	return (convert_len(arg, "0123456789"));
}
