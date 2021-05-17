/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:50:49 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 15:15:19 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	red_cross(void *structure)
{
	t_head	*head;

	head = (t_head *)structure;
	ft_clear_memory(head);
	exit (0);
}

void	draw_weapon(t_head *head, int k)
{
	double	ratio;
	double	step;
	int		n;
	int		i;
	int		j;

	ratio = (double)head->width_weapon / (double)head->width;
	ratio /= 9;
	n = head->width_weapon / 9 * k;
	i = -1;
	while (++i < head->width)
	{
		j = -1;
		step = 0;
		while (++j < head->res_y)
		{
			if (head->data_weapon[(int)(i * ratio)
				+ (int)step * head->width_weapon_data + n] != -16777216)
				head->data[j * head->width + i]
					= head->data_weapon[(int)(i * ratio)
					+ (int)step * head->width_weapon_data + n];
			step += (double)head->height_weapon / (double)head->map->res_y;
		}
	}
}

void	bonk(t_head *head)
{
	if (head->stack_time == 0.0)
		head->bonk = 0;
	if (head->stack_time > 0.0 && head->stack_time <= 0.02)
		head->bonk = 1;
	if (head->stack_time > 0.02 && head->stack_time <= 0.04)
		head->bonk = 2;
	if (head->stack_time > 0.04 && head->stack_time <= 0.06)
		head->bonk = 3;
	if (head->stack_time > 0.06 && head->stack_time <= 0.08)
		head->bonk = 4;
	if (head->stack_time > 0.08 && head->stack_time <= 0.1)
		head->bonk = 5;
	if (head->stack_time > 0.1 && head->stack_time <= 0.12)
		head->bonk = 6;
	if (head->stack_time > 0.12 && head->stack_time <= 0.14)
		head->bonk = 7;
	if (head->stack_time > 0.14)
		head->bonk = 8;
	if (head->stack_time > 0.16)
		head->control.shoot = 2;
	if (head->control.shoot == 2
		&& head->map->map[(int)head->map->player_y][(int)head->map->player_x]
		== '5')
		head->attack = 3;
}
