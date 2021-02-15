/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 04:42:51 by wphylici          #+#    #+#             */
/*   Updated: 2020/11/02 04:08:30 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int		close_game(void)
{
	write(1, "\nBye =)\n\n", 9);
	exit(EXIT_SUCCESS);
	return (0);
}

void	all_destroy(t_cub *cub)
{
	cub->i_t = 0;
	while (cub->i_t < 15)
	{
		if (cub->tex[cub->i_t]->tex_img)
			mlx_destroy_image(cub->mlx_ptr, cub->tex[cub->i_t]->tex_img);
		cub->i_t++;
	}
	if (cub->img)
		mlx_destroy_image(cub->mlx_ptr, cub->img);
	if (cub->win_ptr)
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
}

int		key_press(int key, t_cub *cub)
{
	if (key == 13 && cub->key->forward == 0)
		cub->key->forward = 1;
	if (key == 1 && cub->key->back == 0)
		cub->key->back = 1;
	if (key == 2 && cub->key->right == 0)
		cub->key->right = 1;
	if (key == 0 && cub->key->left == 0)
		cub->key->left = 1;
	if (key == 123 && cub->key->turn_left == 0)
		cub->key->turn_left = 1;
	if (key == 124 && cub->key->turn_right == 0)
		cub->key->turn_right = 1;
	if (key == 53)
		my_exit(cub, "\nBye =)\n", EXIT_SUCCESS);
	return (1);
}

int		key_releas(int key, t_cub *cub)
{
	if (key == 13 && cub->key->forward == 1)
		cub->key->forward = 0;
	if (key == 1 && cub->key->back == 1)
		cub->key->back = 0;
	if (key == 2 && cub->key->right == 1)
		cub->key->right = 0;
	if (key == 0 && cub->key->left == 1)
		cub->key->left = 0;
	if (key == 123 && cub->key->turn_left == 1)
		cub->key->turn_left = 0;
	if (key == 124 && cub->key->turn_right == 1)
		cub->key->turn_right = 0;
	return (1);
}

int		loop_manager(t_cub *cub)
{
	move(cub);
	raycast(cub);
	init_sprite(cub);
	make_minimap(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img, 0, 0);
	fps_count(cub);
	draw_score(cub);
	draw_lifes(cub);
	return (0);
}
