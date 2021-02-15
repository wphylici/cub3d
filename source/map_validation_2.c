/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 07:07:19 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/29 01:19:49 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		valid_sym2(t_map *map, int y, int x)
{
	if (map->map[y][x] == '0' || map->map[y][x] == 'E' ||
	map->map[y][x] == '1' || map->map[y][x] == '2'
	|| map->map[y][x] == 'N' || map->map[y][x] == 'S' ||
	map->map[y][x] == 'W')
		return (1);
	return (0);
}

int		valid_sym1(t_map *map, int y, int x)
{
	if (valid_sym2(map, y, x + 1) && valid_sym2(map, y, x - 1) &&
	valid_sym2(map, y + 1, x) && valid_sym2(map, y - 1, x))
		return (1);
	return (0);
}

int		valid_sym(t_map *map, int y, int x)
{
	if (map->map[y][x] == '0' || map->map[y][x] == '2' ||
	map->map[y][x] == 'N' || map->map[y][x] == 'S' ||
	map->map[y][x] == 'W' || map->map[y][x] == 'E')
		return (1);
	return (0);
}
