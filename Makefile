# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 17:05:54 by llecoq            #+#    #+#              #
#    Updated: 2021/05/14 14:06:23 by llecoq           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME =      Cub3D
LIB  =      ./libft
MLX  =      ./includes/minilibx/
OBJ_PATH =	./objs/

SRCS			=	srcs/utils/clear_memory.c srcs/parsing/map_check.c\
					srcs/parsing/error.c srcs/parsing/init_flags.c\
					srcs/parsing/parsing.c srcs/parsing/texture.c\
					srcs/parsing/color_fc.c srcs/graphic/find_valid.c\
					srcs/main.c srcs/utils/copy_tab.c srcs/utils/inter_map.c\
					srcs/graphic/cub3d.c srcs/parsing/store_sprite.c\
					srcs/graphic/load_texture.c srcs/utils/list_plan.c\
					srcs/parsing/store_plan.c srcs/utils/ft_calloc_plan.c\
					srcs/commands/key_press.c srcs/graphic/ray_casting.c\
					srcs/graphic/find_plan.c srcs/utils/calculs.c\
					srcs/graphic/draw_image.c srcs/utils/frame_rate.c\
					srcs/graphic/find_sprite.c srcs/graphic/draw_sprite.c\
					srcs/graphic/find_sky.c srcs/graphic/life_death.c\
					srcs/utils/save_bmp.c srcs/graphic/bonk.c\
					srcs/commands/move.c srcs/commands/actions.c\
					srcs/commands/control.c srcs/utils/clear_lst.c\
					srcs/utils/utils.c srcs/graphic/draw_texture.c\
					srcs/graphic/data_sprite.c srcs/graphic/load_weapon.c\
					srcs/graphic/load_skybox.c srcs/graphic/load_sprite.c\
					srcs/graphic/get_sprite_plan.c
					
CC = gcc -Ofast -flto -march=native -ffast-math -g3 -fsanitize=address

CFLAGS =   -Wall -Wextra -Werror

INCLUDES =  includes

OBJS =      $(SRCS:.c=.o)

%.o: %.c includes/cub3d.h libft/libft.h
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)

all :       $(NAME)

$(NAME):    $(OBJS)
			$(MAKE) -C $(LIB)
			$(MAKE) -C $(MLX)
			cp includes/minilibx/libmlx.dylib .
			@$(CC) -o $(NAME) $(OBJS) -I $(INCLUDES) libft/libft.a -Lmlx -lmlx -lm

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
						@mkdir $(OBJ_PATH) 2> /dev/null || true
						@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<

clean :
		rm -rf $(OBJS)
		$(MAKE) clean -C $(LIB)
		$(MAKE) clean -C $(MLX)
fclean :    clean
			$(MAKE) fclean -C $(LIB)
			rm -f libmlx.dylib
			rm -f $(NAME)
re : fclean all
norme:
			@norminette $(SRCS) $(INCLUDES)
			@echo "\033[1;34mcub3d\t\033[1;33mNorminette\t\033[0;32m[OK]\033[0m"
			$(MAKE) norme -C ./libft
.PHONY : re all clean fclean norme
