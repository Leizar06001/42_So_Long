/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_lib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:30:06 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/18 21:30:08 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_LIB_H
# define SO_LONG_LIB_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

# define TILE_W 		70
# define TILE_H 		70
# define MAP_W			10
# define MAP_H			5
# define DEC_H			140
# define DEC_W			20

# define ON_KEYDOWN 	2
# define ON_KEYUP 		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_EXPOSE		12
# define ON_NOEXPOSE	14
# define ON_DESTROY		17

# define DIR_LEFT		97 //97 / 113
# define DIR_RIGHT		100
# define DIR_DOWN		115
# define DIR_UP			119 //119 / 122
# define ESCAPE			65307
# define SPACE			32

# define NB_FRAMES_MOV	20.0
# define F_PER_TICK		100	//100 / 30

# define T_PLAYER_MOVE	6
# define T_POUPOU_MOVE	10

# define T_ANIM_LIGHTS	100
# define T_ANIM_FLAMES	10
# define T_ANIM_PORTAL	100
# define T_ANIM_ITEM	60
# define T_ANIM_POUPOU	30
# define T_GAMEOVER		200
# define T_WIN			120

typedef struct s_vals
{
	char				win_loaded;
	unsigned long long	frame;
	int					ticks;
	int					x[2];
	int					y[2];
	int					px;
	int					py;
	int					cur_mov;
	int					cur_bot[3];
	int					w;
	int					h;
	int					pw;
	int					ph;
	void				*mlx;
	void				*win;
	char				key_down;
	char				player_step;
	char				flames_step;
	char				portal_step;
	char				item_step;
	char				pou_step;
	char				poupou_pic;
	char				poupou_dir;
	char				gameover_pic;
	char				endanim_pic;
	int					botpx[3];
	int					botpy[3];
	int					botx[3][2];
	int					boty[3][2];
	char				bot_dir[3];
	int					bot_moving[3];
	char				bot_esc[3];
	int					exityx[2];
	int					exitpyx[2];
	char				moving;
	char				dir;
	char				next_dir;
	int					nb_items;
	int					tot_items;
	int					score;
	char				key_pressed;
	char				gameover;
	char				gamewin;
	char				(*items)[2];
	int					itm_test;
	char				exit_test;
	char				err;
	char				bgd_malloc;
	char				map_malloc;
	char				*map_path;
}	t_vals;

typedef struct s_maps
{
	char	**main;
	char	**bgd;
	char	**tmp;
}	t_maps;

typedef struct s_pics
{
	t_img	*bgd[4];
	t_img	*player[3];
	t_img	*flames[4];
	t_img	*walls[16];
	t_img	*portal[3];
	t_img	*item[4];
	t_img	*poupou[12];
	t_img	*score[11];
	t_img	*gameover[4];
	t_img	*endanim[15];
}	t_pics;

typedef struct s_game
{
	t_pics	pics;
	t_maps	maps;
	t_vals	vals;
}	t_game;

int		ft_putchar(char c);
char	*ft_strdup(const char *s);
int		clean_quit(t_game *g);
int		init_datas(t_vals *v);
int		init_datas_2(t_vals *v);
int		init_window(t_vals *v);
int		load_pics(t_game *g);
int		create_bgd(t_game *g);
int		check_move(t_game *g);
void	draw_walls(t_game *g);
void	draw_wall_1(t_game *g, int y, int x);
void	draw_wall_2(t_game *g, int y, int x);
void	draw_wall_3(t_game *g, int y, int x);
void	draw_wall_0_4(t_game *g, int y, int x, char cross);
void	draw_wall_pic(t_game *g, int y, int x, int pic);
int		load_map(t_game *g);
void	ft_bzero_char(void *s, size_t n);
void	ft_bzero(void *s, size_t n);
int		next_frame(t_game *g);
void	read_items(t_game *g);
int		move_player(t_game *g);
int		check_map(t_game *g);
void	free_ptr(void *ptr);
t_img	*get_xpm(void *mlx, char *p);
void	img_bgd(t_game *g, int x, int y);
void	img_coord(t_game *g, t_img *pic, int px, int py);
void	img_map(t_game *g, t_img *pic, int x, int y);
int		move_poupou_main(t_game *g);
int		move_poupou(t_game *g, int bot);
void	show_score(t_game *g);
int		deal_key(int key, t_game *g);
int		reset_key(int key, t_game *g);
void	win_screen(t_game *g, t_vals *v);
int		init_game(t_game *g);
void	show_bot_move(t_game *g, int bot);
int		move_items(t_game *g);
int		anim_lights_portal(t_game *g);
void	gameover_screen(t_game *g, t_vals *v);
void	init_bots(t_game *g);

#endif
