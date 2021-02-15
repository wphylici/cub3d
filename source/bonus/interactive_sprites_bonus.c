/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_sprites_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 03:36:28 by wphylici          #+#    #+#             */
/*   Updated: 2020/11/02 04:42:20 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	for_collumn_sprite(t_cub *cub, t_sprites *tmp)
{
	if (cub->map->map[(int)floor(tmp->y / SCALE)]
			[(int)floor(tmp->x / SCALE)] == '4')
	{
		cub->i_t = 14;
		tmp->sprite_h = (SCALE / tmp->dist) *
		(cub->width / 2 / tan(cub->plr->fov / 2) + 50);
	}
}

void	for_coin_sprite(t_cub *cub, t_sprites *tmp)
{
	if (cub->map->map[(int)floor(tmp->y / SCALE)]
			[(int)floor(tmp->x / SCALE)] == '3')
	{
		cub->i_t = 6;
		tmp->sprite_h = SCALE / tmp->dist * 150;
		if ((int)floor(cub->plr->plr_y / SCALE) == (int)floor(tmp->y / SCALE) &&
		(int)floor(cub->plr->plr_x / SCALE) == (int)floor(tmp->x / SCALE) &&
		!tmp->flag_invis)
		{
			time_sprite_sound(cub, "afplay ./sounds/coin.wav -v 0.8");
			tmp->flag_invis = 1;
			cub->flag_score += 300;
		}
	}
}

void	for_fire_sprite(t_cub *cub, t_sprites *tmp)
{
	if (cub->map->map[(int)floor(tmp->y / SCALE)]
			[(int)floor(tmp->x / SCALE)] == '2')
	{
		time_sprite(cub);
		tmp->sprite_h = SCALE / tmp->dist * 600;
		if ((int)floor(cub->plr->plr_y / SCALE) == (int)floor(tmp->y / SCALE) &&
		(int)floor(cub->plr->plr_x / SCALE) == (int)floor(tmp->x / SCALE))
		{
			time_sprite_sound(cub, "afplay ./sounds/Oof!.wav -v 0.8");
			time_minus_life(cub);
		}
	}
}

void	get_color_and_interactive(t_cub *cub, t_sprites *tmp)
{
	for_fire_sprite(cub, tmp);
	for_coin_sprite(cub, tmp);
	for_collumn_sprite(cub, tmp);
}
