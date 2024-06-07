/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:00:45 by itahri            #+#    #+#             */
/*   Updated: 2024/03/25 18:06:59 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_elem;

	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	last_elem = ft_lstlast(*lst);
	last_elem->next = new;
}

/*
int main(void)
{
	t_list	*lst1 = NULL;
	t_list	*lst2 = NULL;

	ft_lstadd_back(&lst1, ft_lstnew((void*)1));
	ft_lstadd_back(&lst2, ft_lstnew((void*)2));
    ft_lstadd_back(&lst2, ft_lstnew((void*)3));
    ft_lstadd_back(&lst1, lst2);

	while (lst1) {
		printf("%lld\n", (long long int)lst1->content);
		lst1 = lst1->next;
	}
}
*/
