/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 18:39:14 by tprokysh          #+#    #+#             */
/*   Updated: 2019/07/01 18:39:16 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		key_off(int keycode, t_mlx *m)
{
	if (keycode == 13)
		m->mw = 0;
	if (keycode == 0)
		m->ma = 0;
	if (keycode == 1)
		m->ms = 0;
	if (keycode == 2)
		m->md = 0;
	if (keycode == 257)
		m->speedup = 0;
	return (0);
}

int		key_on(int keycode, t_mlx *m)
{
	if (keycode == 13)
		m->mw = 1;
	if (keycode == 0)
		m->ma = 1;
	if (keycode == 1)
		m->ms = 1;
	if (keycode == 2)
		m->md = 1;
	if (keycode == 53)
		m->close = 1;
	if (keycode == 257)
		m->speedup = 1;
	if (keycode == 17)
		m->textured = !m->textured;
	if (keycode == 4)
		m->help = !m->help;
	return (0);
}

int		keys(t_mlx *m)
{
	if (m->mw == 1)
		move_forward(m);
	if (m->ms == 1)
		move_backward(m);
	if (m->ma == 1)
		rotation_left(m);
	if (m->md == 1)
		rotation_right(m);
	if (m->close == 1)
		close_wolf(m);
	if (m->speedup == 0)
		m->speed = 0.04f;
	if (m->speedup == 1)
		m->speed = 0.08f;
	draw_map(m, m->map);
	return (0);
}
