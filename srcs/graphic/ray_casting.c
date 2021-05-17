/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:40:31 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 17:57:49 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	data_thread(t_threads *thread)
{
	thread->find_door = 0;
	thread->ratio_sky = 0;
	thread->t = 9999.9;
	thread->plan = 0;
}

void	store_t(t_threads *thread, double t, int n, char c)
{
	if (thread->find_door == 1)
		thread->find_door = 0;
	thread->p = thread->y;
	thread->t = t;
	thread->plan = n;
	if (c == '7')
		thread->find_door = 1;
}

void	*ray_casting(void *arg)
{
	t_vec		vec;
	t_threads	*thread;
	int			i;

	thread = (t_threads *)arg;
	get_sprite_plan(thread);
	i = thread->start - 1;
	while (++i < thread->end && i < thread->head->width)
	{
		vec = player_rotation(thread->head, *thread->head->vec_tab[i]);
		data_thread(thread);
		if (vec.x < 0)
			find_right_plan(thread, &vec);
		else if (vec.x > 0)
			find_left_plan(thread, &vec);
		if (vec.y < 0)
			find_bottom_plan(thread, &vec);
		else if (vec.y > 0)
			find_top_plan(thread, &vec);
		find_sky(thread, &vec);
		find_sprite(thread, &vec, thread->sprite);
		draw_image(thread, i);
	}
	pthread_exit(thread->id);
}

void	multi_threads(t_head *head)
{
	t_threads	threads[NB_THREADS];
	int			i;
	int			size;

	i = -1;
	size = head->width / NB_THREADS;
	while (++i < NB_THREADS)
	{
		threads[i].start = i * size;
		threads[i].end = (i + 1) * size;
		threads[i].head = head;
		threads[i].i = i;
		threads[i].sprite = head->sprite[i];
		pthread_create(&threads[i].id, NULL, ray_casting, &threads[i]);
	}
	i = -1;
	while (++i < NB_THREADS)
		pthread_join(threads[i].id, NULL);
}

int	update(t_head *head)
{
	if (head->dead < 100 && head->tower != 2)
	{
		delta_time(head);
		mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, head->win);
		mlx_sync(MLX_SYNC_IMAGE_WRITABLE, head->img);
		plan_sprite(head->map->sprite, head->vec_dir, head);
		ft_control(head);
		multi_threads(head);
		life(head);
		draw_weapon(head, head->bonk);
		if (head->dead >= 100 || head->tower == 2)
			life_death(head);
		mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, head->win);
		if (head->parse->save)
			if (save_bmp(head, head->parse->save))
				exit (0);
		mlx_put_image_to_window(head->mlx, head->win, head->img, 0, 0);
		if (head->dt.dt && head->dead != 100)
		{
			mlx_string_put(head->mlx, head->win, 10, 10, 5652, head->dt.str_dt);
			free (head->dt.str_dt);
			head->dt.str_dt = NULL;
		}
	}
	return (0);
}
