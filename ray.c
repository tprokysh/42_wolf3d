/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 18:32:55 by tprokysh          #+#    #+#             */
/*   Updated: 2019/07/01 18:32:56 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_map(t_mlx *mlx, t_map *map)
{
	int x;

	x = -1;
	while (++x < WIDTH)
	{
		map = init_val(map, x);
		map = calc(map);
		draw_wall(mlx, map, x);
		draw_floor(mlx, map, x);
	}
	minimap(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	help(mlx);
}

t_map	*calc1(t_map *map)
{
	map->wallx = map->side == 0 ? map->py + map->pwd *
			map->rdy : map->px + map->pwd * map->rdx;
	map->wallx -= floor((map->wallx));
	map->tex_x = (int)(map->wallx * (double)(TEXW));
	if (map->side == 0 && map->rdx > 0)
		map->tex_x = TEXW - map->tex_x - 1;
	return (map);
}

t_map	*calc(t_map *map)
{
	while (map->hit == 0)
	{
		if (map->sdx < map->sdy)
		{
			map->sdx += map->ddx;
			map->mx += map->stx;
			map->side = 0;
		}
		else
		{
			map->sdy += map->ddy;
			map->my += map->sty;
			map->side = 1;
		}
		map->world->world[map->mx][map->my] > 0 ? map->hit = 1 : 0;
		map->pwd = map->side == 0 ? (map->mx - map->px + (1 - map->stx) / 2) /
				map->rdx : (map->my - map->py + (1 - map->sty) / 2) / map->rdy;
		map->lineh = (int)(HEIGHT / map->pwd);
		map->draws = -map->lineh / 2 + HEIGHT / 2;
		map->draws < 0 ? map->draws = 0 : 0;
		map->drawe = map->lineh / 2 + HEIGHT / 2;
		map->drawe >= HEIGHT ? map->drawe = HEIGHT - 1 : 0;
	}
	map = calc1(map);
	return (map);
}

t_map	*init_val(t_map *map, int x)
{
	map->cx = 2 * x / (double)WIDTH - 1;
	map->rpx = map->px;
	map->rpy = map->py;
	map->rdx = map->dx + map->plx * map->cx;
	map->rdy = map->dy + map->ply * map->cx;
	map->mx = (int)map->rpx;
	map->my = (int)map->rpy;
	map->ddx = sqrt(1 + (map->rdy * map->rdy) / (map->rdx * map->rdx));
	map->ddy = sqrt(1 + (map->rdx * map->rdx) / (map->rdy * map->rdy));
	map->hit = 0;
	map->side = 0;
	map->stx = map->rdx < 0 ? -1 : 1;
	map->sdx = map->rdx < 0 ? (map->px - map->mx) * map->ddx :
			(map->mx + 1.0 - map->px) * map->ddx;
	map->sty = map->rdy < 0 ? -1 : 1;
	map->sdy = map->rdy < 0 ? (map->py - map->my) * map->ddy :
			(map->my + 1.0 - map->py) * map->ddy;
	return (map);
}
