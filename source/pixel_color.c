/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 03:50:15 by wphylici          #+#    #+#             */
/*   Updated: 2020/11/01 20:46:38 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (y < cub->height && x < cub->width && y >= 0 && x >= 0)
	{
		dst = cub->addr + (y * cub->size_line + x * (cub->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int		create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
