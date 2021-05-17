/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 09:39:07 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/14 13:31:08 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	explode(t_threads *p)
{
	if (p->head->explode == 1)
		system("afplay ./assets/sound/explode.mp3 &");
	p->head->explode += 1;
	if (p->head->explode > 0 && p->head->explode <= 1000)
		p->x += p->head->width_sprite_2 / 7;
	else if (p->head->explode > 1000 && p->head->explode <= 2000)
		p->x += (p->head->width_sprite_2 / 7) * 2;
	else if (p->head->explode > 2000 && p->head->explode <= 3000)
		p->x += (p->head->width_sprite_2 / 7) * 3;
	else if (p->head->explode > 3000 && p->head->explode <= 4000)
		p->x += (p->head->width_sprite_2 / 7) * 4;
	else if (p->head->explode > 4000 && p->head->explode <= 5000)
		p->x += p->head->width_sprite_2 / 7 * 5;
	else if (p->head->explode > 5000 && p->head->explode <= 6000)
		p->x += p->head->width_sprite_2 / 7 * 4;
	else if (p->head->explode > 6000 && p->head->explode <= 7000)
		p->x += p->head->width_sprite_2 / 7 * 5;
	else if (p->head->explode > 7000 && p->head->explode <= 8000)
		p->x += p->head->width_sprite_2 / 7 * 4;
	else if (p->head->explode > 8000 && p->head->explode <= 9000)
		p->x += p->head->width_sprite_2 / 7 * 5;
	else if (p->head->explode > 9000 && p->head->explode <= 10000)
		p->x += p->head->width_sprite_2 / 7 * 4;
	else if (p->head->explode > 10000)
		p->head->tower = 2;
}

void	draw_bottom_sprite(t_threads *p, t_sprite **sprite, int horizon, int i)
{
	int		*data;

	data = p->head->data;
	p->step = ((double)p->height_sprite_2 * 0.5);
	while (++horizon < p->head->horizon + p->y && horizon < p->head->res_y
		&& p->step < p->height_sprite_2)
	{
		if (sprite[p->i]->t < p->t)
			if (p->text[(int)p->x + (int)p->step * p->width_sprite]
				!= -16777216)
				data[horizon * p->head->width + i]
					= p->text[(int)p->x + (int)p->step * p->width_sprite];
		p->step += (double)p->height_sprite_2 / (double)p->height_sprite;
	}
}

void	draw_top_sprite(t_threads *p, t_sprite **sprite, int horizon, int i)
{
	int		*data;

	data = p->head->data;
	data_sprite(p, sprite[p->i], sprite[p->i]->sprite, i);
	p->step = ((double)p->height_sprite_2 * 0.5);
	horizon = p->head->horizon;
	while (--horizon > p->head->horizon - p->y && horizon >= 0
		&& horizon < p->head->res_y && p->step < p->height_sprite_2
		&& p->step >= 0)
	{
		if ((sprite[p->i]->t < p->t) || (sprite[p->i]->t > p->t
				&& horizon < p->head->horizon - p->height * 0.5))
			if (p->text[(int)p->x + (int)p->step * p->width_sprite]
				!= -16777216)
				data[horizon * p->head->width + i]
					= p->text[(int)p->x + (int)p->step * p->width_sprite];
		p->step -= (double)p->height_sprite_2 / (double)p->height_sprite;
	}
}

void	draw_sprite(t_threads *p, t_sprite **sprite, int horizon, int i)
{
	p->i = -1;
	while (sprite[++p->i])
	{
		if (sprite[p->i]->ratio >= 0.0 && sprite[p->i]->ratio <= 1.0)
		{
			draw_top_sprite(p, sprite, horizon, i);
			p->height_sprite = (1 / sprite[p->i]->t) * p->head->cam_dist;
			horizon = p->head->horizon - 1;
			draw_bottom_sprite(p, sprite, horizon, i);
		}
	}
}
