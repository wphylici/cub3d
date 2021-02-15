/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 06:57:01 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/30 21:27:55 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	route_and_location(t_cub *cub)
{
	if (cub->plr->pov)
		my_exit(cub, "\nError\nMore than one player\n", EXIT_FAILURE);
	if (cub->map->map[cub->map->map_y][cub->map->map_x] == 'N')
		cub->plr->pov = PI / 2;
	if (cub->map->map[cub->map->map_y][cub->map->map_x] == 'S')
		cub->plr->pov = 3 * PI / 2;
	if (cub->map->map[cub->map->map_y][cub->map->map_x] == 'W')
		cub->plr->pov = PI;
	if (cub->map->map[cub->map->map_y][cub->map->map_x] == 'E')
		cub->plr->pov = 2 * PI;
	cub->plr->plr_x = cub->map->map_x * SCALE + SCALE / 2;
	cub->plr->plr_y = cub->map->map_y * SCALE + SCALE / 2;
}

void	processing_map(t_cub *cub)
{
	cub->map->map_y = -1;
	while (cub->map->map[++cub->map->map_y] &&
	cub->map->map_y < cub->map->map_max_y)
	{
		cub->map->map_x = -1;
		while (cub->map->map[cub->map->map_y][++cub->map->map_x])
		{
			if ((cub->map->map[cub->map->map_y][cub->map->map_x] == 'N'
			|| cub->map->map[cub->map->map_y][cub->map->map_x] == 'S'
			|| cub->map->map[cub->map->map_y][cub->map->map_x] == 'E'
			|| cub->map->map[cub->map->map_y][cub->map->map_x] == 'W'))
				route_and_location(cub);
			if (cub->map->map[cub->map->map_y][cub->map->map_x] == '2'
			|| cub->map->map[cub->map->map_y][cub->map->map_x] == '3')
				lstnew_sprite(cub, cub->map->map_y, cub->map->map_x);
		}
	}
}

void	map_size(t_cub *cub)
{
	int i;
	int j;
	int	len;

	i = -1;
	j = 1;
	len = 0;
	while (cub->map_str[++i])
	{
		if (cub->map_str[i] == '\n')
		{
			cub->map->map_max_y++;
			len = (len > j) ? len : j;
			j = 0;
		}
		j++;
	}
	cub->map->map_max_x = len - 1;
}

int		create_map(t_cub *cub)
{
	int y;

	y = 0;
	map_size(cub);
	if (!(cub->map->map = ft_split(cub, cub->map_str, '\n')))
		return (-1);
	free(cub->map_str);
	processing_map(cub);
	return (0);
}

int		ft_map(t_cub *cub, char *line)
{
	char *tmp;

	tmp = cub->map_str;
	if (!(cub->map_str = ft_strjoin(tmp, line)))
		return (-1);
	free(tmp);
	tmp = cub->map_str;
	if (!(cub->map_str = ft_strjoin(tmp, "\n")))
		return (-1);
	free(tmp);
	tmp = NULL;
	return (1);
}
