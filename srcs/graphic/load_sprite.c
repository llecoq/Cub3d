/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:09:01 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 13:11:33 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*sprite_1(t_head *head, int width, int height)
{
	int		end;
	int		bit;

	end = 0;
	bit = 0;
	head->width_sprite = width;
	head->data_sprite
		= (int *)mlx_get_data_addr(head->img_sprite, &bit, &width, &end);
	head->width_sprite_data = width / 4;
	head->height_sprite = height;
	return (head->img_sprite);
}

void	*sprite_2(t_head *head, int width, int height)
{
	int		end;
	int		bit;

	end = 0;
	bit = 0;
	head->width_sprite_2 = width;
	head->data_sprite_2
		= (int *)mlx_get_data_addr(head->img_sprite_2, &bit, &width, &end);
	head->width_sprite_data_2 = width / 4;
	head->height_sprite_2 = height;
	return (head->img_sprite_2);
}

void	*sprite_3(t_head *head, int width, int height)
{
	int		end;
	int		bit;

	end = 0;
	bit = 0;
	head->width_sprite_3 = width;
	head->data_sprite_3
		= (int *)mlx_get_data_addr(head->img_sprite_3, &bit, &width, &end);
	head->width_sprite_data_3 = width / 4;
	head->height_sprite_3 = height;
	return (head->img_sprite_3);
}

void	*load_sprite(void *mlx, t_head *head, int n)
{
	int		width;
	int		height;

	if (n == 1)
		head->img_sprite
			= mlx_xpm_file_to_image(mlx, head->text->s, &width, &height);
	else if (n == 2)
		head->img_sprite_2
			= mlx_xpm_file_to_image(mlx, "./assets/xpm/e.xpm", &width, &height);
	else if (n == 3)
		head->img_sprite_3
			= mlx_xpm_file_to_image(mlx, "./assets/xpm/p.xpm", &width, &height);
	if (!head->img_sprite)
	{
		error("Path to sprite texture is incorrect", head);
		return (NULL);
	}
	if (n == 1)
		return (sprite_1(head, width, height));
	else if (n == 2)
		return (sprite_2(head, width, height));
	else if (n == 3)
		return (sprite_3(head, width, height));
	return (NULL);
}
