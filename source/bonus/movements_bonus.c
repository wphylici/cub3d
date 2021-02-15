/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 13:22:43 by wphylici          #+#    #+#             */
/*   Updated: 2020/11/02 04:35:08 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int		check_collision(t_cub *cub)
{
	if (cub->map->map[(int)floor(cub->plr->plr_y / SCALE)]
	[(int)floor(cub->plr->plr_x / SCALE)] == '1' ||
	cub->map->map[(int)floor(cub->plr->plr_y / SCALE)]
	[(int)floor(cub->plr->plr_x / SCALE)] == '4')
		return (-1);
	return (0);
}

void	forward_back(t_cub *cub)
{
	if (cub->key->forward == 1)
	{
		cub->plr->plr_x += cos(cub->plr->pov) * SPEED;
		if (check_collision(cub))
			cub->plr->plr_x -= cos(cub->plr->pov) * SPEED;
		cub->plr->plr_y -= sin(cub->plr->pov) * SPEED;
		if (check_collision(cub))
			cub->plr->plr_y += sin(cub->plr->pov) * SPEED;
	}
	if (cub->key->back == 1)
	{
		cub->plr->plr_x -= cos(cub->plr->pov) * SPEED;
		if (check_collision(cub))
			cub->plr->plr_x += cos(cub->plr->pov) * SPEED;
		cub->plr->plr_y += sin(cub->plr->pov) * SPEED;
		if (check_collision(cub))
			cub->plr->plr_y -= sin(cub->plr->pov) * SPEED;
	}
}

void	right_left(t_cub *cub)
{
	if (cub->key->right == 1)
	{
		cub->plr->plr_x += sin(cub->plr->pov) * SPEED;
		if (check_collision(cub))
			cub->plr->plr_x -= sin(cub->plr->pov) * SPEED;
		cub->plr->plr_y += cos(cub->plr->pov) * SPEED;
		if (check_collision(cub))
			cub->plr->plr_y -= cos(cub->plr->pov) * SPEED;
	}
	if (cub->key->left == 1)
	{
		cub->plr->plr_x -= sin(cub->plr->pov) * SPEED;
		if (check_collision(cub))
			cub->plr->plr_x += sin(cub->plr->pov) * SPEED;
		cub->plr->plr_y -= cos(cub->plr->pov) * SPEED;
		if (check_collision(cub))
			cub->plr->plr_y += cos(cub->plr->pov) * SPEED;
	}
}

void	overview(t_cub *cub)
{
	if (cub->key->turn_right == 1)
	{
		cub->plr->pov -= PI / 50;
		if (cub->plr->pov < 0)
			cub->plr->pov += 2 * PI;
	}
	if (cub->key->turn_left == 1)
	{
		cub->plr->pov += PI / 50;
		if (cub->plr->pov > 2 * PI)
			cub->plr->pov -= 2 * PI;
	}
}

void	move(t_cub *cub)
{
	forward_back(cub);
	right_left(cub);
	overview(cub);
}
