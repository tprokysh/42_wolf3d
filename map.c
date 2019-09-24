/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 18:23:59 by tprokysh          #+#    #+#             */
/*   Updated: 2019/07/01 18:24:01 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			count_words(char *str, char s)
{
	int i;
	int words;
	int x;

	i = 0;
	words = 0;
	x = 0;
	while (str[i] && str[i] == s)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != s)
			i++;
		words++;
		while (str[i] && str[i] == s)
			i++;
	}
	if (words == 0)
		map_error();
	return (words);
}

int			count_worlds(char **av)
{
	char	*line;
	int		w;
	int		tmp;
	int		fd;
	int		i;

	w = 0;
	i = 0;
	if (!(fd = open(av[1], O_RDONLY)) || fd < 0)
		map_error();
	while (get_next_line(fd, &line))
	{
		tmp = w;
		w = count_words(line, ' ');
		if (tmp != w && i != 0)
			map_error();
		ft_strdel(&line);
		i++;
	}
	close(fd);
	return (w);
}

int			count_lines(char **av)
{
	char	*line;
	int		h;
	int		fd;
	int		ret;

	h = 0;
	if (!(fd = open(av[1], O_RDONLY)) || fd < 0)
		map_error();
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			map_error();
		h++;
		ft_strdel(&line);
	}
	if (h == 0)
		map_error();
	close(fd);
	return (h);
}

t_world		*new_map(int width, int height)
{
	t_world	*w;
	int		i;

	i = 0;
	w = (t_world *)malloc(sizeof(t_world));
	w->mw = width;
	w->mh = height;
	w->world = (int **)malloc(sizeof(int *) * width);
	while (i < height)
	{
		w->world[i] = (int *)malloc(sizeof(int) * height);
		i++;
	}
	return (w);
}

t_world		*fill_map(t_world *w, char **av)
{
	int		fd;
	char	*line;
	char	**tmp;
	int		y;
	int		x;

	y = 0;
	if (!(fd = open(av[1], O_RDONLY)))
		map_error();
	while (get_next_line(fd, &line))
	{
		x = -1;
		if (!(tmp = ft_strsplit(line, ' ')))
			map_error();
		while (++x < w->mw)
			w->world[y][x] = ft_atoi(tmp[x]);
		ft_splitdel(&tmp);
		ft_strdel(&line);
		y++;
	}
	check_number(w);
	close(fd);
	return (w);
}
