/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hud_tex_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:01:21 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/29 17:52:19 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	lifes_bar_3(t_cub *cub)
{
	char	*life_1;

	cub->i_t = 12;
	life_1 = "./textures/catacomb/life/life_1.xpm";
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(cub->mlx_ptr,
	life_1, &cub->tex[cub->i_t]->tex_width, &cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
}

void	lifes_bar_2(t_cub *cub)
{
	char	*life_3;
	char	*life_2;

	cub->i_t = 10;
	life_3 = "./textures/catacomb/life/life_3.xpm";
	life_2 = "./textures/catacomb/life/life_2.xpm";
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(cub->mlx_ptr,
	life_3, &cub->tex[cub->i_t]->tex_width, &cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	cub->i_t = 11;
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(cub->mlx_ptr,
	life_2, &cub->tex[cub->i_t]->tex_width, &cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
}

void	lifes_bar(t_cub *cub)
{
	char	*life_5;
	char	*life_4;

	cub->i_t = 8;
	life_5 = "./textures/catacomb/life/life_full.xpm";
	life_4 = "./textures/catacomb/life/life_4.xpm";
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(cub->mlx_ptr,
	life_5, &cub->tex[cub->i_t]->tex_width, &cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	cub->i_t = 9;
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(cub->mlx_ptr,
	life_4, &cub->tex[cub->i_t]->tex_width, &cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
}

void	score_and_game_over(t_cub *cub)
{
	char	*scoreframe;
	char	*gameover;

	cub->i_t = 7;
	scoreframe = "./textures/catacomb/scoreframe.xpm";
	gameover = "./textures/catacomb/gameover.xpm";
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(cub->mlx_ptr,
	scoreframe, &cub->tex[cub->i_t]->tex_width,
	&cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	cub->i_t = 13;
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(
	cub->mlx_ptr, gameover, &cub->tex[cub->i_t]->tex_width,
	&cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
}

void	hud_textures(t_cub *cub)
{
	score_and_game_over(cub);
	lifes_bar(cub);
	lifes_bar_2(cub);
	lifes_bar_3(cub);
}
