/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprite_tex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:39:40 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/29 18:06:40 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
}
