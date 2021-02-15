/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 03:50:15 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/29 17:36:21 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (y < cub->height && x < cub->width && y > 0 && x > 0)
	{
		dst = cub->addr + (y * cub->size_line + x * (cub->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int		create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int		shade_color(int color, double dist)
{
	if (dist <= 1)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / dist) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) / dist) << 8)
		+ ((int)((0x0000FF & color) / dist)));
}

void	distance_shade(t_cub *cub, int color, double dist)
{
	cub->color = shade_color(color, dist / 200);
}
