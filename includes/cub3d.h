/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:18:59 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/14 14:05:51 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <errno.h>
# include <sys/time.h>
# include <fcntl.h>
# include <pthread.h>
# include "struct.h"
# include "./minilibx/mlx.h"
# include "../libft/libft.h"

# define DESTROY 53
# define UP 125
# define DOWN 126
# define LEFT 123
# define RIGHT 124
# define RUN 269
# define SCREEN 105
# define W 13
# define S 1
# define A 0
# define D 2
# define SHIFT 257
# define ALT 261
# define SHOOT 82
# define RATIO 0.6
# define SPACE 49
# define	IMG_BPP 32
# define	LAUNCH 14

# define NB_THREADS 8

/* INIT FLAGS */
void		ft_init(t_head *head, t_map *map, t_text *text, t_parse *parse);
void		init_head(t_head *head, t_map *map, t_text *text, t_parse *parse);
void		init_parse(t_parse *parse);
void		init_texture(t_text *text);
void		init_map(t_map *map);
void		init_map_max(t_head *head);
void		init_control(t_head *head);

/* PARSING */
int			ft_parse(t_head *head, char **path);
int			valid_parse(t_head *head);
int			treat_fc(t_head *head, char *line, int n);
int			treat_map(t_head *head, char *line, t_list **map);
int			valid_map(t_head *head);
int			valid_map_line(char *line, t_head *head);
int			treat_resolution(t_head *head, char *line, char **argv);
int			treat_texture(t_head *head, char *line, int n);
void		treat_line(t_head *head, char **path, char *line, t_list **map);
void		flood(int x, int y, char **copy, t_head *head);
void		format_res(t_head *head);
void		treat_invalid_line(char *line, t_head *head);

/* GRAPHIC */
int			cub3d(t_head *head);
int			update(t_head *head);
void		multi_threads(t_head *head);
void		find_sky(t_threads *thread, t_vec *vec);
void		*ray_casting(void *arg);
void		find_top_plan(t_threads *thread, t_vec *vec);
void		find_bottom_plan(t_threads *thread, t_vec *vec);
void		find_right_plan(t_threads *thread, t_vec *vec);
void		find_left_plan(t_threads *thread, t_vec *vec);
void		draw_image(t_threads *p, int i);
void		draw_top_wall(t_threads *p, int y, int i, int width);
void		draw_bottom_wall(t_threads *p, int y, int i, int width);
void		draw_floor(t_threads *p, int i, int *data);
void		draw_ceiling(t_threads *p, int i, int *data);
void		draw_sprite(t_threads *p, t_sprite **sprite, int horizon, int i);
void		init_vectors(t_head *head, int width);
void		draw_weapon(t_head *head, int k);
void		bonk(t_head *head);
void		data_sprite(t_threads *p, t_sprite *sprite, int n, int i);
void		data_tower(t_threads *p, t_sprite *sprite, int i);
void		data_killer_penguin(t_threads *p, t_sprite *sprite);
void		explode(t_threads *thread);
void		life(t_head *head);
void		u_dead(t_head *head);
void		u_win(t_head *head);
void		hurt(t_head *head);
void		life_death(t_head *head);

/* CALCULS */
t_vec		player_rotation(t_head *head, t_vec vec);
void		get_sprite_plan(t_threads *thread);
void		plan_sprite(t_sprite *sprite, t_vec *vec, t_head *head);
void		find_sprite(t_threads *p, t_vec *vec, t_sprite **sprite);
void		store_t(t_threads *thread, double t, int n, char c);
double		vector_equation_sprite(t_vec *vec, t_sprite *p);
double		plan_equation_sprite(t_head *head, t_sprite *p);
double		vector_equation(t_vec *vec, t_plan *p);
double		plan_equation(t_head *head, t_plan *p);

/* LOAD TEXTURES */
int			load_texture(void *mlx, t_head *head);
void		*load_sprite(void *mlx, t_head *head, int n);
void		load_skybox(void *mlx, t_head *head, int i);
void		*load_hurt(void *mlx, t_head *head);
void		*load_life(void *mlx, t_head *head);
void		*load_dead(void *mlx, t_head *head);
void		*load_weapon(void *mlx, t_head *head);
void		*load_door(void *mlx, t_head *head);

/* STORE PLANS / SPRITES */
char		**store_map(t_head *head, t_list *map);
void		store_plan(int x, int y, char **copy, t_head *head);
void		store_sprite(t_head *head, t_sprite *sprite);
void		sort_sprite(t_sprite **sprite);
void		store_plan_tab(t_head *head, int y, int x);
void		store_plan(int x, int y, char **copy, t_head *head);

/* ERRORS */
int			error(char *str, t_head *head);
int			parse_error(int errnum, char **argv, t_head *head);
int			parse_error_map(int errnum, t_head *head);
int			res_error(char *line);

/* CLEAR MEMORY */
int			ft_clear_memory(t_head *head);
int			clear_tab(char **tab);
void		free_texture(t_text *text);
void		del(void *content);
void		ft_lstclear_sprite(t_sprite *sprite);
void		ft_lstclear_plan(t_plan *plan);
void		clear_vec_tab(t_head *head);
void		clear_sprite(t_sprite ***sprite);
void		clear_tab_plan(t_head *head);
void		clear_plan(t_plan **plan, int i);
size_t		ft_strlen_tab(char **tab);

/* COMMANDS */
int			key_press(int keypress, void *structure);
int			key_release(int keypress, void *structure);
int			red_cross(void *structure);
void		key_hook(t_head *head);
void		ft_control(t_head *head);
void		forward(t_head *head);
void		backward(t_head *head);
void		right(t_head *head);
void		left(t_head *head);
void		sit(t_head *head, int n);
void		open_door(t_head *head);
void		open_secret_door(t_head *head);
void		close_door(t_head *head);
void		close_secret_door(t_head *head);
void		jump(t_head *head);
void		screenshot(t_head *head);

/* UTILS */
int			valid_x_y(t_threads *thread);
int			valid_wall(char c);
int			save_bmp(t_head *head, char *name);
int			data(t_threads *p, int *text, int height);
int			inter(char c, char *old);
int			*data_sky(t_threads *p, int i);
int			data_door(t_threads *p);
t_vec		*new_vec(double x, double y);
t_vec		**ft_calloc_vec(t_vec ***ptr, size_t count, size_t size);
t_plan		**ft_calloc_plan(t_plan ***ptr, size_t count, size_t size);
t_plan		*new_plan(double a, double b, double d);
t_sprite	*ft_lstnew_sprite(double x, double y, int n);
t_sprite	***copy_sprite_tab(t_head *head, t_sprite **sprite, int i);
void		plan_add_front(t_plan **alst, t_plan *new);
void		delta_time(t_head *head);
void		sort_plan(t_plan *alst);
void		asort_plan(t_plan *alst);
void		map_max(t_head *head, char c, int x, int y);
char		**copy_tab(char **tab, t_head *head);

#endif