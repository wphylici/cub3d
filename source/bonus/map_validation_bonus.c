/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 07:02:02 by wphylici          #+#    #+#             */
/*   Updated: 2020/11/02 04:16:12 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int		check_valid_map_line(t_map *map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->map_max_y)
	{
		x = 0;
		while (x < map->map_max_x && map->map[y][x])
		{
			if (map->map[y][x] == ' ' || map->map[y][x] == '1')
				x++;
			else if (valid_sym(map, y, x) && valid_sym1(map, y, x))
				x++;
			else
				return (-1);
		}
	}
	return (1);
}

int		check_map_symbol(t_map *map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->map_max_y)
	{
		x = -1;
		while (++x < map->map_max_x && map->map[y][x])
		{
			if (map->map[y][x] != ' ' && map->map[y][x] != '0' &&
			map->map[y][x] != '1' && map->map[y][x] != '2' &&
			map->map[y][x] != '3' && map->map[y][x] != '4' &&
			map->map[y][x] != 'N' && map->map[y][x] != 'S' &&
			map->map[y][x] != 'W' && map->map[y][x] != 'E')
				return (-1);
		}
	}
	return (1);
}

int		check_elements_map(t_cub *cub)
{
	if (check_map_symbol(cub->map) == -1)
		return (-1);
	if (check_valid_map_line(cub->map) == -1)
		return (-1);
	return (1);
}

void	check_content_map(t_cub *cub)
{
	check_init(cub);
	if (check_elements_map(cub) == -1)
		my_exit(cub, "\nError\nInvalid map\n", EXIT_FAILURE);
}
