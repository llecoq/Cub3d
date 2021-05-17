/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:10:19 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 15:11:29 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	data_door(t_threads *p)
{
	p->text = p->head->data_door;
	p->step = ((double)p->head->height_door / 2.0);
	p->width = p->head->width_door;
	p->height_text = p->head->height_door;
	p->ratio *= 0.7;
	return (p->head->width_door_data);
}

void	data_killer_penguin(t_threads *p, t_sprite *sprite)
{
	p->height_sprite = (1 / sprite->t) * p->head->cam_dist;
	p->y = p->height_sprite * 0.5;
	p->x = (p->head->width_sprite_3 * sprite->ratio) / 3;
	if (p->head->attack == 1)
		p->x += p->head->width_sprite / 3;
	else if (p->head->attack == 3)
		p->x += p->head->width_sprite / 3 * 2;
	p->width_sprite = p->head->width_sprite_data_3;
	p->text = p->head->data_sprite_3;
	p->height_sprite_2 = p->head->height_sprite_3;
}

void	data_tower(t_threads *p, t_sprite *sprite, int i)
{
	if (i == p->head->width / 2 && p->head->control.launch == 1)
		p->head->tower = 1;
	p->height_sprite = (8 / sprite->t) * p->head->cam_dist;
	p->y = p->height_sprite * 0.5;
	p->x = (p->head->width_sprite_2 * sprite->ratio) / 7;
	if (p->head->tower == 1)
		explode(p);
	else if (p->head->tower == 2)
		p->x += p->head->width_sprite_2 / 7 * 6;
	p->width_sprite = p->head->width_sprite_data_2;
	p->text = p->head->data_sprite_2;
	p->height_sprite_2 = p->head->height_sprite_2;
}

void	data_sprite(t_threads *p, t_sprite *sprite, int n, int i)
{
	if (n == 2 || n == 4)
	{
		if (n == 2)
			p->height_sprite = (1 / sprite->t) * p->head->cam_dist;
		else if (n == 4)
			p->height_sprite = (3 / sprite->t) * p->head->cam_dist;
		p->y = p->height_sprite * 0.5;
		p->x = (p->head->width_sprite * sprite->ratio);
		p->width_sprite = p->head->width_sprite_data;
		p->text = p->head->data_sprite;
		p->height_sprite_2 = p->head->height_sprite;
	}
	else if (n == 3)
		data_tower(p, sprite, i);
	else if (n == 5)
		data_killer_penguin(p, sprite);
}
