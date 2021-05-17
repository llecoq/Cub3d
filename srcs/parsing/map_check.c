/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 08:39:31 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/14 15:20:24 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	flood(int x, int y, char **copy, t_head *head)
{
	char	*wall;

	wall = "NSWE07654321*";
	if (inter(copy[y][x], "NSWE0234567") && head->parse->error == 0)
	{
		if (y > 0 && y + 1 < head->map->len && x < ft_strlen(copy[y + 1])
			&& x < ft_strlen(copy[y - 1]))
		{
			if (!(inter(copy[y][x + 1], wall)) || !(inter(copy[y][x - 1], wall))
				|| !(inter(copy[y + 1][x], wall))
				|| !(inter(copy[y - 1][x], wall)))
				error("Map is not closed", head);
			map_max(head, copy[y][x], x, y);
			store_plan(x, y, copy, head);
			copy[y][x] = '*';
			flood(x + 1, y, copy, head);
			flood(x - 1, y, copy, head);
			flood(x, y + 1, copy, head);
			flood(x, y - 1, copy, head);
		}
		if (y == 0 || y + 1 == head->map->len || x >= ft_strlen(copy[y + 1])
			|| x >= ft_strlen(copy[y - 1]))
			error("Map is not closed", head);
	}
}

int	valid_map(t_head *head)
{
	t_sprite	*sprite;
	char		**copy;
	int			x;
	int			y;

	sprite = NULL;
	copy = copy_tab(head->map->map, head);
	x = (int)head->map->player_x;
	y = (int)head->map->player_y;
	init_map_max(head);
	flood(x, y, copy, head);
	clear_tab(copy);
	if (head->parse->error == 1)
		return (0);
	store_sprite(head, sprite);
	store_plan_tab(head, head->map->max_y, head->map->max_x);
	if (head->parse->dir == 'E')
		head->player_dir = -M_PI / 2;
	else if (head->parse->dir == 'W')
		head->player_dir = M_PI / 2;
	else if (head->parse->dir == 'S')
		head->player_dir = 2 * M_PI;
	else if (head->parse->dir == 'N')
		head->player_dir = M_PI;
	return (1);
}

int	valid_player_dir(char c, t_head *head, int i)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (head->parse->map == -1)
			return (0);
		if (head->parse->dir != '0')
			return (parse_error_map(2, head));
		head->parse->dir = c;
		head->map->player_y = (double)head->map->len + 0.5;
		head->map->player_x = (double)i + 0.5;
	}
	return (1);
}

int	treat_map(t_head *head, char *line, t_list **map)
{
	t_list	*temp;

	if (!(valid_map_line(line, head)))
		return (parse_error_map(1, head));
	temp = ft_lstnew(line);
	ft_lstadd_back(map, temp);
	head->map->len++;
	return (1);
}

int	valid_map_line(char *line, t_head *head)
{
	char	*valid;
	int		i;
	int		j;

	valid = "01234567 NSEW";
	i = 0;
	if (line[i] == 0 && head->parse->map == 0)
		return (1);
	while (line[i] == ' ')
		i++;
	if (i == ft_strlen(line))
		return (0);
	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i] != valid[j] && valid[j])
			j++;
		if (line[i] != valid[j])
			return (0);
		valid_player_dir(line[i], head, i);
		i++;
	}
	head->parse->map = 0;
	return (1);
}
