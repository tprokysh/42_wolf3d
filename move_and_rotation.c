/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 18:38:31 by tprokysh          #+#    #+#             */
/*   Updated: 2019/07/01 18:38:34 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		move_forward(t_mlx *m)
{
	double movex;
	double movey;
	double wall_x;
	double wall_y;

	movex = m->map->px + m->map->dx * m->speed;
	movey = m->map->py + m->map->dy * m->speed;
	if (m->map->px < movex)
		wall_x = 0.1;
	else
		wall_x = -0.1;
	if (m->map->py < movey)
		wall_y = 0.1;
	else
		wall_y = -0.1;
	if (movex < m->map->world->mw - 1.1 && movex > 1.1 &&
	(m->map->world->world)[
			(int)(movex + wall_x)][(int)(m->map->py)] == 0)
		m->map->px += m->map->dx * m->speed;
	if (movey < m->map->world->mw - 1.1 && movey > 1.1 &&
	(m->map->world->world)[
			(int)(m->map->px)][(int)(movey + wall_y)] == 0)
		m->map->py += m->map->dy * m->speed;
}

void		move_backward(t_mlx *m)
{
	double movex;
	double movey;
	double wall_x;
	double wall_y;

	movex = m->map->px - m->map->dx * m->speed;
	movey = m->map->py - m->map->dy * m->speed;
	if (m->map->px < movex)
		wall_x = 0.1;
	else
		wall_x = -0.1;
	if (m->map->py < movey)
		wall_y = 0.1;
	else
		wall_y = -0.1;
	if (movex < m->map->world->mh - 1.1 && movex > 1.1 &&
	(m->map->world->world)[
			(int)(movex + wall_x)][(int)m->map->py] == 0)
		m->map->px -= m->map->dx * m->speed;
	if (movey < m->map->world->mh - 1.1 && movey > 1.1 &&
	(m->map->world->world)[
			(int)(m->map->px)][(int)(movey + wall_y)] == 0)
		m->map->py -= m->map->dy * m->speed;
}

void		rotation_right(t_mlx *m)
{
	double	rot_angle;
	double	old_dir;
	double	old_plane_x;

	old_dir = m->map->dx;
	rot_angle = 0.03;
	m->map->dx = m->map->dx * cos(-rot_angle) - m->map->dy * sin(-rot_angle);
	m->map->dy = old_dir * sin(-rot_angle) + m->map->dy * cos(-rot_angle);
	old_plane_x = m->map->plx;
	m->map->plx = m->map->plx * cos(-rot_angle) - m->map->ply * sin(-rot_angle);
	m->map->ply = old_plane_x * sin(-rot_angle) + m->map->ply * cos(-rot_angle);
}

int			rotation_left(t_mlx *m)
{
	double	rot_angle;
	double	old_dir;
	double	old_plane_x;

	old_dir = m->map->dx;
	rot_angle = -0.03;
	m->map->dx = m->map->dx * cos(-rot_angle) - m->map->dy * sin(-rot_angle);
	m->map->dy = old_dir * sin(-rot_angle) + m->map->dy * cos(-rot_angle);
	old_plane_x = m->map->plx;
	m->map->plx = m->map->plx * cos(-rot_angle) - m->map->ply * sin(-rot_angle);
	m->map->ply = old_plane_x * sin(-rot_angle) + m->map->ply * cos(-rot_angle);
	return (0);
}
