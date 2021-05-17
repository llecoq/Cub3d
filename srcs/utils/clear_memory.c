/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:32:46 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/14 14:06:39 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_texture(t_text *text)
{
	system("killall afplay");
	if (text->no)
		free(text->no);
	if (text->so)
		free(text->so);
	if (text->we)
		free(text->we);
	if (text->ea)
		free(text->ea);
	if (text->s)
		free(text->s);
}

void	clear_vec_tab(t_head *head)
{
	head->i = -1;
	while (head->vec_tab[++head->i])
		free(head->vec_tab[head->i]);
	free(head->vec_tab);
}

void	clear_sprite(t_sprite ***sprite)
{
	int	i;
	int	j;

	i = -1;
	while (sprite[++i])
	{
		j = -1;
		while (sprite[i][++j])
			free(sprite[i][j]);
		free(sprite[i]);
	}
	free(sprite);
}

void	clear_skybox(t_head *head)
{
	int	i;

	i = -1;
	if (head->map->skybox)
	{
		while (head->map->skybox[++i])
			free(head->map->skybox[i]);
		free(head->map->skybox);
	}
}

int	ft_clear_memory(t_head *head)
{
	free_texture(head->text);
	if (head->map->map)
		clear_tab(head->map->map);
	if (head->map->sprite)
		ft_lstclear_sprite(head->map->sprite);
	if (head->map->top)
		ft_lstclear_plan(head->map->top);
	if (head->map->bottom)
		ft_lstclear_plan(head->map->bottom);
	if (head->map->right)
		ft_lstclear_plan(head->map->right);
	if (head->map->left)
		ft_lstclear_plan(head->map->left);
	if (head->vec_tab)
		clear_vec_tab(head);
	if (head->sprite_tab)
		free(head->sprite_tab);
	if (head->sprite)
		clear_sprite(head->sprite);
	if (head->map->skybox)
		clear_skybox(head);
	if (head->dt.str_dt)
		free(head->dt.str_dt);
	clear_tab_plan(head);
	return (1);
}
