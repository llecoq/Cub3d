/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:12:10 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 15:10:11 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*load_dead(void *mlx, t_head *head)
{
	int		width;
	int		height;
	int		endian;
	int		bit;

	endian = 0;
	bit = 0;
	head->img_dead
		= mlx_xpm_file_to_image(mlx, "./assets/xpm/w.xpm", &width, &height);
	head->width_dead = width;
	head->data_dead
		= (int *)mlx_get_data_addr(head->img_dead, &bit, &width, &endian);
	head->width_dead_data = width / 4;
	head->height_dead = height;
	return (head->img_dead);
}

void	*load_weapon(void *mlx, t_head *head)
{
	int		width;
	int		height;
	int		endian;
	int		bit;

	endian = 0;
	bit = 0;
	head->img_weapon
		= mlx_xpm_file_to_image(mlx, "./assets/xpm/bonk2.xpm", &width, &height);
	head->width_weapon = width;
	head->data_weapon
		= (int *)mlx_get_data_addr(head->img_weapon, &bit, &width, &endian);
	head->width_weapon_data = width / 4;
	head->height_weapon = height;
	return (head->img_weapon);
}

void	*load_life(void *mlx, t_head *head)
{
	int		width;
	int		height;
	int		endian;
	int		bit;

	endian = 0;
	bit = 0;
	head->img_life
		= mlx_xpm_file_to_image(mlx, "./assets/xpm/life.xpm", &width, &height);
	head->width_life = width;
	head->data_life
		= (int *)mlx_get_data_addr(head->img_life, &bit, &width, &endian);
	head->width_life_data = width / 4;
	head->height_life = height;
	return (head->img_life);
}

void	*load_door(void *mlx, t_head *head)
{
	int		width;
	int		height;
	int		endian;
	int		bit;

	endian = 0;
	bit = 0;
	head->img_door
		= mlx_xpm_file_to_image(mlx, "./assets/xpm/door.xpm", &width, &height);
	head->width_door = width;
	head->data_door
		= (int *)mlx_get_data_addr(head->img_door, &bit, &width, &endian);
	head->width_door_data = width / 4;
	head->height_door = height;
	return (head->img_door);
}

void	*load_hurt(void *mlx, t_head *head)
{
	head->text->hurt = mlx_new_image(mlx, head->res_x, head->res_y);
	return (head->text->hurt);
}
