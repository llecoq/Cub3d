/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_skybox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:10:46 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 09:50:19 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	data_skybox(t_head *head, int i)
{
	int		width;
	int		endian;
	int		bit;

	endian = 0;
	bit = 0;
	if (i == 0)
		head->data_sky_0
			= (int *)mlx_get_data_addr(head->sky_0, &bit, &width, &endian);
	if (i == 1)
		head->data_sky_1
			= (int *)mlx_get_data_addr(head->sky_1, &bit, &width, &endian);
	if (i == 2)
		head->data_sky_2
			= (int *)mlx_get_data_addr(head->sky_2, &bit, &width, &endian);
	if (i == 3)
		head->data_sky_3
			= (int *)mlx_get_data_addr(head->sky_3, &bit, &width, &endian);
	head->width_sky_data = width / 4;
}

void	load_skybox(void *mlx, t_head *head, int i)
{
	int		width;
	int		height;
	int		endian;
	int		bit;

	endian = 0;
	bit = 0;
	if (i == 0)
		head->sky_0
			= mlx_xpm_file_to_image(mlx, "./assets/xpm/0.xpm", &width, &height);
	if (i == 1)
		head->sky_1
			= mlx_xpm_file_to_image(mlx, "./assets/xpm/1.xpm", &width, &height);
	if (i == 2)
		head->sky_2
			= mlx_xpm_file_to_image(mlx, "./assets/xpm/2.xpm", &width, &height);
	if (i == 3)
		head->sky_3
			= mlx_xpm_file_to_image(mlx, "./assets/xpm/3.xpm", &width, &height);
	head->width_sky = width;
	head->height_sky = height;
	data_skybox(head, i);
}
