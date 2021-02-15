/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 04:18:25 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/29 16:21:13 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	search_pxl(t_cub *cub, int line, int *index, int size_line)
{
	char	cash;
	int		i;

	i = 4;
	while (--i >= 0)
	{
		cash = cub->addr[*index + line * cub->size_line];
		cub->addr[*index + line * cub->size_line] = cub->addr[size_line - i +
		(line * cub->size_line - 1)];
		cub->addr[size_line - i + (line * cub->size_line - 1)] = cash;
		*index += 1;
	}
}

void	revers_info(t_cub *cub)
{
	int		line;
	int		index;
	int		size_line;

	line = -1;
	while (++line < cub->height)
	{
		index = 0;
		size_line = cub->size_line;
		while (index < size_line)
		{
			search_pxl(cub, line, &index, size_line);
			size_line -= 4;
		}
	}
}

/*
** 59 - signature
** 60 - file size
** 61 - reserved
** 62 - file offset
*/

void	bit_map_file_header(int fd, int file_size, int offbits)
{
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &offbits, 4);
}

/*
** 75 - header size
** 76 - image width
** 77 - image height
** 78 - planes
** 79 - bitcount
*/

void	bit_map_info_header(t_cub *cub, int fd, int size, int biplanes)
{
	write(fd, &size, 4);
	write(fd, &cub->width, 4);
	write(fd, &cub->height, 4);
	write(fd, &biplanes, 2);
	write(fd, &cub->bits_per_pixel, 2);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 28);
}
