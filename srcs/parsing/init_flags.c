/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:12:17 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/13 09:18:21 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_control(t_head *head)
{
	head->control.w = 0;
	head->control.s = 0;
	head->control.a = 0;
	head->control.d = 0;
	head->control.up = 0;
	head->control.down = 0;
	head->control.left = 0;
	head->control.right = 0;
	head->control.space = 0;
	head->control.shoot = 0;
	head->control.alt = 0;
	head->control.sit = 0;
	head->control.up_down = 0;
	head->control.run = 0;
	head->control.screenshot = 0;
	head->control.launch = 0;
	head->dt.str_dt = NULL;
}

void	init_head(t_head *head, t_map *map, t_text *text, t_parse *parse)
{
	head->map = map;
	head->text = text;
	head->parse = parse;
	head->win = NULL;
	head->mlx = NULL;
	head->vec_tab = NULL;
	head->cam_dist = 0.0;
	head->res_x = 0;
	head->i = 0;
	head->size_x = 0;
	head->size_y = 0;
	head->vector = 0.0;
	head->plan = 0.0;
	head->max_y = 0;
	head->speed = 1.0;
	head->dead = 0;
	head->bonk = 0;
	head->stack_time = 0.0;
	head->attack = 0;
	head->tower = 0;
	head->explode = 0;
	head->door = 0;
	head->secret_door = 0;
}

void	init_parse(t_parse *parse)
{
	parse->res = 0;
	parse->so = 0;
	parse->no = 0;
	parse->we = 0;
	parse->ea = 0;
	parse->s = 0;
	parse->dir = '0';
	parse->map = -1;
	parse->error = 0;
	parse->save = NULL;
}

void	init_texture(t_text *text)
{
	text->no = NULL;
	text->so = NULL;
	text->we = NULL;
	text->ea = NULL;
	text->s = NULL;
	text->top = NULL;
	text->bottom = NULL;
	text->right = NULL;
	text->left = NULL;
	text->sprite = NULL;
	text->f_r = 0;
	text->f_g = 0;
	text->f_b = 0;
	text->c_r = 0;
	text->c_g = 0;
	text->c_b = 0;
	text->f = 0;
	text->c = 0;
}

void	init_map(t_map *map)
{
	map->res_x = -1;
	map->res_y = -1;
	map->map = NULL;
	map->len = 0;
	map->player_y = 0.0;
	map->player_x = 0.0;
	map->max_y = 0;
	map->max_x = 0;
	map->min_y = 0;
	map->min_x = 0;
	map->sprite = NULL;
	map->top = NULL;
	map->bottom = NULL;
	map->right = NULL;
	map->left = NULL;
	map->tab_bottom = NULL;
	map->tab_top = NULL;
	map->tab_left = NULL;
	map->tab_right = NULL;
}
