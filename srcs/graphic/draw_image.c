/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:01:59 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 15:10:52 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_top(t_threads *p, int y, int i)
{
	int		*data;
	int		width;

	p->whole = (int)p->x;
	p->ratio = p->width * (p->x - p->whole);
	data = p->head->data;
	width = p->head->width_top_data;
	p->height_text = p->head->height_top;
	if (p->find_door)
		width = data_door(p);
	draw_bottom_wall(p, y, i, width);
	draw_floor(p, i, data);
	draw_top_wall(p, y, i, width);
	draw_ceiling(p, i, data);
}

void	draw_right(t_threads *p, int y, int i)
{
	int		*data;
	int		width;

	p->whole = (int)p->p;
	p->ratio = p->width * (p->p - p->whole);
	width = p->head->width_right_data;
	data = p->head->data;
	p->height_text = p->head->height_right;
	if (p->find_door)
		width = data_door(p);
	draw_bottom_wall(p, y, i, width);
	draw_floor(p, i, data);
	draw_top_wall(p, y, i, width);
	draw_ceiling(p, i, data);
}

void	draw_bottom(t_threads *p, int y, int i)
{
	int		*data;
	int		width;

	p->whole = (int)p->x;
	p->ratio = p->width * (p->x - p->whole);
	data = p->head->data;
	width = p->head->width_bottom_data;
	p->height_text = p->head->height_bottom;
	if (p->find_door)
		width = data_door(p);
	draw_bottom_wall(p, y, i, width);
	draw_floor(p, i, data);
	draw_top_wall(p, y, i, width);
	draw_ceiling(p, i, data);
}

void	draw_left(t_threads *p, int y, int i)
{
	int		*data;
	int		width;

	p->whole = (int)p->p;
	p->ratio = p->width * (p->p - p->whole);
	data = p->head->data;
	width = p->head->width_left_data;
	p->height_text = p->head->height_left;
	if (p->find_door)
		width = data_door(p);
	draw_bottom_wall(p, y, i, width);
	draw_floor(p, i, data);
	draw_top_wall(p, y, i, width);
	draw_ceiling(p, i, data);
}

void	draw_image(t_threads *p, int i)
{
	int	horizon;
	int	y;

	horizon = p->head->horizon;
	p->horizon = p->head->horizon;
	p->height = (RATIO / p->t) * p->head->cam_dist;
	y = p->height * 0.5 ;
	if (p->plan == 1)
		if (data(p, p->head->data_top, p->head->height_top))
			draw_top(p, y, i);
	if (p->plan == 2)
		if (data(p, p->head->data_right, p->head->height_right))
			draw_right(p, y, i);
	if (p->plan == 3)
		if (data(p, p->head->data_bottom, p->head->height_bottom))
			draw_bottom(p, y, i);
	if (p->plan == 4)
		if (data(p, p->head->data_left, p->head->height_left))
			draw_left(p, y, i);
	draw_sprite(p, p->sprite, horizon, i);
}
