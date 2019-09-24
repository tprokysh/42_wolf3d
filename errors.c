/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:53:18 by tprokysh          #+#    #+#             */
/*   Updated: 2019/02/15 18:19:59 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		map_error(void)
{
	ft_putstr(ANSI_COLOR_RED"Make sure the numbers "ANSI_COLOR_RED);
	ft_putstr(ANSI_COLOR_RED"on the map are"" from 0 to 8, it"ANSI_COLOR_RED);
	ft_putstr(ANSI_COLOR_RED" is square, map size <="ANSI_COLOR_RED);
	ft_putstr(ANSI_COLOR_RED" 500x500, there is no "ANSI_COLOR_RED);
	ft_putstr(ANSI_COLOR_RED"0 on the outer "ANSI_COLOR_RED);
	ft_putstr(ANSI_COLOR_RED"walls!\nUsage: ./wolf3d [map]\n"ANSI_COLOR_RED);
	exit(1);
	return (0);
}

int		texture_error(void)
{
	ft_putstr(ANSI_COLOR_RED"Can't find texture.xpm file!\n"ANSI_COLOR_RED);
	ft_putstr(ANSI_COLOR_RED"Usage: ./wolf3d [map]\n"ANSI_COLOR_RED);
	exit(1);
	return (0);
}

int		spawn_error(void)
{
	ft_putstr(ANSI_COLOR_RED"Not enought space for spawn!\n"ANSI_COLOR_RED);
	ft_putstr(ANSI_COLOR_RED"Usage: ./wolf3d [map]\n"ANSI_COLOR_RED);
	exit(1);
	return (0);
}

int		usage_error(void)
{
	ft_putstr(ANSI_COLOR_RED"Usage: ./wolf3d [map]\n"ANSI_COLOR_RED);
	exit(1);
	return (0);
}
