/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_rate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:14:39 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/11 18:20:17 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	shoot(t_head *head)
{
	if (head->control.shoot == 1)
		head->stack_time += head->dt.dt;
	if (head->control.shoot == 2)
		head->stack_time -= head->dt.dt;
	if (head->control.shoot == 2 && head->stack_time <= 0.0)
	{
		head->control.shoot = 0;
		head->stack_time = 0.0;
	}
}

void	delta_time(t_head *head)
{
	struct timeval	time;
	long int		time_end;
	float			speed;

	gettimeofday(&time, NULL);
	time_end = time.tv_sec * 1000000 + time.tv_usec;
	if (head->dt.time_mem > 0)
		head->dt.dt = (time_end - head->dt.time_mem) * 0.000001;
	head->dt.time_mem = time_end;
	if (head->dt.dt)
	{
		speed = 1 / head->dt.dt;
		head->dt.str_dt = ft_itoa(speed);
		head->speed = 35 / speed;
		shoot(head);
		if (head->control.up_down)
			head->speed *= 0.5;
		if (head->control.run == 1)
			head->speed *= 1.7;
	}
}
