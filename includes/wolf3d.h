/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:38:28 by tprokysh          #+#    #+#             */
/*   Updated: 2019/07/03 13:38:29 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF3D_H
# define WOLF3D_WOLF3D_H

# include <mlx.h>
# include "../libft/includes/libft.h"
# include <math.h>
# include <fcntl.h>
# include <time.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# define WIDTH 1250
# define HEIGHT 750
# define ANSI_COLOR_RED "\x1b[31m"
# define TEXW 64

typedef struct			s_win
{
	void				*mlx;
	void				*win;
	void				*image;
	char				*line;
	unsigned int		color;
}						t_win;

typedef	struct			s_img
{
	void				*img_ptr;
	int					*data;
	int					tw;
	int					th;
	int					bpp;
	int					size_line;
	int					endian;
	int					color;
}						t_img;

typedef struct			s_world
{
	int					**world;
	int					mw;
	int					mh;
}						t_world;

typedef struct			s_map
{
	float				dx;
	float				dy;
	float				plx;
	float				ply;
	float				rdx;
	float				rdy;
	float				cx;
	int					mx;
	int					my;
	float				px;
	float				py;
	double				sdx;
	double				sdy;
	double				ddx;
	double				ddy;
	double				rpx;
	double				rpy;
	int					stx;
	int					sty;
	int					hit;
	int					side;
	double				pwd;
	int					lineh;
	int					draws;
	int					drawe;
	double				wallx;
	int					tex_x;
	int					tex_y;
	double				floorx;
	double				floory;
	double				dstw;
	double				dstp;
	double				dstc;
	double				weight;
	double				cfloorx;
	double				cfloory;
	int					floortx;
	int					floorty;
	t_img				*texture;
	t_world				*world;
}						t_map;

typedef struct			s_rgba
{
	uint8_t				b;
	uint8_t				g;
	uint8_t				r;
	uint8_t				a;
}						t_rgba;

typedef union			u_color
{
	int					value;
	t_rgba				rgba;
}						t_color;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	void				*img_ptrtex;
	int					*data;
	char				*datatex;
	int					bpp;
	int					size_line;
	int					endian;
	int					mw;
	int					ma;
	int					ms;
	int					md;
	int					speedup;
	int					close;
	int					spawn;
	float				speed;
	int					textured;
	int					help;
	t_map				*map;
	t_img				*texture[8];
	t_world				*world;
}						t_mlx;

t_world					*init_world(char **av);
int						keys(t_mlx *m);
int						rotation_left(t_mlx *m);
void					rotation_right(t_mlx *m);
void					move_backward(t_mlx *m);
void					move_forward(t_mlx *m);
int						move_char(t_mlx *m);
int						ft_splitdel(char ***split);
t_map					*init_val(t_map *map, int x);
t_map					*calc(t_map *map);
void					draw_map(t_mlx *mlx, t_map *map);
void					draw_wall(t_mlx *mlx, t_map *map, int x);
void					draw_floor(t_mlx *mlx, t_map *map, int x);
t_world					*fill_map(t_world *w, char **av);
t_world					*new_map(int width, int height);
int						count_lines(char **av);
int						count_worlds(char **av);
int						count_words(char *str, char s);
void					load_textures(t_mlx *m);
t_img					*create_tex(char *t, t_mlx *m);
t_mlx					*init_mlx(t_mlx *m);
t_map					*init_map(t_map *m, t_world *w);
void					init_img(int f, t_mlx *m);
void					spawn(t_map *map, t_world *world);
int						key_on(int keycode, t_mlx *m);
int						key_off(int keycode, t_mlx *m);
int						keycodes(int keycode, t_mlx *m);
void					check_number(t_world *w);
int						map_error(void);
int						spawn_error(void);
int						texture_error(void);
int						close_wolf(t_mlx *m);
int						usage_error(void);
void					minimap(t_mlx *mlx);
void					minimap_draw(int x, int y, int color, t_mlx *mlx);
void					help(t_mlx *m);

#endif
