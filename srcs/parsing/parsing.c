/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 08:30:55 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/14 14:07:54 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	valid_parse(t_head *head)
{
	if (head->parse->map == -1)
		error("Map is missing", head);
	if (head->map->res_x == -1)
		error("x resolution is missing", head);
	if (head->map->res_y == -1)
		error("y resolution is missing", head);
	if (head->text->no == NULL)
		error("North texture is missing", head);
	if (head->text->so == NULL)
		error("South texture is missing", head);
	if (head->text->we == NULL)
		error("West texture is missing", head);
	if (head->text->ea == NULL)
		error("East texture is missing", head);
	if (head->text->s == NULL)
		error("Sprite texture is missing", head);
	if (head->parse->dir == '0')
		error("PLayer is missing", head);
	if (head->parse->error == 0)
		return (1);
	return (0);
}

void	format_res(t_head *head)
{
	if (head->map->res_x < 100)
		head->map->res_x = 100;
	if (head->map->res_y < 100)
		head->map->res_y = 100;
}

int	treat_resolution(t_head *head, char *line, char **argv)
{
	int	i;

	i = 1;
	if (res_error(line) != 1 || (head->parse->res == 1))
	{
		free(line);
		return (parse_error(7, argv, head));
	}
	head->map->res_x = 0;
	head->map->res_y = 0;
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
		head->map->res_x = (head->map->res_x * 10 + (line[i++] - 48));
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
		head->map->res_y = (head->map->res_y * 10 + line[i++] - 48);
	format_res(head);
	head->parse->res = 1;
	free(line);
	line = NULL;
	head->horizon = head->res_y * 0.5;
	return (1);
}

void	treat_line(t_head *head, char **path, char *line, t_list **map)
{
	int		i;

	i = 0;
	while (head->parse->map == -1 && line[i] == ' ')
		i++;
	if (ft_strncmp("R", line + i, 1) == 0 && head->parse->map == -1)
		treat_resolution(head, line, path);
	else if (ft_strncmp("NO", line + i, 2) == 0 && head->parse->map == -1)
		treat_texture(head, line, 1);
	else if (ft_strncmp("SO", line + i, 2) == 0 && head->parse->map == -1)
		treat_texture(head, line, 2);
	else if (ft_strncmp("WE", line + i, 2) == 0 && head->parse->map == -1)
		treat_texture(head, line, 3);
	else if (ft_strncmp("EA", line + i, 2) == 0 && head->parse->map == -1)
		treat_texture(head, line, 4);
	else if (ft_strncmp("S", line + i, 1) == 0 && head->parse->map == -1)
		treat_texture(head, line, 5);
	else if (head->parse->map == 0 || valid_map_line(line, head))
		treat_map(head, line, map);
	else if (ft_strncmp("F", line + i, 1) == 0 && head->parse->map == -1)
		treat_fc(head, line, 6);
	else if (ft_strncmp("C", line + i, 1) == 0 && head->parse->map == -1)
		treat_fc(head, line, 7);
	else
		treat_invalid_line(line, head);
}

int	ft_parse(t_head *head, char **path)
{
	int		fd;
	char	*line;
	int		res;
	t_list	*map;

	map = NULL;
	res = 1;
	fd = open(path[1], O_RDONLY);
	if (fd == -1)
		return (parse_error(6, path, head));
	while (res > 0)
	{
		res = get_next_line(fd, &line);
		if (res > 0)
			treat_line(head, path, line, &map);
	}
	if (res == -1)
		return (parse_error(9, path, head));
	treat_line(head, path, line, &map);
	close(fd);
	head->map->map = store_map(head, map);
	ft_lstclear(&map, &del, 0);
	if (valid_parse(head) && valid_map(head))
		return (1);
	return (0);
}
