/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 08:30:38 by tprokysh          #+#    #+#             */
/*   Updated: 2019/07/03 08:30:42 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		close_wolf(t_mlx *m)
{
	(void)m;
	m = NULL;
	exit(0);
	return (0);
}

void	minimap_draw(int x, int y, int color, t_mlx *mlx)
{
	int i;
	int j;
	int s;

	s = WIDTH / 7 / mlx->map->world->mw;
	if (s == 0)
		s = 1;
	j = s * 2 + s * y;
	while (j < s * 2 + (s * (y + 1)))
	{
		i = s * 2 + s * x;
		while (i < s * 2 + (s * (x + 1)))
		{
			((int *)mlx->data)[j * WIDTH + (WIDTH - i)] = color;
			i++;
		}
		j++;
	}
}

void	minimap(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < mlx->map->world->mw)
	{
		x = 0;
		while (x < mlx->map->world->mh)
		{
			if (mlx->map->world->world[x][y] != 0)
				minimap_draw(x, y, 0x874812, mlx);
			else
				minimap_draw(x, y, 0x000000, mlx);
			x++;
		}
		y++;
	}
	x = mlx->map->px;
	y = mlx->map->py;
	minimap_draw(x, y, 0xFF0004, mlx);
}

void	check_number(t_world *w)
{
	int x;
	int y;

	y = 0;
	while (y < w->mh)
	{
		x = 0;
		while (x < w->mw)
		{
			if (w->world[0][x] == 0 || w->world[w->mh - 1][x] == 0
				|| w->world[y][x] > 8 || w->world[y][x] < 0)
				map_error();
			x++;
		}
		if (w->world[y][0] == 0 || w->world[y][w->mw - 1] == 0)
			map_error();
		y++;
	}
}

void	spawn(t_map *map, t_world *world)
{
	int x;
	int y;
	int i;
	int j;

	x = 0;
	y = 0;
	i = -1;
	while (++i < world->mh)
	{
		j = -1;
		while (++j < world->mw)
		{
			if (world->world[j][i] == 0)
			{
				y = i;
				x = j;
			}
		}
	}
	if (!x && !y)
		spawn_error();
	map->px = x + 0.5;
	map->py = y + 0.5;
}
