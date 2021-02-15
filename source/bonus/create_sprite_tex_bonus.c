/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprite_tex_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:39:40 by wphylici          #+#    #+#             */
/*   Updated: 2020/11/02 04:29:13 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	bonus_sprite1(t_cub *cub)
{
	char	*collumn;

	cub->i_t = 14;
	collumn = "./textures/catacomb/coll.xpm";
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(cub->mlx_ptr,
	collumn, &cub->tex[cub->i_t]->tex_width, &cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	make_array(cub);
}

void	bonus_sprite(t_cub *cub)
{
	char	*b_sprite;
	char	*coin_sprite;

	cub->i_t = 5;
	b_sprite = "./textures/catacomb/shar_bzz.xpm";
	coin_sprite = "./textures/catacomb/coin.xpm";
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(cub->mlx_ptr,
	b_sprite, &cub->tex[cub->i_t]->tex_width, &cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	make_array(cub);
	cub->i_t = 6;
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(cub->mlx_ptr,
	coin_sprite, &cub->tex[cub->i_t]->tex_width,
	&cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	make_array(cub);
}

void	sprite_textures(t_cub *cub)
{
	cub->i_t = 4;
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(cub->mlx_ptr,
	cub->tex_s, &cub->tex[cub->i_t]->tex_width,
	&cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	make_array(cub);
	bonus_sprite(cub);
	bonus_sprite1(cub);
}
