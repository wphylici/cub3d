/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resol_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 06:46:25 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/29 23:42:44 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_resol(t_cub *cub, char *line)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (line[i] == ' ')
		i++;
	j = i;
	while (line[i] >= '0' && line[i] <= '9')
		cub->width = (cub->width * 10) + (line[i++] - '0');
	j = i - j;
	(cub->width > 1440 || j > 5) ? cub->width = 1440 : cub->width;
	cub->width < 500 ? cub->width = 500 : cub->width;
	while (line[i] == ' ')
		i++;
	j = i;
	while (line[i] >= '0' && line[i] <= '9')
		cub->height = (cub->height * 10) + (line[i++] - '0');
	j = i - j;
	(cub->height > 900 || j > 5) ? cub->height = 900 : cub->height;
	cub->height < 500 ? cub->height = 500 : cub->height;
	return (1);
}

int	ft_resol(t_cub *cub, char *line)
{
	int i;

	i = 1;
	if (cub->width || cub->height)
		return (-1);
	if (line[i] != ' ')
		return (-1);
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] != ' ')
		return (-1);
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
		return (-1);
	return (init_resol(cub, line));
}
