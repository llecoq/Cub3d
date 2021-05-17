/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:40:37 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/14 13:46:51 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_control_2(t_head *head)
{
	if (head->map->map[(int)head->map->player_y][(int)head->map->player_x]
		== '5'
		&& head->attack != 3)
		hurt(head);
	else if (head->map->map[(int)head->map->player_y][(int)head->map->player_x]
		!= '5'
		&& head->attack != 3)
		head->attack = 0;
	if (head->control.alt && head->secret_door == 0)
		open_secret_door(head);
	if (head->control.alt && head->door == 0)
		open_door(head);
	else if (head->control.alt && head->door)
		close_door(head);
	if (head->control.sit == 1)
		sit(head, head->control.up_down);
	head->control.alt = 0;
	if (head->control.shoot == 1 && head->stack_time < 0.05)
		system("afplay ./assets/sound/quack.mp3 &");
	bonk(head);
}

void	ft_control(t_head *head)
{
	if (head->control.right)
		head->player_dir += 0.04 * head->speed;
	if (head->control.left)
		head->player_dir -= 0.04 * head->speed;
	if (head->control.down && head->horizon + 50 * head->speed < head->res_y)
		head->horizon += 50 * head->speed;
	if (head->control.up && head->horizon - 50 * head->speed > 0)
		head->horizon -= 50 * head->speed;
	if (head->control.a)
		left(head);
	if (head->control.w)
		forward(head);
	if (head->control.s)
		backward(head);
	if (head->control.d)
		right(head);
	if (head->control.space)
		jump(head);
	ft_control_2(head);
}
