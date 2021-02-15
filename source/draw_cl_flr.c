/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cl_flr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 04:30:38 by wphylici          #+#    #+#             */
/*   Updated: 2020/11/15 19:10:50 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_floor(t_cub *cub, float floor_start)
{
	while (floor_start < cub->height)
		my_mlx_pixel_put(cub, cub->line_x, floor_start++, cub->clr_f);
}

void	draw_ceiling(t_cub *cub, float ceiling_start)
{
	while (ceiling_start >= 0)
		my_mlx_pixel_put(cub, cub->line_x, ceiling_start--, cub->clr_c);
}

void	draw_all(t_cub *cub, float col_h, int y)
{
	draw_ceiling(cub, y);
	draw_wall_texture(cub, col_h, y);
	draw_floor(cub, y + col_h);
	cub->line_x++;
}
