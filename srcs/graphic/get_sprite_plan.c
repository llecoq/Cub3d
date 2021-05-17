/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_plan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:26:03 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 09:55:38 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	swap(t_sprite **sprite, t_sprite *temp, int i, int j)
{
	temp = sprite[i];
	sprite[i] = sprite[j];
	sprite[j] = temp;
}

void	sort_sprite(t_sprite **sprite)
{
	int			i;
	int			j;
	t_sprite	*temp;

	temp = NULL;
	i = -1;
	while (sprite[++i])
	{
		j = -1;
		while (sprite[++j])
			if (sprite[j]->d > sprite[i]->d)
				swap(sprite, temp, i, j);
	}
}

void	plan_sprite(t_sprite *sprite, t_vec *vec, t_head *head)
{
	t_vec		new_vec;

	new_vec = player_rotation(head, *vec);
	while (sprite)
	{
		sprite->a = new_vec.x;
		sprite->b = new_vec.y;
		sprite->d = - (sprite->a * sprite->x + sprite->b * sprite->y);
		sprite = sprite->next;
	}
	sort_sprite(head->sprite_tab);
}

void	get_sprite_plan(t_threads *thread)
{
	int	i;

	i = -1;
	while (thread->sprite[++i])
	{
		thread->sprite[i]->x = thread->head->sprite_tab[i]->x;
		thread->sprite[i]->y = thread->head->sprite_tab[i]->y;
		thread->sprite[i]->a = thread->head->sprite_tab[i]->a;
		thread->sprite[i]->b = thread->head->sprite_tab[i]->b;
		thread->sprite[i]->d = thread->head->sprite_tab[i]->d;
		thread->sprite[i]->t = thread->head->sprite_tab[i]->t;
		thread->sprite[i]->sprite = thread->head->sprite_tab[i]->sprite;
		thread->sprite[i]->next = thread->head->sprite_tab[i]->next;
		thread->sprite[i]->previous = thread->head->sprite_tab[i]->previous;
	}
	if (thread->head->player_dir < 0)
		thread->head->player_dir += (2 * M_PI);
	if (thread->head->player_dir > (2 * M_PI))
		thread->head->player_dir -= (2 * M_PI);
}
