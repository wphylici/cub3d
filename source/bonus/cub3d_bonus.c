/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphylici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:48:05 by wphylici          #+#    #+#             */
/*   Updated: 2020/11/02 04:07:23 by wphylici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init(t_cub *cub)
{
	cub->plr->fov = PI / 3;
	if (!(cub->mlx_ptr = mlx_init()))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->win_ptr = mlx_new_window(cub->mlx_ptr, cub->width,
	cub->height, "cub3d")))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->img = mlx_new_image(cub->mlx_ptr, cub->width, cub->height)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->addr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel,
	&cub->size_line, &cub->endian)))
		my_exit(cub, "\nError\nMlx function problem\n", EXIT_FAILURE);
	if (!(cub->all_dist = (float *)malloc(sizeof(float) * cub->width)))
		my_exit(cub, "\nError\nMalloc problem\n", EXIT_FAILURE);
}

void	mem_alloc(t_cub *cub)
{
	int i;

	i = 0;
	cub->map_str = ft_strdup("");
	if (!(cub->key = (t_key *)malloc(sizeof(t_key))))
		my_exit(cub, "\nError\nMalloc problem\n", EXIT_FAILURE);
	ft_bzero(cub->key, sizeof(t_key));
	if (!(cub->plr = (t_plr *)malloc(sizeof(t_plr))))
		my_exit(cub, "\nError\nMalloc problem\n", EXIT_FAILURE);
	ft_bzero(cub->plr, sizeof(t_plr));
	if (!(cub->map = (t_map *)malloc(sizeof(t_map))))
		my_exit(cub, "\nError\nMalloc problem\n", EXIT_FAILURE);
	ft_bzero(cub->map, sizeof(t_map));
	if (!(cub->tex = (t_tex **)malloc(15 * sizeof(t_tex*))))
		my_exit(cub, "\nError\nMalloc problem\n", EXIT_FAILURE);
	while (i < 15)
	{
		if (!(cub->tex[i] = (t_tex *)malloc(sizeof(t_tex))))
			my_exit(cub, "\nError\nMalloc problem\n", EXIT_FAILURE);
		ft_bzero(cub->tex[i++], sizeof(t_tex));
	}
}

void	check_args(int argc)
{
	if (argc < 2 || argc > 3)
	{
		ft_putendl("\nError\nInvalid quantity of arguments\n");
		exit(EXIT_FAILURE);
	}
}

void	load(t_cub *cub, int argc, char **argv)
{
	mem_alloc(cub);
	check_args(argc);
	parser(cub, argv[1]);
	init(cub);
	wall_textures(cub);
	sprite_textures(cub);
	hud_textures(cub);
}

int		main(int argc, char **argv)
{
	t_cub *cub;

	if (!(cub = (t_cub *)malloc(sizeof(t_cub))))
		my_exit(cub, "\nError\nMalloc problem\n", EXIT_FAILURE);
	ft_bzero(cub, sizeof(t_cub));
	load(cub, argc, argv);
	search_save(cub, argc, argv);
	mlx_hook(cub->win_ptr, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->win_ptr, 3, 1L << 1, key_releas, cub);
	mlx_hook(cub->win_ptr, 17, 1L << 17, close_game, cub);
	mlx_loop_hook(cub->mlx_ptr, loop_manager, cub);
	if (cub->save == 0)
		mlx_loop(cub->mlx_ptr);
	my_exit(cub, "\nScreenshot done\n", EXIT_SUCCESS);
	return (0);
}
