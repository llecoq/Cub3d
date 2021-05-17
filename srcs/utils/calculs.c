/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:03:12 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 09:33:23 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec	player_rotation(t_head *head, t_vec vec)
{
	t_vec	new_vec;
	double	x;
	double	y;

	x = vec.x;
	y = vec.y;
	new_vec.x = x * cos(head->player_dir) - y * sin(head->player_dir);
	new_vec.y = x * sin(head->player_dir) + y * cos(head->player_dir);
	return (new_vec);
}

double	plan_equation(t_head *head, t_plan *p)
{
	double	plan;
	double	pos_x;
	double	pos_y;

	pos_x = head->map->player_x;
	pos_y = head->map->player_y;
	plan = - (pos_x * p->a + pos_y * p->b + p->d);
	return (plan);
}

double	vector_equation(t_vec *vec, t_plan *p)
{
	double	vector;

	vector = p->a * vec->x + p->b * vec->y;
	return (vector);
}

double	plan_equation_sprite(t_head *head, t_sprite *p)
{
	double	plan;
	double	pos_x;
	double	pos_y;

	pos_x = head->map->player_x;
	pos_y = head->map->player_y;
	plan = - (pos_x * p->a + pos_y * p->b + p->d);
	return (plan);
}

double	vector_equation_sprite(t_vec *vec, t_sprite *p)
{
	double	vector;

	vector = p->a * vec->x + p->b * vec->y;
	return (vector);
}
