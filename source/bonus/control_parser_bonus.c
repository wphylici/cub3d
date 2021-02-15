/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_parser_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 18:49:14 by wphylici          #+#    #+#             */
/*   Updated: 2020/11/02 03:50:08 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int		processing_str_map(t_cub *cub, char *line, int j)
{
	int i;

	i = 0;
	if (*line == 'R' && *cub->map_str == '\0')
		return (ft_resol(cub, line));
	if ((*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
	&& *cub->map_str == '\0')
		return (ft_texture(cub, line));
	if ((*line == 'F' || *line == 'C') && *cub->map_str == '\0')
		return (ft_color(cub, line));
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (ft_map(cub, line));
	if ((*cub->map_str == '\0' && *line == '\0') || (*line == '\0' && j == 0))
		return (1);
	return (-1);
}

void	check_name(t_cub *cub, char *name)
{
	int len;

	len = ft_strlen(name);
	if (name[len - 1] != 'b' && name[len - 2] != 'u' &&
		name[len - 3] != 'c' && name[len - 4] != '.')
		my_exit(cub, "\nError\nInvalid configuration file name\n",
													EXIT_FAILURE);
}

void	read_map(t_cub *cub, char *name)
{
	int		j;
	int		fd;
	char	*line;

	line = NULL;
	check_name(cub, name);
	if ((fd = open(name, O_RDONLY)) < 0)
		my_exit(cub, "\nError\nFile reading problem\n", EXIT_FAILURE);
	while ((j = get_next_line(fd, &line)) != -1)
	{
		if (line && processing_str_map(cub, line, j) == -1)
		{
			free(line);
			free(cub->map_str);
			my_exit(cub, "\nError\nInvalid configuration file\n", EXIT_FAILURE);
		}
		free(line);
		if (j == 0)
			break ;
	}
	close(fd);
}

void	check_init(t_cub *cub)
{
	if (cub->tex_no == '\0' || cub->tex_so == '\0' || cub->tex_we == '\0' ||
		cub->tex_ea == '\0' || *cub->tex_s == '\0' || cub->clr_c_flag == 0 ||
		cub->clr_f_flag == 0 || cub->width == 0 || cub->height == 0 ||
		cub->plr->plr_x == 0 || cub->plr->plr_y == 0)
		my_exit(cub, "\nError\nNot enough data to run\n", EXIT_FAILURE);
}

void	parser(t_cub *cub, char *name)
{
	read_map(cub, name);
	create_map(cub);
	check_content_map(cub);
}
