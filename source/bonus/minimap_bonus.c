/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:32:32 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/31 13:34:24 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	raystep(t_cub *cub, float curr_ray)
{
	int c;
	int x;
	int y;

	c = 0;
	x = floor(cub->plr->plr_x / SCALE * SCL_MAP);
	y = floor(cub->plr->plr_y / SCALE * SCL_MAP);
	while (cub->map->map[(int)(y / SCL_MAP)]
	[(int)(x / SCL_MAP)] != '1' && c < 20)
	{
		c += 1;
		x = (cub->plr->plr_x / SCALE * SCL_MAP + SHIFT_X + 1)
		+ c * cos(curr_ray);
		y = (cub->plr->plr_y / SCALE * SCL_MAP + SHIFT_Y + 1)
		- c * sin(curr_ray);
		my_mlx_pixel_put(cub, x, y, 0xFFFF66);
		x -= SHIFT_X;
		y -= SHIFT_Y;
		if ((int)(x / SCL_MAP) >= cub->map->map_max_x ||
		(int)(y / SCL_MAP) >= cub->map->map_max_y ||
		(int)(x / SCL_MAP) < 0 || (int)(y / SCL_MAP) < 0)
			break ;
	}
}

void	draw_spectrum(t_cub *cub)
{
	float	curr_ray;

	curr_ray = cub->plr->pov - PI / 6;
	while (curr_ray < cub->plr->pov + PI / 6)
	{
		raystep(cub, curr_ray);
		curr_ray += cub->plr->fov / cub->width;
	}
}

void	draw_rote_pov(t_cub *cub)
{
	float c;
	float x;
	float y;

	c = 0;
	x = cub->plr->plr_x / SCALE * SCL_MAP;
	y = cub->plr->plr_y / SCALE * SCL_MAP;
	draw_spectrum(cub);
	while (cub->map->map[(int)y / SCL_MAP][(int)x / SCL_MAP] != '1' && c < 10)
	{
		c += 1;
		x = (cub->plr->plr_x / SCALE * SCL_MAP + SHIFT_X + 1)
		+ c * cos(cub->plr->pov);
		y = (cub->plr->plr_y / SCALE * SCL_MAP + SHIFT_Y + 1)
		- c * sin(cub->plr->pov);
		my_mlx_pixel_put(cub, x, y, 0xFF0000);
		x -= SHIFT_X;
		y -= SHIFT_Y;
	}
}

void	draw_plr(t_cub *cub)
{
	int x_tmp;
	int y_tmp;

	y_tmp = cub->plr->plr_y / SCALE * SCL_MAP + SHIFT_Y;
	while (y_tmp < (cub->plr->plr_y / SCALE * SCL_MAP + SHIFT_Y + 2))
	{
		x_tmp = cub->plr->plr_x / SCALE * SCL_MAP + SHIFT_X;
		while (x_tmp < (cub->plr->plr_x / SCALE * SCL_MAP + SHIFT_X + 2))
			my_mlx_pixel_put(cub, x_tmp++, y_tmp, 0xFF0000);
		y_tmp++;
	}
}

void	draw_minimap(t_cub *cub, int color)
{
	int x_tmp;
	int y_tmp;

	y_tmp = cub->map->map_y * SCL_MAP + SHIFT_Y;
	while (y_tmp < (cub->map->map_y * SCL_MAP + SCL_MAP + SHIFT_Y))
	{
		x_tmp = cub->map->map_x * SCL_MAP + SHIFT_X;
		while (x_tmp < (cub->map->map_x * SCL_MAP + SCL_MAP + SHIFT_X))
			my_mlx_pixel_put(cub, x_tmp++, y_tmp, color);
		y_tmp++;
	}
}
