/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:33:02 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 12:47:42 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct s_save
{
	int				file_size;
	int				offset;
	int				header_size;
	int				planes;
	int				bpp;
	int				img_size;
}				t_save;

typedef struct s_control
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				w;
	int				a;
	int				s;
	int				d;
	int				space;
	int				reverse;
	int				shift;
	int				shoot;
	int				alt;
	int				sit;
	int				up_down;
	int				run;
	int				screenshot;
	int				launch;
	float			gravity;
	float			count;
}				t_control;

typedef struct s_dt
{
	float			dt;
	double			time_mem;
	char			*str_dt;
}				t_dt;

typedef struct s_sprite
{
	double			x;
	double			y;
	double			a;
	double			b;
	double			d;
	double			t;
	double			sx;
	double			sy;
	double			ratio;
	int				sprite;
	struct s_sprite	*next;
	struct s_sprite	*previous;
}				t_sprite;

typedef struct s_vec
{
	double			x;
	double			y;
}				t_vec;

typedef struct s_plan
{
	double			a;
	double			b;
	double			c;
	double			d;
	struct s_plan	*next;
	struct s_plan	*previous;
}				t_plan;

typedef struct s_parse
{
	int				res;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				s;
	int				map;
	int				error;
	char			dir;
	char			*save;
}				t_parse;

typedef struct s_map
{
	char		**map;
	int			res_x;
	int			res_y;
	int			len;
	double		player_y;
	double		player_x;
	int			max_y;
	int			max_x;
	int			min_y;
	int			min_x;
	t_sprite	*sprite;
	t_plan		*top;
	t_plan		*bottom;
	t_plan		*right;
	t_plan		*left;
	t_plan		**tab_top;
	t_plan		**tab_bottom;
	t_plan		**tab_right;
	t_plan		**tab_left;
	t_plan		**skybox;
}				t_map;

typedef struct s_text
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	void		*top;
	void		*bottom;
	void		*right;
	void		*left;
	void		*sprite;
	void		*sprite_2;
	void		*sprite_3;
	void		*dead;
	void		*weapon;
	void		*hurt;
	void		*life;
	void		*door;
	int			*hurt_data;
	int			f_r;
	int			f_g;
	int			f_b;
	int			c_r;
	int			c_g;
	int			c_b;
	int			f;
	int			c;
}				t_text;

typedef struct s_head
{
	t_map		*map;
	t_text		*text;
	t_parse		*parse;
	t_vec		**vec_tab;
	t_vec		*vec_dir;
	t_dt		dt;
	t_control	control;
	t_sprite	**sprite_tab;
	t_sprite	***sprite;
	void		*win;
	void		*mlx;
	void		*img;
	void		*img_dead;
	void		*img_door;
	void		*img_weapon;
	void		*img_top;
	void		*img_bottom;
	void		*img_right;
	void		*img_left;
	void		*img_life;
	void		*img_sprite;
	void		*img_sprite_2;
	void		*img_sprite_3;
	void		*sky_0;
	void		*sky_1;
	void		*sky_2;
	void		*sky_3;
	void		*life;
	double		cam_dist;
	double		player_dir;
	double		x;
	double		y;
	double		vector;
	double		stack_time;
	float		speed;
	int			*data;
	int			*data_top;
	int			*data_bottom;
	int			*data_right;
	int			*data_left;
	int			*data_sprite;
	int			*data_sprite_2;
	int			*data_sprite_3;
	int			*data_dead;
	int			*data_weapon;
	int			*data_sky_0;
	int			*data_sky_1;
	int			*data_sky_2;
	int			*data_sky_3;
	int			*data_life;
	int			*data_door;
	int			width;
	int			width_top;
	int			width_door;
	int			width_top_data;
	int			width_bottom;
	int			width_bottom_data;
	int			width_life_data;
	int			width_door_data;
	int			width_left;
	int			width_left_data;
	int			width_right;
	int			width_right_data;
	int			width_sprite;
	int			width_sprite_2;
	int			width_sprite_3;
	int			width_sky;
	int			width_dead;
	int			width_weapon_data;
	int			width_weapon;
	int			width_life;
	int			width_sprite_data;
	int			width_sprite_data_2;
	int			width_sprite_data_3;
	int			width_life_data_3;
	int			width_dead_data;
	int			width_sky_data;
	int			height_sky;
	int			height_top;
	int			height_bottom;
	int			height_left;
	int			height_right;
	int			height_sprite;
	int			height_sprite_2;
	int			height_sprite_3;
	int			height_life;
	int			height_dead;
	int			height_weapon;
	int			height_door;
	int			res_x;
	int			res_y;
	int			i;
	int			plan;
	int			size_x;
	int			size_y;
	int			max_y;
	int			max_x;
	int			min_x;
	int			min_y;
	int			horizon;
	int			dead;
	int			bonk;
	int			attack;
	int			tower;
	int			explode;
	int			door;
	int			secret_door;
}				t_head;

typedef struct s_threads
{
	t_head		*head;
	pthread_t	id;
	t_sprite	**sprite;
	int			i;
	int			start;
	int			end;
	int			whole;
	int			height;
	int			height_text;
	int			height_sprite;
	int			height_sprite_2;
	int			*text;
	int			horizon;
	double		step;
	double		t;
	double		x;
	double		y;
	double		p;
	double		plan;
	double		vector;
	double		ratio;
	double		ratio_sky;
	int			width;
	int			width_sprite;
	int			find_door;
}				t_threads;

#endif
