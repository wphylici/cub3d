/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 09:59:15 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/29 20:57:40 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_background(t_cub *cub)
{
	int x;
	int y;

	y = 0;
	cub->color = 0x151112;
	while (y < cub->height)
	{
		x = 0;
		while (x < cub->width)
			my_mlx_pixel_put(cub, x++, y, cub->color);
		y++;
	}
}

void	draw_score(t_cub *cub)
{
	char *nbr;
	char *str;

	if (!(nbr = ft_itoa(cub->flag_score)))
		my_exit(cub, "\nError\nft_itoa problem\n", EXIT_FAILURE);
	if (!(str = ft_strjoin("SCORE: ", nbr)))
		my_exit(cub, "\nError\nft_strjoin problem\n", EXIT_FAILURE);
	cub->i_t = 7;
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr,
	cub->tex[cub->i_t]->tex_img, cub->width - 215, cub->height - 66);
	mlx_string_put(cub->mlx_ptr, cub->win_ptr, cub->width - 180,
	cub->height - 36, 0xFFFFFF, str);
	free(nbr);
	free(str);
}

void	draw_lifes(t_cub *cub)
{
	static int flag = 8;

	cub->i_t = flag;
	if (flag <= 12)
	{
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr,
		cub->tex[cub->i_t]->tex_img, 30, cub->height - 70);
	}
	if (cub->flag_life == -42 && cub->i_t < 12)
	{
		flag++;
		cub->flag_life = 0;
	}
	if (cub->i_t >= 12 && cub->flag_life == -42)
	{
		cub->i_t = 13;
		time_death(cub);
	}
}

void	make_minimap(t_cub *cub)
{
	cub->map->map_y = -1;
	while (cub->map->map[++cub->map->map_y] &&
	cub->map->map_y < cub->map->map_max_y)
	{
		cub->map->map_x = -1;
		while (cub->map->map[cub->map->map_y][++cub->map->map_x])
		{
			if (cub->map->map[cub->map->map_y][cub->map->map_x] == '1')
				draw_minimap(cub, 0x6E6E6E);
			if (cub->map->map[cub->map->map_y][cub->map->map_x] != '1' &&
				cub->map->map[cub->map->map_y][cub->map->map_x] != ' ')
				draw_minimap(cub, 0x191919);
		}
	}
	draw_plr(cub);
	draw_rote_pov(cub);
}
