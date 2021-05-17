/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:19:52 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/11 19:10:56 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_vectors(t_head *head, int width)
{
	double	coeff;
	double	id;

	id = 0.0;
	head->cam_dist = ((width / 2) / tan(M_PI / 6));
	coeff = (2 * tan(M_PI / 6)) / width;
	if (!ft_calloc_vec(&head->vec_tab, width, sizeof(t_plan *)))
		if (ft_clear_memory(head))
			exit (0);
	head->i = width / 2 + 1;
	while (head->i-- > 0)
	{
		head->x = id * coeff;
		head->vec_tab[head->i] = new_vec(head->x, 1.0);
		id++;
	}
	head->i = width / 2;
	id = 1.0;
	while (++head->i < width)
	{
		head->x = id * coeff;
		head->vec_tab[head->i] = new_vec(head->x, 1.0);
		id--;
	}
}

void	screen_size(t_head *head)
{
	mlx_get_screen_size(head->mlx, &head->size_x, &head->size_y);
	if (head->map->res_x > head->size_x)
		head->map->res_x = head->size_x;
	if (head->map->res_y > head->size_y)
		head->map->res_y = head->size_y;
	head->res_x = head->map->res_x;
	head->res_y = head->map->res_y;
	head->horizon = head->map->res_y / 2;
}

void	new_image(t_head *head)
{
	int		endian;
	int		bit;

	endian = 0;
	bit = 0;
	head->img = mlx_new_image(head->mlx, head->res_x, head->map->res_y);
	head->data
		= (int *)mlx_get_data_addr(head->img, &bit, &head->width, &endian);
	head->width /= 4;
}

int	cub3d(t_head *head)
{
	head->mlx = mlx_init();
	if (!head->mlx)
		return (-1);
	screen_size(head);
	head->win
		= mlx_new_window(head->mlx, head->res_x, head->map->res_y, "cub3d");
	if (!load_texture(head->mlx, head))
		return (0);
	new_image(head);
	init_vectors(head, head->width);
	head->vec_dir = head->vec_tab[head->width / 2];
	key_hook(head);
	mlx_loop_hook(head->mlx, &update, head);
	mlx_loop(head->mlx);
	return (1);
}
