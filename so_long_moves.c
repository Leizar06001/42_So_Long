/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:03:53 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/13 20:03:54 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	show_score(t_game *g)
{
	int	x;
	int	y;

	x = g->vals.pw / 2 - 40;
	y = 47;
	img_coord(g, g->pics.score[g->vals.score / 100], x, y);
	img_coord(g, g->pics.score[g->vals.score % 100 / 10], x + 30, y);
	img_coord(g, g->pics.score[g->vals.score % 10], x + 60, y);
}

void	show_player_move(t_game *g)
{
	t_vals	*v;

	v = &g->vals;
	if (v->frame % T_ANIM_FLAMES == 0)
	{
		if (++v->flames_step > 3)
			v->flames_step = 0;
	}
	img_bgd(g, v->x[0], v->y[0]);
	img_bgd(g, v->x[1], v->y[1]);
	img_coord(g, g->pics.player[v->player_step], v->px, v->py);
	img_coord(g, g->pics.flames[v->flames_step], v->px, v->py + 48);
}

int	move_player(t_game *g)
{
	t_vals	*v;

	v = &g->vals;
	v->cur_mov += 1;
	if (v->dir == DIR_LEFT)
		v->px = v->x[0] * TILE_W - v->cur_mov / NB_FRAMES_MOV * TILE_W + DEC_W;
	else if (v->dir == DIR_RIGHT)
		v->px = v->x[0] * TILE_W + v->cur_mov / NB_FRAMES_MOV * TILE_W + DEC_W;
	else if (v->dir == DIR_DOWN)
		v->py = v->y[0] * TILE_H + v->cur_mov / NB_FRAMES_MOV * TILE_H + DEC_H;
	else if (v->dir == DIR_UP)
		v->py = v->y[0] * TILE_H - v->cur_mov / NB_FRAMES_MOV * TILE_H + DEC_H;
	show_player_move(g);
	if (v->cur_mov >= NB_FRAMES_MOV)
	{
		v->moving = 0;
		v->x[0] = v->x[1];
		v->y[0] = v->y[1];
		g->vals.score++;
		show_score(g);
	}
	return (0);
}

int	check_items(t_game *g)
{
	int	i;

	g->maps.main[g->vals.y[1] + 1][g->vals.x[1] + 1] = '0';
	i = -1;
	while (++i < g->vals.nb_items)
	{
		if (g->vals.items[i][0] == g->vals.y[1]
			&& g->vals.items[i][1] == g->vals.x[1])
		{
			g->vals.items[i][0] = g->vals.items[g->vals.nb_items - 1][0];
			g->vals.items[i][1] = g->vals.items[g->vals.nb_items - 1][1];
			break ;
		}
	}
	g->vals.nb_items--;
}

int	check_move(t_game *g)
{
	char	c;

	c = g->maps.main[g->vals.y[1] + 1][g->vals.x[1] + 1];
	if (c == '1')
	{
		g->vals.x[1] = g->vals.x[0];
		g->vals.y[1] = g->vals.y[0];
		return (0);
	}
	else if (c == 'C')
		check_items(g);
	else if (c == 'E')
	{
		if (g->vals.nb_items == 0)
			g->vals.gamewin = 1;
	}
	return (1);
}
