/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:31:17 by wphylici          #+#    #+#             */
/*   Updated: 2020/11/01 01:21:35 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i] || str1[i] == '\0')
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	ft_save(t_cub *cub)
{
	int		fd;
	int		index;

	loop_manager(cub);
	if (!(fd = open("screenshot.bmp", O_RDWR | O_CREAT, S_IRUSR
										| S_IWUSR | S_IROTH)))
		my_exit(cub, "\nError\nFile reading problem\n", EXIT_FAILURE);
	bit_map_file_header(fd,
	14 + 40 + 4 + cub->width * cub->height * 4, 14 + 40 + 4);
	bit_map_info_header(cub, fd, 40, 1);
	revers_info(cub);
	index = cub->width * cub->height;
	while (--index >= 0)
		write(fd, &cub->addr[index * cub->bits_per_pixel / 8], 4);
	close(fd);
}

void	search_save(t_cub *cub, int argc, char **argv)
{
	if (argc > 3)
		my_exit(cub, "Error\nDelete one or more arguments!\n", EXIT_FAILURE);
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) == 6 &&
		ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
		{
			ft_save(cub);
			cub->save = 1;
		}
		else
			my_exit(cub, "Error\nIncorrect input for image!\n", EXIT_FAILURE);
	}
	else
		cub->save = 0;
}
