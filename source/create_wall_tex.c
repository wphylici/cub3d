/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_wall_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:23:33 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/29 18:07:05 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	side_no(t_cub *cub)
{
	cub->i_t = 0;
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(cub->mlx_ptr,
	cub->tex_no, &cub->tex[cub->i_t]->tex_width,
	&cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	make_reverse_array(cub);
}

void	side_so(t_cub *cub)
{
	cub->i_t = 1;
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(cub->mlx_ptr,
	cub->tex_so, &cub->tex[cub->i_t]->tex_width,
	&cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	make_array(cub);
}

void	side_we(t_cub *cub)
{
	cub->i_t = 2;
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(
	cub->mlx_ptr, cub->tex_we, &cub->tex[cub->i_t]->tex_width,
	&cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\n\nError\nMlx function problem\n", EXIT_FAILURE);
	make_reverse_array(cub);
}

void	side_ea(t_cub *cub)
{
	cub->i_t = 3;
	if (!(cub->tex[cub->i_t]->tex_img = mlx_xpm_file_to_image(cub->mlx_ptr,
	cub->tex_ea, &cub->tex[cub->i_t]->tex_width,
	&cub->tex[cub->i_t]->tex_height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->tex[cub->i_t]->tex_addr = (int *)mlx_get_data_addr(
	cub->tex[cub->i_t]->tex_img, &cub->tex[cub->i_t]->tex_bpp,
	&cub->tex[cub->i_t]->tex_line_s, &cub->tex[cub->i_t]->tex_endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	make_array(cub);
}

void	wall_textures(t_cub *cub)
{
	side_no(cub);
	side_so(cub);
	side_we(cub);
	side_ea(cub);
}
