/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:27:08 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/29 18:06:30 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	make_array(t_cub *cub)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	if (!(cub->tex[cub->i_t]->tex_array =
	(int **)malloc(cub->tex[cub->i_t]->tex_height * sizeof(int *))))
		my_exit(cub, "\nError\nMalloc problem\n", EXIT_FAILURE);
	while (y < cub->tex[cub->i_t]->tex_height)
		if (!(cub->tex[cub->i_t]->tex_array[y++] =
		(int *)malloc(cub->tex[cub->i_t]->tex_width * sizeof(int))))
			my_exit(cub, "\nError\nMalloc problem\n", EXIT_FAILURE);
	y = 0;
	while (y < cub->tex[cub->i_t]->tex_height)
	{
		x = 0;
		while (x < cub->tex[cub->i_t]->tex_width)
			cub->tex[cub->i_t]->tex_array[y][x++] =
			cub->tex[cub->i_t]->tex_addr[i++];
		y++;
	}
}

void	make_reverse_array(t_cub *cub)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	if (!(cub->tex[cub->i_t]->tex_array =
	(int **)malloc(cub->tex[cub->i_t]->tex_height * sizeof(int *))))
		my_exit(cub, "\nError\nMalloc problem\n", EXIT_FAILURE);
	while (y < cub->tex[cub->i_t]->tex_height)
		if (!(cub->tex[cub->i_t]->tex_array[y++] =
		(int *)malloc(cub->tex[cub->i_t]->tex_width * sizeof(int))))
			my_exit(cub, "\nError\nMalloc problem\n", EXIT_FAILURE);
	y = 0;
	while (y < cub->tex[cub->i_t]->tex_height)
	{
		x = cub->tex[cub->i_t]->tex_width - 1;
		while (x >= 0)
			cub->tex[cub->i_t]->tex_array[y][x--] =
			cub->tex[cub->i_t]->tex_addr[i++];
		y++;
	}
}
