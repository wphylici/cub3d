/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 03:15:26 by wphylici          #+#    #+#             */
/*   Updated: 2020/11/02 03:36:40 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../source/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>

# define PI 3.14159265
# define SCALE 64
# define SPEED SCALE * 0.1

typedef struct			s_sprites
{
	int					x;
	int					y;
	float				dist;
	float				sprite_h;
	float				sprite_angle;
	float				sprite_x;
	float				sprite_y;
	float				s_scale;
	struct s_sprites	*next;
}						t_sprites;

typedef struct			s_tex
{
	char				*tex_img;
	int					tex_width;
	int					tex_height;
	int					tex_bpp;
	int					tex_line_s;
	int					tex_endian;
	int					*tex_addr;
	int					tex_x;
	int					tex_y;
	int					**tex_array;
	float				tex_scale;
}						t_tex;

typedef struct			s_key
{
	int					forward;
	int					back;
	int					left;
	int					right;
	int					turn_left;
	int					turn_right;
	int					down;
	int					up;
}						t_key;

typedef struct			s_plr
{
	float				plr_x;
	float				plr_y;
	float				pov;
	float				fov;
	float				plr_map_x;
	float				plr_map_y;
}						t_plr;

typedef struct			s_map
{
	int					map_x;
	int					map_y;
	int					map_max_x;
	int					map_max_y;
	char				**map;
}						t_map;

typedef struct			s_cub
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int					width;
	int					height;
	int					clr_f;
	int					clr_c;
	int					clr_f_flag;
	int					clr_c_flag;
	char				*tex_no;
	char				*tex_so;
	char				*tex_we;
	char				*tex_ea;
	char				*tex_s;
	float				*all_dist;
	char				*map_str;
	float				line_x;
	int					color;
	int					i_t;
	int					offset_x;
	int					offset_y;
	int					save;
	t_tex				**tex;
	t_map				*map;
	t_plr				*plr;
	t_key				*key;
	t_sprites			*sprites;
}						t_cub;

/*
**						parser
*/

void					parser(t_cub *cub, char *name);
int						ft_resol(t_cub *cub, char *line);
int						ft_texture(t_cub *cub, char *line);
int						ft_color(t_cub *cub, char *line);
int						ft_map(t_cub *cub, char *line);
void					check_content_map(t_cub *cub);
int						create_map(t_cub *cub);
void					route_and_location(t_cub *cub);
void					lstnew_sprite(t_cub *cub, int y, int x);
int						map_ver(t_map *map, int y, int x, char c);
int						map_hor(t_map *map, int y, int x, char c);
int						check_map_symbol(t_map *cub);
int						valid_sym(t_map *map, int y, int x);
int						valid_sym1(t_map *map, int y, int x);
void					check_init(t_cub *cub);

/*
**						draw projection
*/

void					raycast(t_cub *cub);
void					horiz_side(t_cub *cub, float dist_horiz,
												float curr_ray);
void					vert_side(t_cub *cub, float dist_vert, float curr_ray);
void					draw_all(t_cub *cub, float col_h, int y);
void					draw_wall_texture(t_cub *cub, float col_h, float y);

/*
**						textures
*/

void					make_array(t_cub *cub);
void					make_reverse_array(t_cub *cub);
void					wall_textures(t_cub *cub);
void					sprite_textures(t_cub *cub);
void					init_sprite(t_cub *cub);

/*
**						hook and movements
*/

int						key_press(int key, t_cub *cub);
int						key_releas(int key, t_cub *cub);
int						close_game();
void					move(t_cub *cub);
int						loop_manager(t_cub *cub);

/*
**						utils
*/

void					ft_bzero(void *s, size_t n);
void					ft_putendl(char const *s);
int						ft_digit_len(long n);
char					**ft_split(t_cub *cub, char const *s, char c);

/*
**						free destroy and exit
*/

void					my_exit(t_cub *cub, char *str, int status);
void					all_destroy(t_cub *cub);
void					all_free(t_cub *cub);
void					free_side(t_cub *cub);

/*
**						pixel colors
*/

void					my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
void					my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int						create_rgb(int r, int g, int b);

/*
**						screenshot
*/

void					search_save(t_cub *cub, int argc, char **argv);
void					bit_map_info_header(t_cub *cub, int fd,
												int size, int biplanes);
void					bit_map_file_header(int fd, int file_size,
														int offbits);
void					revers_info(t_cub *cub);

#endif
