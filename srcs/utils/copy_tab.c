/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:38:34 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/13 19:08:02 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_sprite	*sprite_dup(t_head *head, t_sprite *sprite)
{
	t_sprite	*dst;

	dst = calloc(1, sizeof(t_sprite));
	if (!dst)
		if (ft_clear_memory(head))
			exit (0);
	dst->x = sprite->x;
	dst->y = sprite->y;
	dst->sprite = sprite->sprite;
	dst->next = sprite->next;
	dst->previous = sprite->previous;
	return (dst);
}

t_sprite	**sprite_tab_dup(t_head *head, t_sprite **sprite, int i)
{
	t_sprite	**dst;
	int			j;

	dst = calloc(i + 1, sizeof(t_sprite *));
	if (!dst)
		if (ft_clear_memory(head))
			exit (0);
	j = -1;
	while (sprite[++j])
		dst[j] = sprite_dup(head, sprite[j]);
	return (dst);
}

t_sprite	***copy_sprite_tab(t_head *head, t_sprite **sprite, int i)
{
	int			j;
	t_sprite	***dst;

	dst = calloc(NB_THREADS + 1, sizeof(t_sprite **));
	if (!dst)
		if (ft_clear_memory(head))
			exit (0);
	j = -1;
	while (++j < NB_THREADS)
		dst[j] = sprite_tab_dup(head, sprite, i);
	return (dst);
}

char	**store_map(t_head *head, t_list *map)
{
	char	**result;
	int		y;

	if (!ft_calloc_map(&result, head->map->len, sizeof(char *)))
		return (NULL);
	y = 0;
	while (map)
	{
		result[y] = map->content;
		y++;
		map = map->next;
	}
	return (result);
}

char	**copy_tab(char **tab, t_head *head)
{
	char	**dst;
	int		i;

	i = 0;
	if (!ft_calloc_map(&dst, head->map->len, sizeof(char *)))
		return (NULL);
	while (i < head->map->len)
	{
		dst[i] = ft_strdup(tab[i]);
		i++;
	}
	return (dst);
}
