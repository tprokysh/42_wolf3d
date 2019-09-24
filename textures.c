/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 18:16:27 by tprokysh          #+#    #+#             */
/*   Updated: 2019/07/01 18:16:28 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_mlx	*untextured_color(t_mlx *mlx)
{
	mlx->texture[1]->color = 0xFF0000;
	mlx->texture[2]->color = 0xFF00A6;
	mlx->texture[3]->color = 0xAE00FF;
	mlx->texture[4]->color = 0x3300FF;
	mlx->texture[5]->color = 0x00BFFF;
	mlx->texture[6]->color = 0x00FF80;
	mlx->texture[7]->color = 0xEEFF00;
	mlx->texture[8]->color = 0x00FBFF;
	return (mlx);
}

t_img	*create_tex(char *t, t_mlx *m)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!(img->img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
			t, &img->tw, &img->th)))
		texture_error();
	img->data = (int *)mlx_get_data_addr(img->img_ptr,
			&img->bpp, &img->size_line, &img->endian);
	img->bpp /= 8;
	img->tw = img->size_line / img->bpp;
	img->th = img->size_line / img->bpp;
	return (img);
}

void	load_textures(t_mlx *m)
{
	int			i;
	char		*t;
	t_img		*img;
	static char	*textures[9] = {
			"wall3.xpm",
			"wall4.xpm",
			"wall5.xpm",
			"wall8.xpm",
			"wall2.xpm",
			"wall1.xpm",
			"wall6.xpm",
			"wall7.xpm" };

	i = 1;
	while (i < 9 && textures[i - 1])
	{
		t = ft_strjoin("textures/", textures[i - 1]);
		img = create_tex(t, m);
		m->texture[i] = img;
		ft_strdel(&t);
		i++;
	}
	m = untextured_color(m);
}
