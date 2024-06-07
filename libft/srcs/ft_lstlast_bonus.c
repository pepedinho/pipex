/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:11:59 by itahri            #+#    #+#             */
/*   Updated: 2024/03/25 18:12:02 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst_testlast)
{
	if (!lst_testlast)
		return (NULL);
	while (lst_testlast->next)
	{
		lst_testlast = lst_testlast->next;
	}
	return (lst_testlast);
}
