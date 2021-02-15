/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:48:34 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/29 16:36:00 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int		ft_counter_string(char const *s, char c)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (*s == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			result++;
		}
	}
	return (result);
}

static char		*ft_make_string(t_cub *cub, char const *s, char c)
{
	int		n;
	char	*str;

	if (!(str = (char*)malloc((cub->map->map_max_x + 1) * sizeof(char))))
		return (NULL);
	n = 0;
	while (s[n] != c && s[n] != '\0')
	{
		str[n] = s[n];
		n++;
	}
	while (n < cub->map->map_max_x)
		str[n++] = ' ';
	str[n] = '\0';
	return (str);
}

static void		**ft_free(char **str, int i)
{
	while (i > 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

char			**ft_split(t_cub *cub, char const *s, const char c)
{
	int		i;
	int		i_res;
	char	**res;

	i = 0;
	i_res = 0;
	if (s == NULL)
		return (NULL);
	if (!(res = (char **)malloc((ft_counter_string(s, c) + 1) * sizeof(char*))))
		return (NULL);
	while (s[i] != '\0' && i_res < ft_counter_string(s, c))
	{
		while (s[i] == c)
			i++;
		if (!(res[i_res] = ft_make_string(cub, s + i, c)))
			return ((char**)ft_free(res, i_res));
		while (s[i] != c && s[i] != '\0')
			i++;
		i_res++;
	}
	res[i_res] = NULL;
	return (res);
}
