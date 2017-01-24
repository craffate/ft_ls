/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:47:30 by craffate          #+#    #+#             */
/*   Updated: 2016/11/16 23:21:58 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;

	lst2 = NULL;
	if (lst)
	{
		lst2 = (*f)(lst);
		lst2->next = ft_lstmap(lst->next, (*f));
		return (lst2);
	}
	return (NULL);
}
