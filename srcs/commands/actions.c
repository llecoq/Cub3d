/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:22:26 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 15:15:12 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sit(t_head *head, int n)
{
	head->control.sit = 0;
	if (n == 0)
	{
		head->horizon = head->res_y * 0.5 - 300;
		head->control.up_down = 1;
	}
	else if (n == 1)
	{
		head->horizon = head->res_y * 0.5;
		head->control.up_down = 0;
	}
}

void	open_door(t_head *head)
{
	int	x;
	int	y;

	x = (int)head->map->player_x;
	y = (int)head->map->player_y;
	if (head->map->map[y + 1][x] == '7')
	{
		head->map->map[y + 1][x] = '8';
		head->door = 1;
	}
	else if (head->map->map[y - 1][x] == '7')
	{
		head->map->map[y - 1][x] = '8';
		head->door = 1;
	}
	else if (head->map->map[y][x + 1] == '7')
	{
		head->map->map[y][x + 1] = '8';
		head->door = 1;
	}
	else if (head->map->map[y][x - 1] == '7')
	{
		head->map->map[y][x - 1] = '8';
		head->door = 1;
	}
}

void	close_door(t_head *head)
{
	int	x;
	int	y;

	x = (int)head->map->player_x;
	y = (int)head->map->player_y;
	if (head->map->map[y + 1][x] == '8')
	{
		head->map->map[y + 1][x] = '7';
		head->door = 0;
	}
	else if (head->map->map[y - 1][x] == '8')
	{
		head->map->map[y - 1][x] = '7';
		head->door = 0;
	}
	else if (head->map->map[y][x + 1] == '8')
	{
		head->map->map[y][x + 1] = '7';
		head->door = 0;
	}
	else if (head->map->map[y][x - 1] == '8')
	{
		head->map->map[y][x - 1] = '7';
		head->door = 0;
	}
}

void	open_secret_door(t_head *head)
{
	int	x;
	int	y;

	x = (int)head->map->player_x;
	y = (int)head->map->player_y;
	if (head->map->map[y + 1][x] == '6')
	{
		head->map->map[y + 1][x] = '0';
		head->secret_door = 1;
	}
	else if (head->map->map[y - 1][x] == '6')
	{
		head->map->map[y - 1][x] = '0';
		head->secret_door = 1;
	}
	else if (head->map->map[y][x + 1] == '6')
	{
		head->map->map[y][x + 1] = '0';
		head->secret_door = 1;
	}
	else if (head->map->map[y][x - 1] == '6')
	{
		head->map->map[y][x - 1] = '0';
		head->secret_door = 1;
	}
}

void	jump(t_head *head)
{
	if (head->control.count <= 5.0 && head->control.reverse == 0)
	{
		head->control.gravity = 25.0 - pow(head->control.count, 2);
		if (head->horizon < head->res_y - 50)
			head->horizon += head->control.gravity;
		head->control.count += 0.3 * head->speed;
		if (head->control.count >= 5.0)
			head->control.reverse = 1;
	}
	if (head->control.reverse == 1)
	{
		head->control.gravity = 25.0 - pow(head->control.count, 2);
		head->horizon -= head->control.gravity;
		head->control.count -= 0.3 * head->speed;
		if (head->control.count <= 0.0)
			head->control.space = 0;
	}
}
