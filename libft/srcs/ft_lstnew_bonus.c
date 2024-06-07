/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:35:24 by itahri            #+#    #+#             */
/*   Updated: 2024/03/25 17:34:25 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_element;

	n_element = malloc(sizeof(t_list));
	if (!n_element)
		return (NULL);
	n_element->content = content;
	n_element->next = NULL;
	return (n_element);
}
