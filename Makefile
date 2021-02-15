NAME =		cub3D

SRC =		./source/cub3d.c ./source/cub3d_utils.c \
			./source/movements.c ./source/ft_split.c \
			./source/sprites.c ./source/pixel_color.c \
			./source/raycast.c ./source/draw_wall.c \
			./source/draw_cl_flr.c ./source/hook.c ./source/map_parser.c \
			./source/map_validation.c ./source/map_validation_2.c \
			./source/resol_parser.c ./source/texture_parser.c \
			./source/control_parser.c ./source/free.c \
			./source/color_parser.c ./source/create_arr_tex.c \
			./source/create_sprite_tex.c ./source/create_wall_tex.c \
			./source/screenshot.c ./source/screenshot_utils.c\
			./source/get_next_line/get_next_line.c \
			./source/get_next_line/get_next_line_utils.c \

SRC_BONUS = ./source/bonus/cub3d_bonus.c ./source/bonus/cub3d_utils_bonus.c \
			./source/bonus/movements_bonus.c ./source/bonus/ft_split_bonus.c \
			./source/bonus/sprites_bonus.c ./source/bonus/pixel_color_bonus.c \
			./source/bonus/raycast_bonus.c ./source/bonus/draw_wall_bonus.c \
			./source/bonus/draw_cl_flr_bonus.c ./source/bonus/hook_bonus.c \
			./source/bonus/map_parser_bonus.c ./source/bonus/map_validation_bonus.c \
			./source/bonus/map_validation_2_bonus.c ./source/bonus/resol_parser_bonus.c \
			./source/bonus/texture_parser_bonus.c ./source/bonus/control_parser_bonus.c \
			./source/bonus/free_bonus.c ./source/bonus/color_parser_bonus.c \
			./source/bonus/create_arr_tex_bonus.c ./source/bonus/create_sprite_tex_bonus.c \
			./source/bonus/create_wall_tex_bonus.c ./source/bonus/create_hud_tex_bonus.c \
			./source/bonus/hud_bonus.c ./source/bonus/interactive_sprites_bonus.c \
			./source/bonus/minimap_bonus.c ./source/bonus/time_bonus.c \
			./source/bonus/screenshot_bonus.c ./source/bonus/screenshot_utils_bonus.c \
			./source/get_next_line/get_next_line.c ./source/get_next_line/get_next_line_utils.c \

FLAGS =		-Wall -Werror -Wextra

MLX =		-framework OpenGL -framework Appkit

HEADER =	cub3d.h

LIB_S = 	./mlx/libmlx.a

MAP =		./maps/map.cub

MAP_B =		./maps/e1m1.cub

OBJ = 		$(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@rm -rf $(NAME)
	@gcc $(FLAGS) $(OBJ) $(MLX) $(LIB_S) -o $(NAME)

bonus: $(OBJ_BONUS)
	@rm -rf $(NAME)
	@gcc $(FLAGS) $(OBJ_BONUS) $(MLX) $(LIB_S) -o $(NAME)

%.o: %.c $(HEADER)
	@gcc $(FLAGS) -c $< -o

run: all clean
	@./$(NAME) $(MAP)

runb: bonus clean
	@./$(NAME) $(MAP_B)

re: fclean all

reb: fclean bonus

de:
	@gcc -g $(FLAGS) $(MLX) $(SRC_BONUS) $(LIB_S)

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -rf $(NAME) screenshot.bmp
