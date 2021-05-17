/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:17:39 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/13 18:51:02 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forward(t_head *h)
{
	double	x;
	double	y;

	x = h->map->player_x + cos(h->player_dir + M_PI_2) * 0.05 * h->speed;
	y = h->map->player_y + sin(h->player_dir + M_PI_2) * 0.05 * h->speed;
	if (h->map->map[(int)h->map->player_y][(int)x] != '1'
		&& h->map->map[(int)h->map->player_y][(int)x] != '2'
		&& h->map->map[(int)h->map->player_y][(int)x] != '3'
		&& h->map->map[(int)h->map->player_y][(int)x] != '4'
		&& h->map->map[(int)h->map->player_y][(int)x] != '6'
		&& h->map->map[(int)h->map->player_y][(int)x] != '7')
		h->map->player_x += cos(h->player_dir + M_PI_2)
			* 0.05 * h->speed;
	if (h->map->map[(int)y][(int)h->map->player_x] != '1'
		&& h->map->map[(int)y][(int)h->map->player_x] != '2'
		&& h->map->map[(int)y][(int)h->map->player_x] != '3'
		&& h->map->map[(int)y][(int)h->map->player_x] != '4'
		&& h->map->map[(int)y][(int)h->map->player_x] != '6'
		&& h->map->map[(int)y][(int)h->map->player_x] != '7')
		h->map->player_y += sin(h->player_dir + M_PI_2)
			* 0.05 * h->speed;
}

void	backward(t_head *head)
{
	double	x;
	double	y;

	x = head->map->player_x
		+ cos(head->player_dir - M_PI_2) * 0.040 * head->speed;
	y = head->map->player_y
		+ sin(head->player_dir - M_PI_2) * 0.040 * head->speed;
	if (head->map->map[(int)head->map->player_y][(int)x] != '1'
		&& head->map->map[(int)head->map->player_y][(int)x] != '2'
		&& head->map->map[(int)head->map->player_y][(int)x] != '3'
		&& head->map->map[(int)head->map->player_y][(int)x] != '4'
		&& head->map->map[(int)head->map->player_y][(int)x] != '6'
		&& head->map->map[(int)head->map->player_y][(int)x] != '7')
		head->map->player_x = x;
	if (head->map->map[(int)y][(int)head->map->player_x] != '1'
		&& head->map->map[(int)y][(int)head->map->player_x] != '2'
		&& head->map->map[(int)y][(int)head->map->player_x] != '3'
		&& head->map->map[(int)y][(int)head->map->player_x] != '4'
		&& head->map->map[(int)y][(int)head->map->player_x] != '6'
		&& head->map->map[(int)y][(int)head->map->player_x] != '7')
		head->map->player_y = y;
}

void	right(t_head *head)
{
	double	x;
	double	y;

	x = head->map->player_x + cos(head->player_dir + M_PI)
		* 0.040 * head->speed;
	y = head->map->player_y + sin(head->player_dir + M_PI) * 0.040
		* head->speed;
	if (head->map->map[(int)head->map->player_y][(int)x] != '1'
		&& head->map->map[(int)head->map->player_y][(int)x] != '2'
		&& head->map->map[(int)head->map->player_y][(int)x] != '3'
		&& head->map->map[(int)head->map->player_y][(int)x] != '4'
		&& head->map->map[(int)head->map->player_y][(int)x] != '6'
		&& head->map->map[(int)head->map->player_y][(int)x] != '7')
		head->map->player_x = x;
	if (head->map->map[(int)y][(int)head->map->player_x] != '1'
		&& head->map->map[(int)y][(int)head->map->player_x] != '2'
		&& head->map->map[(int)y][(int)head->map->player_x] != '3'
		&& head->map->map[(int)y][(int)head->map->player_x] != '4'
		&& head->map->map[(int)y][(int)head->map->player_x] != '6'
		&& head->map->map[(int)y][(int)head->map->player_x] != '7')
		head->map->player_y = y;
}

void	left(t_head *head)
{
	double	x;
	double	y;

	x = head->map->player_x + cos(head->player_dir)
		* 0.040 * head->speed;
	y = head->map->player_y + sin(head->player_dir) * 0.040
		* head->speed;
	if (head->map->map[(int)head->map->player_y][(int)x] != '1'
		&& head->map->map[(int)head->map->player_y][(int)x] != '2'
		&& head->map->map[(int)head->map->player_y][(int)x] != '3'
		&& head->map->map[(int)head->map->player_y][(int)x] != '4'
		&& head->map->map[(int)head->map->player_y][(int)x] != '6'
		&& head->map->map[(int)head->map->player_y][(int)x] != '7')
		head->map->player_x = x;
	if (head->map->map[(int)y][(int)head->map->player_x] != '1'
		&& head->map->map[(int)y][(int)head->map->player_x] != '2'
		&& head->map->map[(int)y][(int)head->map->player_x] != '3'
		&& head->map->map[(int)y][(int)head->map->player_x] != '4'
		&& head->map->map[(int)y][(int)head->map->player_x] != '6'
		&& head->map->map[(int)y][(int)head->map->player_x] != '7')
		head->map->player_y = y;
}
