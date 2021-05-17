/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:15:31 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/14 14:05:13 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_top_plan(t_threads *p, t_vec *vec)
{
	int		i;
	double	t;
	double	plan;

	i = p->head->map->player_y - 1;
	while (++i < p->head->max_y + 1)
	{
		while (!p->head->map->tab_top[i] && i < p->head->max_y + 1)
			i++;
		if (p->head->map->tab_top[i])
		{
			p->vector = vector_equation(vec, p->head->map->tab_top[i]);
			plan = plan_equation(p->head, p->head->map->tab_top[i]);
			t = plan / p->vector;
			if (t < p->t && t > 0)
			{
				p->x = p->head->map->player_x + vec->x * t;
				p->y = -p->head->map->tab_top[i]->d;
				if (valid_x_y(p)
					&& valid_wall(p->head->map->map[i][(int)p->x]))
					return (store_t(p, t, 1
							, p->head->map->map[i][(int)p->x]));
			}
		}
	}
}

void	find_bottom_plan(t_threads *p, t_vec *vec)
{
	int		i;
	double	t;
	double	plan;

	i = p->head->map->player_y + 1;
	while (--i > 0)
	{
		while (!p->head->map->tab_bottom[i] && i > 0)
			i--;
		if (p->head->map->tab_bottom[i])
		{
			p->vector = vector_equation(vec, p->head->map->tab_bottom[i]);
			plan = plan_equation(p->head, p->head->map->tab_bottom[i]);
			t = plan / p->vector;
			if (t < p->t && t > 0)
			{
				p->x = p->head->map->player_x + vec->x * t;
				p->y = -p->head->map->tab_bottom[i]->d;
				if (valid_x_y(p)
					&& valid_wall(p->head->map->map[(int)(i - 1.0)][(int)p->x]))
					return (store_t(p, t, 3
							, p->head->map->map[(int)(i - 1.0)][(int)p->x]));
			}
		}
	}
}

void	find_right_plan(t_threads *p, t_vec *vec)
{
	int		i;
	double	t;
	double	plan;

	i = p->head->map->player_x + 1;
	while (--i > 0)
	{
		while (!p->head->map->tab_right[i] && i > 0)
			i--;
		if (p->head->map->tab_right[i])
		{
			p->vector = vector_equation(vec, p->head->map->tab_right[i]);
			plan = plan_equation(p->head, p->head->map->tab_right[i]);
			t = plan / p->vector;
			if (t < p->t && t > 0)
			{
				p->x = -p->head->map->tab_right[i]->d;
				p->y = p->head->map->player_y + vec->y * t;
				if (valid_x_y(p)
					&& valid_wall(p->head->map->map[(int)p->y][(int)(i - 1.0)]))
					return (store_t(p, t, 2
							, p->head->map->map[(int)p->y][(int)(i - 1.0)]));
			}
		}
	}
}

void	find_left_plan(t_threads *p, t_vec *vec)
{
	int		i;
	double	t;
	double	plan;

	i = p->head->map->player_x - 1;
	while (++i < p->head->max_x + 1)
	{
		while (!p->head->map->tab_left[i])
			i++;
		if (p->head->map->tab_left[i])
		{
			p->vector = vector_equation(vec, p->head->map->tab_left[i]);
			plan = plan_equation(p->head, p->head->map->tab_left[i]);
			t = plan / p->vector;
			if (t < p->t && t > 0)
			{
				p->x = -p->head->map->tab_left[i]->d;
				p->y = p->head->map->player_y + vec->y * t;
				if (valid_x_y(p)
					&& valid_wall (p->head->map->map[(int)p->y][i]))
					return (store_t(p, t, 4
							, p->head->map->map[(int)p->y][i]));
			}
		}
	}
}
