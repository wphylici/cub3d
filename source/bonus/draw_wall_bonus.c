/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 04:03:16 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/29 17:35:46 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_wall_texture(t_cub *cub, float col_h, float y, float dist)
{
	while (cub->tex[cub->i_t]->tex_y < col_h)
	{
		if (cub->tex[cub->i_t]->tex_x < cub->tex[cub->i_t]->tex_width &&
		cub->tex[cub->i_t]->tex_y / cub->tex[cub->i_t]->tex_scale <
		cub->tex[cub->i_t]->tex_height)
			distance_shade(cub, cub->tex[cub->i_t]->tex_array[
			(int)(cub->tex[cub->i_t]->tex_y / cub->tex[cub->i_t]->tex_scale)]
			[cub->tex[cub->i_t]->tex_x], dist);
		my_mlx_pixel_put(cub, cub->line_x, y++, cub->color);
		cub->tex[cub->i_t]->tex_y++;
	}
	cub->tex[cub->i_t]->tex_x++;
}

void	data_projection(t_cub *cub, float dist, float curr_ray)
{
	float col_h;
	float shift_point;

	dist = dist * cos(curr_ray - cub->plr->pov);
	col_h = (SCALE / dist) * (cub->width / 2 / tan(cub->plr->fov / 2));
	cub->tex[cub->i_t]->tex_scale = col_h / cub->tex[cub->i_t]->tex_height;
	if ((int)col_h >= cub->height)
	{
		shift_point = 0;
		cub->tex[cub->i_t]->tex_y = (col_h - cub->height) / 2;
		col_h = cub->tex[cub->i_t]->tex_y + cub->height;
	}
	else
	{
		shift_point = (cub->height - col_h) / 2;
		cub->tex[cub->i_t]->tex_y = 0;
	}
	draw_all(cub, col_h, shift_point, dist);
}

void	horiz_side(t_cub *cub, float dist_horiz, float curr_ray)
{
	if ((curr_ray > 0 && curr_ray < PI) || curr_ray > 2 * PI)
	{
		cub->i_t = 0;
		cub->tex[cub->i_t]->tex_x = cub->offset_x;
		data_projection(cub, dist_horiz, curr_ray);
	}
	else
	{
		cub->i_t = 1;
		cub->tex[cub->i_t]->tex_x = cub->offset_x;
		data_projection(cub, dist_horiz, curr_ray);
	}
}

void	vert_side(t_cub *cub, float dist_vert, float curr_ray)
{
	cub->tex[cub->i_t]->tex_x = cub->offset_y;
	if (curr_ray > PI / 2 && curr_ray < 3 * PI / 2)
	{
		cub->i_t = 2;
		cub->tex[cub->i_t]->tex_x = cub->offset_y;
		data_projection(cub, dist_vert, curr_ray);
	}
	else
	{
		cub->i_t = 3;
		cub->tex[cub->i_t]->tex_x = cub->offset_y;
		data_projection(cub, dist_vert, curr_ray);
	}
}
