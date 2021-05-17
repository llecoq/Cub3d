/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:08:21 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/11 18:22:06 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_map_max(t_head *head)
{
	head->map->max_y = head->map->player_y;
	head->map->min_y = head->map->player_y;
	head->map->max_x = head->map->player_x;
	head->map->min_x = head->map->player_x;
}

void	map_max(t_head *head, char c, int x, int y)
{
	if (c == '0')
	{
		if (x <= head->map->min_x)
			head->map->min_x = x - 1;
		else if (x >= head->map->max_x)
			head->map->max_x = x + 1;
		if (y <= head->map->min_y)
			head->map->min_y = y - 1;
		else if (y >= head->map->max_y)
			head->map->max_y = y + 1;
	}
	head->max_x = head->map->max_x;
	head->max_y = head->map->max_y;
	head->min_x = head->map->min_x;
	head->min_y = head->map->min_y;
}

int	inter(char c, char *old)
{
	int		i;

	i = 0;
	while (old[i])
	{
		if (old[i] == c)
			return (1);
		i++;
	}
	return (0);
}
