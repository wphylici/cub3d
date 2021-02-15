/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 06:52:21 by wphylici          #+#    #+#             */
/*   Updated: 2020/11/01 20:10:36 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	size_t	c;
	char	*res;

	i = 0;
	c = 0;
	s_len = ft_strlen((char *)s);
	if (s == NULL)
		return (NULL);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (start > len)
		return (ft_strdup(""));
	while (s[i] != '\0')
	{
		if (i >= start && c < len)
			res[c++] = s[i];
		i++;
	}
	res[c] = '\0';
	return (res);
}

int		init_texture(t_cub *cub, char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i] != '.')
		i++;
	if (!(tmp = ft_substr(line, i, ft_strlen(line))))
		return (-1);
	i = 0;
	if (*line == 'N')
		cub->tex_no = tmp;
	if (line[i] == 'S' && line[i + 1] == 'O')
		cub->tex_so = tmp;
	if (*line == 'W')
		cub->tex_we = tmp;
	if (*line == 'E')
		cub->tex_ea = tmp;
	if (line[i] == 'S' && line[i + 1] == ' ')
		cub->tex_s = tmp;
	return (1);
}

int		check_double_tex(t_cub *cub, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'N')
		if (cub->tex_no)
			return (-1);
	if (line[i] == 'S' && line[i + 1] == 'O')
		if (cub->tex_so)
			return (-1);
	if (line[i] == 'W')
		if (cub->tex_we)
			return (-1);
	if (line[i] == 'E')
		if (cub->tex_ea)
			return (-1);
	if (line[i] == 'S' && line[i + 1] == ' ')
		if (cub->tex_s)
			return (-1);
	return (0);
}

int		ft_texture(t_cub *cub, char *line)
{
	int fd;
	int i;

	i = 1;
	if (check_double_tex(cub, line))
		return (-1);
	if (line[i - 1] == 'N' && line[i] != 'O')
		return (-1);
	if (line[i - 1] == 'S' && (line[i] != 'O' && line[i] != ' '))
		return (-1);
	if (line[i - 1] == 'W' && line[i] != 'E')
		return (-1);
	if (line[i - 1] == 'E' && line[i] != 'A')
		return (-1);
	(line[i - 1] == 'S' && line[i] == ' ') ? i : i++;
	if (line[i] != ' ')
		return (-1);
	while (line[i] == ' ')
		i++;
	if (line[i] != '.')
		return (-1);
	if ((fd = open(ft_strchr(line, '.'), O_RDONLY)) == -1)
		return (-1);
	close(fd);
	return (init_texture(cub, line));
}
