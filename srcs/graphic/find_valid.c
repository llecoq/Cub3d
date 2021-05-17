/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:04:53 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/14 14:05:56 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_x_y(t_threads *thread)
{
	if (thread->x >= thread->head->min_x
		&& thread->y >= 0
		&& thread->y <= thread->head->max_y + 1
		&& thread->x <= ft_strlen(thread->head->map->map[(int)thread->y]))
		return (1);
	return (0);
}

int	valid_wall(char c)
{
	if (c == '1' || c == '6' || c == '7')
		return (1);
	return (0);
}
