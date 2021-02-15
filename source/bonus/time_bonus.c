/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 03:27:28 by wphylici          #+#    #+#             */
/*   Updated: 2020/10/31 13:31:48 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	time_sprite(t_cub *cub)
{
	static time_t	str_time = 0;

	if (str_time == 0)
		str_time = time(0);
	if (time(0) - str_time >= 2)
	{
		cub->i_t = 5;
		str_time = 0;
	}
	else
		cub->i_t = 4;
}

void	time_sprite_sound(t_cub *cub, const char *sound)
{
	int				pid;
	static int		start = 0;
	static time_t	str_time = 0;

	if (start == 0)
	{
		pid = fork();
		pid == 0 ? system(sound) : 0;
		pid == 0 ? kill(cub->pid + 1, SIGTERM) : 0;
		start = 1;
	}
	if (str_time == 0)
		str_time = time(0);
	if (time(0) - str_time >= 1)
	{
		pid = fork();
		pid == 0 ? system(sound) : 0;
		pid == 0 ? kill(cub->pid + 1, SIGTERM) : 0;
		str_time = 0;
		if (cub->i_t == 6)
			start = 0;
	}
}

void	time_minus_life(t_cub *cub)
{
	static int		start = 0;
	static time_t	str_time = 0;

	if (start == 0 && cub->i_t != 8)
	{
		cub->flag_life = -42;
		start = 1;
	}
	if (str_time == 0)
		str_time = time(0);
	if (time(0) - str_time >= 1 && cub->i_t != 8)
	{
		cub->flag_life = -42;
		str_time = 0;
	}
}

void	time_death(t_cub *cub)
{
	static int		start = 0;
	static time_t	str_time = 0;

	if (start == 0)
	{
		cub->pid = fork();
		cub->pid == 0 ? system("afplay ./sounds/death.mp3 -v 0.8") : 0;
		cub->pid == 0 ? kill(cub->pid + 1, SIGTERM) : 0;
		start = 1;
	}
	if (str_time == 0)
		str_time = time(0);
	while (time(0) - str_time < 6)
	{
		draw_background(cub);
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr,
		cub->tex[cub->i_t]->tex_img, cub->width / 2 - 233, cub->height / 2
		- cub->tex[cub->i_t]->tex_height / 2);
	}
	if (time(0) - str_time >= 4)
		my_exit(cub, "\nYOU DIED!\n", EXIT_SUCCESS);
}

void	fps_count(t_cub *cub)
{
	static time_t	str_time = 0;
	static int		count = 0;
	static char		*str = NULL;
	char			*tmp;

	if (str_time == 0)
		str_time = time(0);
	if (time(0) - str_time >= 1)
	{
		str_time = time(0);
		free(str);
		if (!(str = ft_itoa(count)))
			my_exit(cub, "\nError\nft_itoa problem\n", EXIT_FAILURE);
		count = 0;
	}
	else
		count++;
	if (str != NULL)
	{
		if (!(tmp = ft_strjoin("FPS: ", str)))
			my_exit(cub, "\nError\nft_strjoin problem\n", EXIT_FAILURE);
		mlx_string_put(cub->mlx_ptr, cub->win_ptr,
		cub->width - 100, 30, 0xFE5454, tmp);
		free(tmp);
	}
}
