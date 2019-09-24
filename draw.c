/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 18:37:40 by tprokysh          #+#    #+#             */
/*   Updated: 2019/07/01 18:37:41 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_textured_floor(int x, int y, t_mlx *mlx, t_map *m)
{
	int color;

	color = ((int *)mlx->texture[4]->data)[TEXW * m->floortx + m->floorty];
	((int *)mlx->data)[y * WIDTH + x] = color;
	color = ((int *)mlx->texture[3]->data)[TEXW * m->floortx + m->floorty];
	((int *)mlx->data)[(HEIGHT - y) * WIDTH + x] = color;
}

void	draw_floor1(t_mlx *mlx, t_map *m, int x)
{
	int y;

	m->dstw = m->pwd;
	m->dstp = 0.0;
	if (m->drawe < 0)
		m->drawe = HEIGHT;
	y = m->drawe;
	while (y < HEIGHT)
	{
		m->dstc = HEIGHT / (2.0 * y - HEIGHT);
		m->weight = (m->dstc - m->dstp) / (m->dstw - m->dstp);
		m->cfloorx = m->weight * m->floorx + (1.0 - m->weight) * m->px;
		m->cfloory = m->weight * m->floory + (1.0 - m->weight) * m->py;
		m->floortx = (int)(m->cfloorx * TEXW) % TEXW;
		m->floorty = (int)(m->cfloory * TEXW) % TEXW;
		if (!mlx->textured)
		{
			((int *)mlx->data)[y * WIDTH + x] = 0x636363;
			((int *)mlx->data)[(HEIGHT - y) * WIDTH + x] = 0xC7C7C7;
		}
		else
			draw_textured_floor(x, y, mlx, m);
		y++;
	}
}

void	draw_floor(t_mlx *mlx, t_map *m, int x)
{
	int y;
	int color;

	if (m->side == 0 && m->rdx > 0)
	{
		m->floorx = m->mx;
		m->floory = m->my + m->wallx;
	}
	else if (m->side == 0 && m->rdx < 0)
	{
		m->floorx = m->mx + 1.0;
		m->floory = m->my + m->wallx;
	}
	else if (m->side == 1 && m->rdy > 0)
	{
		m->floorx = m->mx + m->wallx;
		m->floory = m->my;
	}
	else
	{
		m->floorx = m->mx + m->wallx;
		m->floory = m->my + 1.0;
	}
	draw_floor1(mlx, m, x);
}

void	draw_textured_wall(int x, int y, t_map *map, t_mlx *mlx)
{
	int color;
	int d;

	d = y * 256 - HEIGHT * 128 + map->lineh * 128;
	if (map->side == 0 && map->world->world[map->mx][map->my] + 1 <= 8)
		color = ((int *)mlx->texture
				[map->world->world[map->mx][map->my] + 1]->data)
		[TEXW * map->tex_y + map->tex_x];
	if (map->side == 0 && map->world->world[map->mx][map->my] == 8)
		color = ((int *)mlx->texture
				[map->world->world[map->mx][map->my] - 1]->data)
		[TEXW * map->tex_y + map->tex_x];
	if (map->side == 1)
	{
		color = ((int *)mlx->texture[map->world->world[map->mx][map->my]]->data)
		[TEXW * map->tex_y + map->tex_x];
		color = (color >> 1) & 8355711;
	}
	((int *)mlx->data)[y * WIDTH + x] = color;
}

void	draw_wall(t_mlx *mlx, t_map *map, int x)
{
	int y;
	int d;
	int color;

	if (map->hit == 0)
		return ;
	y = map->draws - 1;
	while (++y < map->drawe + 1)
	{
		d = y * 256 - HEIGHT * 128 + map->lineh * 128;
		map->tex_y = ((d * TEXW) / map->lineh) / 256;
		if (!mlx->textured)
		{
			color = mlx->texture[map->world->world[map->mx][map->my]]->color;
			if (map->side == 1)
				color = (color >> 1) & 8355711;
			((int *)mlx->data)[y * WIDTH + x] = color;
		}
		else
			draw_textured_wall(x, y, map, mlx);
	}
}
