/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:52:00 by tprokysh          #+#    #+#             */
/*   Updated: 2019/07/01 17:52:03 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_world	*init_world(char **av)
{
	t_world *w;
	int		width;
	int		height;

	height = count_lines(av);
	width = count_worlds(av);
	if (width != height || height > 500 || width > 500)
		map_error();
	w = new_map(width, height);
	fill_map(w, av);
	return (w);
}

void	init_img(int f, t_mlx *m)
{
	if (f == 0)
	{
		m->img_ptr = mlx_new_image(m->mlx_ptr, WIDTH, HEIGHT);
		m->data = (int *)mlx_get_data_addr(m->img_ptr, &m->bpp,
				&m->size_line, &m->endian);
		m->bpp /= 8;
	}
}

t_map	*init_map(t_map *m, t_world *w)
{
	m = (t_map *)malloc(sizeof(t_map));
	m->dx = -1;
	m->dy = 0;
	m->plx = 0;
	m->ply = 0.5;
	return (m);
}

t_mlx	*init_mlx(t_mlx *m)
{
	m = (t_mlx *)malloc(sizeof(t_mlx));
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, WIDTH, HEIGHT, "wolf3d");
	m->textured = 1;
	return (m);
}
