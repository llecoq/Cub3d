/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:36:41 by llecoq            #+#    #+#             */
/*   Updated: 2021/03/03 14:50:16 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*), int free_content)
{
	t_list	*next_elem;

	if (!lst)
		return ;
	while (*lst)
	{
		next_elem = (*lst)->next;
		ft_lstdelone(*lst, del, free_content);
		*lst = next_elem;
	}
	*lst = NULL;
}
