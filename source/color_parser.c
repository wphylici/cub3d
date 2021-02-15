/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 06:53:44 by wphylici          #+#    #+#             */
/*   Updated: 2020/11/02 02:58:12 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_format_clr(int r, int g, int b)
{
	if (r > 255 || r < 0)
		return (-1);
	if (g > 255 || g < 0)
		return (-1);
	if (b > 255 || b < 0)
		return (-1);
	return (0);
}

int		init_color(t_cub *cub, char *line)
{
	int i;
	int r;
	int g;
	int b;

	i = 1;
	r = 0;
	g = 0;
	b = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		r = (r * 10) + (line[i++] - '0');
	i++;
	while (line[i] >= '0' && line[i] <= '9')
		g = (g * 10) + (line[i++] - '0');
	i++;
	while (line[i] >= '0' && line[i] <= '9')
		b = (b * 10) + (line[i++] - '0');
	if (check_format_clr(r, g, b))
		return (-1);
	*line == 'C' ? (cub->clr_c = create_rgb(r, g, b)) :
	(cub->clr_f = create_rgb(r, g, b));
	return (1);
}

int		check_double_clr(t_cub *cub, char c)
{
	if (c == 'F')
	{
		if (cub->clr_f_flag)
		{
			free(cub->map_str);
			my_exit(cub, "\nError\nInvalid configuration file\n", EXIT_FAILURE);
		}
		cub->clr_f_flag = 1;
	}
	if (c == 'C')
	{
		if (cub->clr_c_flag)
		{
			free(cub->map_str);
			my_exit(cub, "\nError\nInvalid configuration file\n", EXIT_FAILURE);
		}
		cub->clr_c_flag = 1;
	}
	return (0);
}

int		check_comma(t_cub *cub, char *line, int i)
{
	if (line[i] < '0' || line[i] > '9')
	{
		free(cub->map_str);
		my_exit(cub, "\nError\nInvalid configuration file\n", EXIT_FAILURE);
	}
	return (i);
}

int		ft_color(t_cub *cub, char *line)
{
	int i;

	i = 1;
	check_double_clr(cub, line[0]);
	if (line[i] != ' ')
		return (-1);
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i++] != ',')
		return (-1);
	check_comma(cub, line, i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i++] != ',')
		return (-1);
	check_comma(cub, line, i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
		return (-1);
	return (init_color(cub, line));
}
