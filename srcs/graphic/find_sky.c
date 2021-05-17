/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:31:43 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/11 19:29:54 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_sky_0(t_threads *thread, t_vec *vec)
{
	double	plan;
	double	x;
	double	y;
	double	t;

	thread->vector = vector_equation(vec, thread->head->map->skybox[0]);
	plan = plan_equation(thread->head, thread->head->map->skybox[0]);
	t = plan / thread->vector;
	x = thread->head->map->player_x + vec->x * t;
	y = -thread->head->map->skybox[0]->d;
	if (y == (-1000.0) && x >= -1000.0 && x <= 1000.0)
	{
		x += 1000;
		thread->ratio_sky = thread->head->width_sky * (x / 2000);
		thread->i = 0;
	}
}

void	find_sky_1(t_threads *thread, t_vec *vec)
{
	double	plan;
	double	x;
	double	y;
	double	t;

	thread->vector = vector_equation(vec, thread->head->map->skybox[1]);
	plan = plan_equation(thread->head, thread->head->map->skybox[1]);
	t = plan / thread->vector;
	y = thread->head->map->player_y + vec->y * t;
	x = -thread->head->map->skybox[1]->d;
	if (x == 1000.0 && y >= -1000.0 && y <= 1000.0)
	{
		y += 1000;
		thread->ratio_sky = thread->head->width_sky * (y / 2000);
		thread->i = 1;
	}
}

void	find_sky_2(t_threads *thread, t_vec *vec)
{
	double	plan;
	double	x;
	double	y;
	double	t;

	thread->vector = vector_equation(vec, thread->head->map->skybox[2]);
	plan = plan_equation(thread->head, thread->head->map->skybox[2]);
	t = plan / thread->vector;
	x = thread->head->map->player_x + vec->x * t;
	y = -thread->head->map->skybox[2]->d;
	if (y == (1000.0) && x >= -1000.0 && x <= 1000.0)
	{
		x += 1000;
		thread->ratio_sky = thread->head->width_sky * (x / 2000);
		thread->i = 2;
	}
}

void	find_sky_3(t_threads *thread, t_vec *vec)
{
	double	plan;
	double	x;
	double	y;
	double	t;

	thread->vector = vector_equation(vec, thread->head->map->skybox[3]);
	plan = plan_equation(thread->head, thread->head->map->skybox[3]);
	t = plan / thread->vector;
	y = thread->head->map->player_y + vec->y * t;
	x = -thread->head->map->skybox[3]->d;
	if (x == -1000.0 && y >= -1000.0 && y <= 1000.0)
	{
		y += 1000;
		thread->ratio_sky = thread->head->width_sky * (y / 2000);
		thread->i = 3;
	}
}

void	find_sky(t_threads *thread, t_vec *vec)
{
	thread->i = -1;
	if (vec->x < 0)
		find_sky_3(thread, vec);
	else if (vec->x > 0)
		find_sky_1(thread, vec);
	if (vec->y < 0)
		find_sky_0(thread, vec);
	else if (vec->y > 0)
		find_sky_2(thread, vec);
}
