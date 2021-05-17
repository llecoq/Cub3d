/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:59:07 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/11 19:01:29 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_top_wall(t_threads *p, int y, int i, int width)
{
	int		*data;
	int		x;

	x = p->ratio;
	data = p->head->data;
	p->horizon = p->head->horizon + 1;
	while (--p->horizon > p->head->horizon - y
		&& p->horizon >= 0 && p->horizon < p->head->res_y)
	{
		data[p->horizon * p->head->width + i]
			= p->text[x + (int)p->step * width];
		p->step -= (double)p->height_text / (double)p->height;
	}
}

void	draw_bottom_wall(t_threads *p, int y, int i, int width)
{
	int		*data;
	int		x;

	x = p->ratio;
	data = p->head->data;
	while (++p->horizon <= p->head->horizon + y
		&& p->horizon < p->head->res_y && p->step <= p->height_text)
	{
		data[p->horizon * p->head->width + i]
			= p->text[x + (int)p->step * width];
		p->step += (double)p->height_text / (double)p->height;
	}
	p->step = (p->height_text * 0.5);
	p->step -= (double)p->height_text / (double)p->height;
}

void	draw_floor(t_threads *p, int i, int *data)
{
	p->horizon--;
	while (++p->horizon < p->head->res_y && p->horizon >= 0)
		data[p->horizon * p->head->width + i] = p->head->text->f;
}

void	draw_ceiling(t_threads *p, int i, int *data)
{
	double	step;
	int		height;
	int		x;
	int		*sky_data;
	double	ratio;

	height = 2000;
	sky_data = data_sky(p, p->i);
	ratio = 1 - (p->height * 0.5) / height;
	x = p->ratio_sky;
	step = ratio * p->head->height_sky;
	step -= ((double)p->head->height_sky / (double)height) * 300;
	p->horizon++;
	if (p->ratio_sky)
	{
		while (--p->horizon >= 0 && p->horizon < p->head->res_y && step >= 0)
		{
			data[p->horizon * p->head->width + i]
				= sky_data[x + (int)step * p->head->width_sky_data];
			step -= (double)p->head->height_sky / (double)height;
		}
	}
	else
		while (--p->horizon >= 0 && p->horizon < p->head->res_y)
			data[p->horizon * p->head->width + i] = p->head->text->c;
}
