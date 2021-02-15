/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 03:59:45 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/31 13:48:11 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int		check_wall(t_cub *cub, float x, float y, char c)
{
	if ((int)(x / SCALE) < 0 || (int)(y / SCALE) < 0 ||
	(int)(y / SCALE) >= cub->map->map_max_y ||
	(int)(x / SCALE) >= cub->map->map_max_x)
		return (-1);
	else if (cub->map->map[(int)(y / SCALE)][(int)(x / SCALE)] == '1')
	{
		if (c == 'h')
			cub->offset_x = (int)x % SCALE;
		else
			cub->offset_y = (int)y % SCALE;
		return (1);
	}
	else
		return (0);
}

float	horiz_intersection(t_cub *cub, float curr_ray)
{
	float x;
	float y;
	float step_x;
	float step_y;

	step_y = SCALE;
	step_x = SCALE / tan(curr_ray);
	if ((curr_ray > 0 && curr_ray < PI) || curr_ray > PI * 2)
	{
		y = (int)(cub->plr->plr_y / SCALE) * SCALE - 0.001;
		step_y = -step_y;
	}
	else
	{
		y = (int)(cub->plr->plr_y / SCALE) * SCALE + SCALE;
		step_x = -step_x;
	}
	x = cub->plr->plr_x + (cub->plr->plr_y - y) / tan(curr_ray);
	while (check_wall(cub, x, y, 'h') == 0)
	{
		x += step_x;
		y += step_y;
	}
	return (check_wall(cub, x, y, 'h') == -1 ? INT_MAX :
	sqrt(pow(cub->plr->plr_x - x, 2) + pow(cub->plr->plr_y - y, 2)));
}

float	vert_intersection(t_cub *cub, float curr_ray)
{
	float x;
	float y;
	float step_x;
	float step_y;

	step_x = SCALE;
	step_y = SCALE * tan(curr_ray);
	if (curr_ray > PI / 2 && curr_ray < 3 * PI / 2)
	{
		x = (int)(cub->plr->plr_x / SCALE) * SCALE - 0.001;
		step_x = -step_x;
	}
	else
	{
		x = (int)(cub->plr->plr_x / SCALE) * SCALE + SCALE;
		step_y = -step_y;
	}
	y = cub->plr->plr_y + (cub->plr->plr_x - x) * tan(curr_ray);
	while (check_wall(cub, x, y, 'v') == 0)
	{
		x += step_x;
		y += step_y;
	}
	return (check_wall(cub, x, y, 'v') == -1 ? INT_MAX :
	sqrt(pow(cub->plr->plr_x - x, 2) + pow(cub->plr->plr_y - y, 2)));
}

void	raycast(t_cub *cub)
{
	int		i;
	float	start;
	float	dist_horiz;
	float	dist_vert;

	i = 0;
	start = cub->plr->pov + PI / 6;
	while (start > cub->plr->pov - PI / 6)
	{
		dist_horiz = horiz_intersection(cub, start);
		dist_vert = vert_intersection(cub, start);
		if (dist_horiz < dist_vert)
		{
			cub->all_dist[i++] = dist_horiz;
			horiz_side(cub, dist_horiz, start);
		}
		else
		{
			cub->all_dist[i++] = dist_vert;
			vert_side(cub, dist_vert, start);
		}
		start -= cub->plr->fov / cub->width;
	}
	cub->line_x = 0;
}
