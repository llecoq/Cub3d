/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:10:15 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 09:56:50 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init(t_head *head, t_map *map, t_text *text, t_parse *parse)
{
	init_parse(parse);
	init_map(map);
	init_texture(text);
	init_head(head, map, text, parse);
	init_control(head);
}

int	treat_arg(t_head *head, int argc, char **argv)
{
	int	i;

	if (argc > 1)
		i = ft_strlen(argv[1]);
	if (argc < 2)
		return (2);
	if (argc == 2)
	{
		if ((ft_strncmp(".cub", argv[1] + i - 4, 4)) != 0)
			return (3);
		return (1);
	}
	if (argc == 3)
	{
		if ((ft_strncmp(".cub", argv[1] + i - 4, 4)) != 0)
			return (3);
		i = ft_strlen(argv[2]);
		if (i != 6 || (ft_strncmp("--save", argv[2], 6) != 0))
			return (4);
		head->parse->save = "screenshot.bmp";
	}
	if (argc > 3)
		return (5);
	return (1);
}

int	main(int argc, char **argv)
{
	t_head	head;
	t_map	map;
	t_text	texture;
	t_parse	parse;

	ft_init(&head, &map, &texture, &parse);
	if (treat_arg(&head, argc, argv) != 1)
		return (parse_error(treat_arg(&head, argc, argv), argv, &head));
	if (!(ft_parse(&head, argv)))
		return (ft_clear_memory(&head));
	cub3d(&head);
	ft_clear_memory(&head);
	return (0);
}
