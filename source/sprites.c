/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 03:31:30 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/30 00:15:15 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	lstnew_sprite(t_cub *cub, int y, int x)
{
	t_sprites	*tmp;
	t_sprites	*new;

	if (!(new = (t_sprites *)malloc(sizeof(t_sprites))))
		my_exit(cub, "\nError\nMalloc problem\n", EXIT_FAILURE);
	if (cub->sprites == NULL)
		cub->sprites = new;
	else
	{
		tmp = cub->sprites;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	new->x = x * SCALE + SCALE / 2;
	new->y = y * SCALE + SCALE / 2;
	new->dist = 0;
	new->next = NULL;
}

void	draw_pixel_sprite(t_cub *cub, t_sprites *tmp)
{
	int		x;
	int		y;

	x = -1;
	cub->i_t = 4;
	tmp->sprite_h = SCALE / tmp->dist * 600;
	tmp->s_scale = tmp->sprite_h / cub->tex[cub->i_t]->tex_width;
	tmp->sprite_x = cub->width / 2 - (cub->width / (M_PI / 3))
	* tmp->sprite_angle - tmp->sprite_h / 2;
	tmp->sprite_y = cub->height / 2 - tmp->sprite_h / 2;
	while (++x < tmp->sprite_h && (x + tmp->sprite_x) < cub->width)
	{
		y = -1;
		while (++y < tmp->sprite_h && (y + tmp->sprite_y) < cub->height)
		{
			cub->color = cub->tex[cub->i_t]->tex_array[
			(int)(y / tmp->s_scale)][(int)(x / tmp->s_scale)];
			if (cub->color > 0 && cub->all_dist[
			(int)(tmp->sprite_x + x)] > tmp->dist)
				my_mlx_pixel_put(cub, tmp->sprite_x + x,
				tmp->sprite_y + y, cub->color);
		}
	}
}

void	sorting_sprite(t_cub *cub)
{
	t_sprites	*tmp;
	t_sprites	*sprite_max;
	float		dist_max;

	dist_max = 0;
	while (dist_max != -1)
	{
		tmp = cub->sprites;
		dist_max = -1;
		while (tmp != NULL)
		{
			if (tmp->dist > dist_max)
			{
				dist_max = tmp->dist;
				sprite_max = tmp;
			}
			tmp = tmp->next;
		}
		if (dist_max != -1)
		{
			draw_pixel_sprite(cub, sprite_max);
			sprite_max->dist = -1;
		}
	}
}

void	init_sprite(t_cub *cub)
{
	t_sprites	*tmp;

	tmp = cub->sprites;
	while (tmp != NULL)
	{
		tmp->sprite_angle = atan2(cub->plr->plr_y - tmp->y,
		tmp->x - cub->plr->plr_x);
		if (tmp->sprite_angle < 0 && cub->plr->pov >= PI / 6 &&
			cub->plr->pov <= (PI * 2 - PI / 6))
			tmp->sprite_angle += 2 * PI;
		if (cub->plr->pov > (M_PI * 2 - M_PI / 6) && cub->plr->pov <= 7)
			tmp->sprite_angle += 2 * M_PI;
		tmp->sprite_angle -= cub->plr->pov;
		if (tmp->sprite_angle > -M_PI / 6 && tmp->sprite_angle < M_PI / 6)
			tmp->dist = sqrt(pow(cub->plr->plr_x - tmp->x, 2) +
			pow(cub->plr->plr_y - tmp->y, 2));
		else
			tmp->dist = -1;
		if (tmp->dist < 20)
			tmp->dist = -1;
		tmp = tmp->next;
	}
	sorting_sprite(cub);
}
