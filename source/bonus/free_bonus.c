/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 07:11:59 by wphylici          #+#    #+#             */
/*   Updated: 2020/11/02 04:45:32 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	free_side(t_cub *cub)
{
	if (cub->tex_no != NULL)
		free(cub->tex_no);
	if (cub->tex_so != NULL)
		free(cub->tex_so);
	if (cub->tex_we != NULL)
		free(cub->tex_we);
	if (cub->tex_ea != NULL)
		free(cub->tex_ea);
	if (cub->tex_s != NULL)
		free(cub->tex_s);
}

void	free_double_arr(void **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_s_tex(t_cub *cub)
{
	int i;

	i = 0;
	if (cub->tex != NULL)
	{
		while (i < 15)
		{
			free(cub->tex[i]);
			i++;
		}
		free(cub->tex);
	}
}

void	free_arr_tex(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 15)
	{
		if (cub->tex[i]->tex_array != NULL)
		{
			while (j < cub->tex[i]->tex_height)
			{
				free(cub->tex[i]->tex_array[j]);
				j++;
			}
			j = 0;
			free(cub->tex[i]->tex_array);
		}
		i++;
	}
}

void	all_free(t_cub *cub)
{
	int			i;
	t_sprites	*tmp;

	i = 0;
	if (cub->key != NULL)
		free(cub->key);
	if (cub->plr != NULL)
		free(cub->plr);
	if (cub->map != NULL)
		free(cub->map);
	if (cub->all_dist != NULL)
		free(cub->all_dist);
	if (cub->map->map != NULL)
		free_double_arr((void **)cub->map->map);
	free_arr_tex(cub);
	free_s_tex(cub);
	free_side(cub);
	if (cub != NULL)
		free(cub);
	while (cub->sprites != NULL)
	{
		tmp = cub->sprites;
		cub->sprites = cub->sprites->next;
		free(tmp);
	}
}
