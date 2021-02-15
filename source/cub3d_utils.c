/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 03:15:01 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/29 18:38:58 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_exit(t_cub *cub, char *str, int status)
{
	all_destroy(cub);
	all_free(cub);
	ft_putendl(str);
	exit(status);
}

void	ft_putendl(char const *s)
{
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)s;
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
}

int		ft_digit_len(long n)
{
	int x;

	x = 0;
	if (n < 0)
		x++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		x++;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*res;

	neg = 0;
	len = ft_digit_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(res = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		neg = 1;
	}
	res[len] = '\0';
	while (len--)
	{
		res[len] = n % 10 + '0';
		n = n / 10;
		if (neg == 1)
			res[0] = '-';
	}
	return (res);
}
