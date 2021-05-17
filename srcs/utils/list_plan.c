/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 08:43:47 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/13 18:40:45 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	plan_skybox(t_head *head)
{
	t_plan	*plan;

	if (!ft_calloc_plan(&head->map->skybox, 4, sizeof(t_plan *)))
		return ;
	plan = new_plan(0.0, 1.0, 1000.0);
	head->map->skybox[0] = plan;
	plan = new_plan(1.0, 0.0, -1000.0);
	head->map->skybox[1] = plan;
	plan = new_plan(0.0, 1.0, -1000.0);
	head->map->skybox[2] = plan;
	plan = new_plan(1.0, 0.0, 1000.0);
	head->map->skybox[3] = plan;
}

void	lst_to_tab_plan(t_head *head)
{
	while (head->map->top)
	{
		head->map->tab_top[(int) - head->map->top->d] = head->map->top;
		head->map->top = head->map->top->next;
	}
	while (head->map->bottom)
	{
		head->map->tab_bottom[(int) - head->map->bottom->d] = head->map->bottom;
		head->map->bottom = head->map->bottom->next;
	}
	while (head->map->right)
	{
		head->map->tab_right[(int) - head->map->right->d] = head->map->right;
		head->map->right = head->map->right->next;
	}
	while (head->map->left)
	{
		head->map->tab_left[(int) - head->map->left->d] = head->map->left;
		head->map->left = head->map->left->next;
	}
}

void	store_plan_tab(t_head *head, int y, int x)
{
	if (!ft_calloc_plan(&head->map->tab_bottom, y, sizeof(t_plan *)))
		return ;
	if (!ft_calloc_plan(&head->map->tab_top, y + 1, sizeof(t_plan *)))
		return ;
	if (!ft_calloc_plan(&head->map->tab_right, x, sizeof(t_plan *)))
		return ;
	if (!ft_calloc_plan(&head->map->tab_left, x + 1, sizeof(t_plan *)))
		return ;
	plan_skybox(head);
	lst_to_tab_plan(head);
}

void	plan_add_front(t_plan **alst, t_plan *new)
{
	t_plan	*temp;

	temp = *alst;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	if (!new)
		return ;
	new->next = *alst;
	*alst = new;
	new->next->previous = new;
}

t_plan	*new_plan(double a, double b, double d)
{
	t_plan	*new_elem;

	new_elem = malloc(sizeof(t_plan));
	if (!new_elem)
		return (NULL);
	new_elem->a = a;
	new_elem->b = b;
	new_elem->c = '0';
	new_elem->d = d;
	new_elem->next = 0;
	new_elem->previous = 0;
	return (new_elem);
}
