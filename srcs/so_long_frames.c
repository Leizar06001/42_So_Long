/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_frames.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:02:37 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/13 20:02:38 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	set_player_dir(t_game *g)
{
	if (!g->vals.moving && g->vals.key_pressed != 0)
	{
		g->vals.dir = g->vals.next_dir;
		g->vals.cur_mov = 0;
		g->vals.x[1] = g->vals.x[0];
		g->vals.y[1] = g->vals.y[0];
		if (g->vals.dir == DIR_LEFT)
			g->vals.x[1]--;
		else if (g->vals.dir == DIR_RIGHT)
			g->vals.x[1]++;
		else if (g->vals.dir == DIR_DOWN)
			g->vals.y[1]++;
		else if (g->vals.dir == DIR_UP)
			g->vals.y[1]--;
		g->vals.moving = check_move(g);
	}
}

int	win_or_lose(t_game *g)
{
	if (g->vals.gamewin)
	{
		if (g->vals.frame % T_WIN == 0)
			win_screen(g, &g->vals);
		return (1);
	}
	if (g->vals.gameover)
	{
		if (g->vals.frame % T_GAMEOVER == 0)
			gameover_screen(g, &g->vals);
		return (1);
	}
	return (0);
}

int	next_frame(t_game *g)
{
	g->vals.ticks++;
	if (g->vals.ticks >= F_PER_TICK)
	{
		g->vals.ticks = 0;
		g->vals.frame++;
		if (win_or_lose(g))
			return (1);
		set_player_dir(g);
		if (g->vals.frame % T_PLAYER_MOVE == 0 && g->vals.moving)
			move_player(g);
		if (g->vals.frame % T_ANIM_LIGHTS == 0)
			anim_lights_portal(g);
		if (g->vals.frame % T_ANIM_ITEM == 0)
			move_items(g);
		if (g->vals.frame % T_POUPOU_MOVE == 0)
			move_poupou_main(g);
		if (g->vals.frame % T_ANIM_POUPOU == 0 && ++g->vals.pou_step > 5)
			g->vals.pou_step = 0;
	}
	return (0);
}
