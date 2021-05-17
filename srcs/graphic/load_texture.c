/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:57:01 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 12:03:02 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*load_left(void *mlx, t_head *head)
{
	int		width;
	int		height;
	int		endian;
	int		bit;

	endian = 0;
	bit = 0;
	head->img_left
		= mlx_xpm_file_to_image(mlx, head->text->we, &width, &height);
	if (!head->img_left)
	{
		error("Path to west texture is incorrect", head);
		return (NULL);
	}
	head->width_left = width;
	head->data_left
		= (int *)mlx_get_data_addr(head->img_left, &bit, &width, &endian);
	head->width_left_data = width / 4;
	head->height_left = height;
	return (head->img_left);
}

void	*load_right(void *mlx, t_head *head)
{
	int		width;
	int		height;
	int		endian;
	int		bit;

	endian = 0;
	bit = 0;
	head->img_right
		= mlx_xpm_file_to_image(mlx, head->text->ea, &width, &height);
	if (!head->img_right)
	{
		error("Path to east texture is incorrect", head);
		return (NULL);
	}
	head->width_right = width;
	head->data_right
		= (int *)mlx_get_data_addr(head->img_right, &bit, &width, &endian);
	head->width_right_data = width / 4;
	head->height_right = height;
	return (head->img_right);
}

void	*load_bottom(void *mlx, t_head *head)
{
	int		width;
	int		height;
	int		endian;
	int		bit;

	endian = 0;
	bit = 0;
	head->img_bottom
		= mlx_xpm_file_to_image(mlx, head->text->so, &width, &height);
	if (!head->img_bottom)
	{
		error("Path to south texture is incorrect", head);
		return (NULL);
	}
	head->width_bottom = width;
	head->data_bottom
		= (int *)mlx_get_data_addr(head->img_bottom, &bit, &width, &endian);
	head->width_bottom_data = width / 4;
	head->height_bottom = height;
	return (head->img_bottom);
}

void	*load_top(void *mlx, t_head *head)
{
	int		width;
	int		height;
	int		endian;
	int		bit;

	endian = 0;
	bit = 0;
	head->img_top = mlx_xpm_file_to_image(mlx, head->text->no, &width, &height);
	if (!head->img_top)
	{
		error("Path to north texture is incorrect", head);
		return (NULL);
	}
	head->width_top = width;
	head->data_top
		= (int *)mlx_get_data_addr(head->img_top, &bit, &width, &endian);
	head->width_top_data = width / 4;
	head->height_top = height;
	return (head->img_top);
}

int	load_texture(void *mlx, t_head *head)
{
	head->text->sprite = load_sprite(mlx, head, 1);
	head->text->sprite_2 = load_sprite(mlx, head, 2);
	head->text->sprite_3 = load_sprite(mlx, head, 3);
	head->text->top = load_top(mlx, head);
	head->text->bottom = load_bottom(mlx, head);
	head->text->right = load_right(mlx, head);
	head->text->left = load_left(mlx, head);
	head->text->dead = load_dead(mlx, head);
	head->text->weapon = load_weapon(mlx, head);
	head->text->hurt = load_hurt(mlx, head);
	head->text->life = load_life(mlx, head);
	head->text->door = load_door(mlx, head);
	load_skybox(mlx, head, 0);
	load_skybox(mlx, head, 1);
	load_skybox(mlx, head, 2);
	load_skybox(mlx, head, 3);
	if (!head->text->top || !head->text->bottom || !head->text->right
		|| !head->text->left || !head->text->sprite)
		return (0);
	return (1);
}
