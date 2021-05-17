/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:12:12 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/13 18:36:48 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_sprite	**sprite_tab(t_sprite *sprite, int i, t_head *head)
{
	t_sprite	**tab;
	int			j;

	j = 0;
	tab = calloc(i + 1, sizeof(t_sprite *));
	if (!tab)
		if (ft_clear_memory(head))
			exit (0);
	while (sprite)
	{
		tab[j] = sprite;
		sprite = sprite->next;
		j++;
	}
	return (tab);
}

t_sprite	*ft_lstlast_sprite(t_sprite *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_sprite(t_sprite **alst, t_sprite *new)
{
	t_sprite	*last_elem;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last_elem = ft_lstlast_sprite(*alst);
	new->previous = last_elem;
	last_elem->next = new;
}

t_sprite	*ft_lstnew_sprite(double x, double y, int n)
{
	t_sprite	*new_elem;

	new_elem = malloc(sizeof(t_sprite));
	if (!new_elem)
		return (NULL);
	new_elem->x = x;
	new_elem->y = y;
	new_elem->a = 0.0;
	new_elem->b = 0.0;
	new_elem->d = 0.0;
	new_elem->next = 0;
	new_elem->previous = 0;
	if (n == '2')
		new_elem->sprite = 2;
	else if (n == '3')
		new_elem->sprite = 3;
	else if (n == '4')
		new_elem->sprite = 4;
	else if (n == '5')
		new_elem->sprite = 5;
	return (new_elem);
}

void	store_sprite(t_head *head, t_sprite *sprite)
{
	t_sprite	*temp;
	int			y;
	int			x;

	y = 0;
	while (++y < head->map->max_y)
	{
		x = head->map->min_x;
		while (++x < head->map->max_x && head->map->map[y][x])
		{
			if (inter(head->map->map[y][x], "2345")
				&& (ft_strncmp(&head->map->map[y][x], "2", 1) == 0
					|| ft_strncmp(&head->map->map[y][x], "3", 1) == 0
					|| ft_strncmp(&head->map->map[y][x], "4", 1) == 0
					|| ft_strncmp(&head->map->map[y][x], "5", 1) == 0))
			{
				temp = ft_lstnew_sprite(x + 0.5, y + 0.5, head->map->map[y][x]);
				ft_lstadd_back_sprite(&sprite, temp);
				head->i++;
			}
		}
	}
	head->map->sprite = sprite;
	head->sprite_tab = sprite_tab(sprite, head->i, head);
	head->sprite = copy_sprite_tab(head, head->sprite_tab, head->i);
}
