/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:49:10 by tprokysh          #+#    #+#             */
/*   Updated: 2019/07/01 17:49:14 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	help(t_mlx *m)
{
	if (!m->help)
	{
		mlx_string_put(m->mlx_ptr, m->win_ptr, 50, 50, 0xFFFFFF,
				"Press 'H' to see tips");
	}
	else
	{
		mlx_string_put(m->mlx_ptr, m->win_ptr, 50, 50, 0xFFFFFF,
				"Move -> 'WASD'");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 50, 70, 0xFFFFFF,
				"Sprint -> 'Shift'");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 50, 90, 0xFFFFFF,
				"Show/Hide textures -> 'T'");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 50, 110, 0xFFFFFF,
				"Show/Hide help -> 'H'");
		mlx_string_put(m->mlx_ptr, m->win_ptr, 50, 130, 0xFFFFFF,
				"Exit - 'ESC'");
	}
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	t_map	*map;
	t_world	*world;

	if (ac != 2)
		usage_error();
	if (ft_strcmp(av[0], "./wolf3d") != 0)
		usage_error();
	world = init_world(av);
	map = init_map(map, world);
	map->world = world;
	mlx = init_mlx(mlx);
	load_textures(mlx);
	spawn(map, world);
	init_img(0, mlx);
	mlx->map = map;
	draw_map(mlx, map);
	mlx_hook(mlx->win_ptr, 2, 1, key_on, mlx);
	mlx_hook(mlx->win_ptr, 3, 2, key_off, mlx);
	mlx_loop_hook(mlx->mlx_ptr, keys, (void *)mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
