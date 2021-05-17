/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_death.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:40:49 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/14 13:31:04 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hurt(t_head *head)
{
	if (head->attack)
		system("afplay ./assets/sound/velo.mp3 &");
	mlx_put_image_to_window(head->mlx, head->win, head->text->hurt, 0, 0);
	head->dead += 4;
	if (head->dead > 0 && head->dead <= 10)
		head->attack = 1;
	else if (head->dead > 10 && head->dead <= 20)
		head->attack = 0;
	else if (head->dead > 20 && head->dead <= 30)
		head->attack = 1;
	else if (head->dead > 40 && head->dead <= 50)
		head->attack = 0;
	else if (head->dead > 50 && head->dead <= 60)
		head->attack = 1;
	else if (head->dead > 60 && head->dead <= 70)
		head->attack = 0;
	else if (head->dead > 70 && head->dead <= 80)
		head->attack = 1;
	else if (head->dead > 80 && head->dead <= 90)
		head->attack = 0;
	else if (head->dead > 90 && head->dead <= 100)
		head->attack = 1;
}

void	u_win(t_head *head)
{
	double	ratio;
	double	step;
	int		i;
	int		j;

	system("afplay ./assets/sound/flute.mp3 &");
	ratio = (double)head->width_dead / (double)head->width / 3;
	i = -1;
	while (++i < head->width)
	{
		j = -1;
		step = 0;
		while (++j < head->res_y)
		{
			head->data[j * head->width + i]
				= head->data_dead[(int)(i * ratio)
				+ (int)step * head->width_dead_data + head->width_dead / 3 * 2];
			step += (double)head->height_dead / (double)head->map->res_y;
		}
	}
}

void	u_dead(t_head *head)
{
	double	ratio;
	double	step;
	int		i;
	int		j;

	system("afplay ./assets/sound/ded.mp3 &");
	ratio = (double)head->width_dead / (double)head->width / 3;
	i = -1;
	while (++i < head->width)
	{
		j = -1;
		step = 0;
		while (++j < head->res_y)
		{
			head->data[j * head->width + i]
				= head->data_dead[(int)(i * ratio)
				+ (int)step * head->width_dead_data + head->width_dead / 3 + 3];
			step += (double)head->height_dead / (double)head->map->res_y;
		}
	}
}

void	life(t_head *head)
{
	double	ratio;
	double	step;
	int		i;
	int		j;
	int		max;

	ratio = (double)head->width_life / (double)head->width * 3.2;
	i = head->width / 3;
	max = (int)(2 * head->width / 3 * (1.0 - (double)head->dead * 0.005));
	while (++i < max)
	{
		j = head->res_y / 50;
		step = 0;
		while (++j < head->res_y && step < head->height_life - 5)
		{
			if (head->data_life[(int)(i * ratio)
				+ (int)step * head->width_life_data] != -16777216
				&& head->data_life[(int)(i * ratio)
				+ (int)step * head->width_life_data] != 0)
				head->data[j * head->width + i]
					= head->data_life[(int)(i * ratio)
					+ (int)step * head->width_life_data];
			step += ((double)head->height_life * 10 / (double)head->map->res_y);
		}
	}
}

void	life_death(t_head *head)
{
	if (head->dead >= 100)
		u_dead(head);
	else if (head->tower == 2)
		u_win(head);
}
