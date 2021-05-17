/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:05:22 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/11 19:40:06 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calcul_ratio(t_threads *p, double ratio, double a, double b)
{
	if (p->head->player_dir >= 2.35 && p->head->player_dir < 3.92
		&& b < 0)
		ratio = -ratio;
	if (p->head->player_dir >= 3.92 && p->head->player_dir < 5.49
		&& a < 0)
		ratio = -ratio;
	if (p->head->player_dir >= 5.49 && b > 0)
		ratio = -ratio;
	if (p->head->player_dir >= 0 && p->head->player_dir < 0.78
		&& b > 0)
		ratio = -ratio;
	if (p->head->player_dir >= 0.78 && p->head->player_dir < 2.35
		&& a > 0)
		ratio = -ratio;
	return (ratio);
}

double	find_ratio(t_threads *p, t_sprite *sprite)
{
	double	a;
	double	b;
	double	ratio;

	a = sprite->sy - sprite->y;
	b = sprite->sx - sprite->x;
	ratio = sqrt(pow(a, 2.0) + pow(b, 2.0));
	if (ratio <= 0.5)
		ratio = calcul_ratio(p, ratio, a, b);
	ratio += 0.5;
	return (ratio);
}

int	valid_sprite(t_threads *p, int i, t_sprite **sprite)
{
	if (sprite[i]->sx >= 0 && sprite[i]->sy >= 0
		&& sprite[i]->sy <= p->head->max_y
		&& sprite[i]->sx <= ft_strlen(p->head->map->map[(int)sprite[i]->sy])
		&& (p->head->map->map[(int)sprite[i]->sy][(int)sprite[i]->sx] == '2'
		|| p->head->map->map[(int)sprite[i]->sy][(int)sprite[i]->sx] == '3'
		|| p->head->map->map[(int)sprite[i]->sy][(int)sprite[i]->sx] == '4'
		|| p->head->map->map[(int)sprite[i]->sy][(int)sprite[i]->sx] == '5'))
		return (1);
	return (0);
}

void	find_sprite(t_threads *p, t_vec *vec, t_sprite **sprite)
{
	double		plan;
	double		vector;
	int			i;

	i = -1;
	while (sprite[++i])
	{
		vector = vector_equation_sprite(vec, sprite[i]);
		plan = plan_equation_sprite(p->head, sprite[i]);
		sprite[i]->t = plan / vector;
		sprite[i]->ratio = -1.0;
		if (sprite[i]->t > 0)
		{
			sprite[i]->sx = p->head->map->player_x + vec->x * sprite[i]->t;
			sprite[i]->sy = p->head->map->player_y + vec->y * sprite[i]->t;
			if (valid_sprite(p, i, sprite))
				sprite[i]->ratio = find_ratio(p, sprite[i]);
		}
	}
}
