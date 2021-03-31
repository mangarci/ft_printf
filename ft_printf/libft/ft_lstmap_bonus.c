/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mangarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:50:09 by mangarci          #+#    #+#             */
/*   Updated: 2019/11/21 14:39:56 by mangarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new;
	t_list	*aux;

	if (lst)
	{
		new = ft_lstnew(f(lst->content));
		aux = new;
		while (lst->next)
		{
			lst = lst->next;
			if (!(new->next = ft_lstnew(f(lst->content))))
			{
				del(new->next);
				free(new->next);
				return (NULL);
			}
			new = new->next;
		}
		return (aux);
	}
	return (NULL);
}
