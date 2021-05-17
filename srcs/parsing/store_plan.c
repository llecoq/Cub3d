/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:00:25 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/14 13:07:38 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	bottom_plan(int y, t_head *head)
{
	t_plan	*bottom;
	t_plan	*temp;

	temp = head->map->bottom;
	while (temp)
	{
		if (-y == temp->d)
			return ;
		temp = temp->next;
	}
	bottom = new_plan(0, 1, -y);
	plan_add_front(&head->map->bottom, bottom);
	asort_plan(head->map->bottom);
}

void	top_plan(int y, t_head *head)
{
	t_plan	*top;
	t_plan	*temp;

	temp = head->map->top;
	while (temp)
	{
		if (- (y + 1) == temp->d)
			return ;
		temp = temp->next;
	}
	top = new_plan(0, 1, - (y + 1));
	plan_add_front(&head->map->top, top);
	sort_plan(head->map->top);
}

void	left_plan(int x, t_head *head)
{
	t_plan	*left;
	t_plan	*temp;

	temp = head->map->left;
	while (temp)
	{
		if (- (x + 1) == temp->d)
			return ;
		temp = temp->next;
	}
	left = new_plan(1, 0, - (x + 1));
	plan_add_front(&head->map->left, left);
	sort_plan(head->map->left);
}

void	right_plan(int x, t_head *head)
{
	t_plan	*right;
	t_plan	*temp;

	temp = head->map->right;
	while (temp)
	{
		if (-x == temp->d)
			return ;
		temp = temp->next;
	}
	right = new_plan(1, 0, -x);
	plan_add_front(&head->map->right, right);
	asort_plan(head->map->right);
}

void	store_plan(int x, int y, char **copy, t_head *head)
{
	if (copy[y][x - 1] == '1' || copy[y][x - 1] == '6' || copy[y][x - 1] == '7')
		right_plan(x, head);
	if (copy[y][x + 1] == '1' || copy[y][x + 1] == '6' || copy[y][x - 1] == '7')
		left_plan(x, head);
	if (copy[y - 1][x] == '1' || copy[y - 1][x] == '6' || copy[y][x - 1] == '7')
		bottom_plan(y, head);
	if (copy[y + 1][x] == '1' || copy[y + 1][x] == '6' || copy[y][x - 1] == '7')
		top_plan(y, head);
}
