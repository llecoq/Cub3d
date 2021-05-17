/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:06:59 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/11 18:15:09 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clear_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (-1);
}

void	ft_lstclear_sprite(t_sprite *sprite)
{
	t_sprite	*next_elem;

	if (!sprite)
		return ;
	while (sprite)
	{
		next_elem = (sprite)->next;
		free(sprite);
		sprite = next_elem;
	}
	sprite = NULL;
}

void	ft_lstclear_plan(t_plan *plan)
{
	t_plan	*next_elem;

	if (!plan)
		return ;
	while (plan)
	{
		next_elem = (plan)->next;
		free(plan);
		plan = next_elem;
	}
	plan = NULL;
}

void	clear_plan(t_plan **plan, int i)
{
	while (--i >= 0)
		if (plan[i])
			free (plan[i]);
	free(plan);
}

void	clear_tab_plan(t_head *head)
{
	int	i;

	if (head->map->tab_bottom)
	{
		i = head->max_y + 1;
		clear_plan(head->map->tab_bottom, i);
	}
	if (head->map->tab_top)
	{
		i = head->max_y + 2;
		clear_plan(head->map->tab_top, i);
	}
	if (head->map->tab_right)
	{
		i = head->max_x + 1;
		clear_plan(head->map->tab_right, i);
	}
	if (head->map->tab_left)
	{
		i = head->max_x + 2;
		clear_plan(head->map->tab_left, i);
	}
}
