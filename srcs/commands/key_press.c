/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:41:06 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/11 16:24:30 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_2(t_head *head, int keypress)
{
	if (keypress == D)
		head->control.d = 1;
	if (keypress == SPACE)
	{
		head->control.space = 1;
		head->control.count = 0.0;
		head->control.reverse = 0;
	}
	if (keypress == SHOOT)
		head->control.shoot = 1;
	if (keypress == ALT)
		head->control.alt = 1;
	if (keypress == SHIFT)
		head->control.sit = 1;
	if (keypress == RUN)
		head->control.run = 1;
	if (keypress == SCREEN)
		screenshot(head);
	if (keypress == LAUNCH)
		head->control.launch = 1;
	return (0);
}

int	key_press(int keypress, void *structure)
{
	t_head	*head;

	head = (t_head *)structure;
	if (keypress == DESTROY)
		if (!mlx_destroy_window(head->mlx, head->win))
			if (ft_clear_memory(head))
				exit (0);
	if (keypress == RIGHT)
		head->control.right = 1;
	if (keypress == LEFT)
		head->control.left = 1;
	if (keypress == DOWN)
		head->control.down = 1;
	if (keypress == UP)
		head->control.up = 1;
	if (keypress == W)
		head->control.w = 1;
	if (keypress == A)
		head->control.a = 1;
	if (keypress == S)
		head->control.s = 1;
	key_press_2(head, keypress);
	return (0);
}

int	key_release_2(t_head *head, int keypress)
{
	if (keypress == ALT)
		head->control.alt = 0;
	if (keypress == RUN)
		head->control.run = 0;
	if (keypress == LAUNCH)
		head->control.launch = 0;
	return (0);
}

int	key_release(int keypress, void *structure)
{
	t_head	*head;

	head = (t_head *)structure;
	if (keypress == RIGHT)
		head->control.right = 0;
	if (keypress == LEFT)
		head->control.left = 0;
	if (keypress == DOWN)
		head->control.down = 0;
	if (keypress == UP)
		head->control.up = 0;
	if (keypress == W)
		head->control.w = 0;
	if (keypress == A)
		head->control.a = 0;
	if (keypress == S)
		head->control.s = 0;
	if (keypress == D)
		head->control.d = 0;
	key_release_2(head, keypress);
	return (0);
}

void	key_hook(t_head *head)
{
	mlx_hook(head->win, 2, (1L <<0), key_press, head);
	mlx_hook(head->win, 3, (1L <<1), key_release, head);
	mlx_hook(head->win, 17, (1L <<5), red_cross, head);
}
