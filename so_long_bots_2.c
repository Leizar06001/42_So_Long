/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bots_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:03:00 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/18 21:03:01 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

int	move_poupou(t_game *g, int bot)
{
	t_vals	*v;

	v = &g->vals;
	v->cur_bot[bot] += 1;
	v->botpx[bot] = v->botx[bot][0] * TILE_W + DEC_W + (v->botx[bot][1]
			- v->botx[bot][0]) * TILE_W * v->cur_bot[bot] / NB_FRAMES_MOV;
	v->botpy[bot] = v->boty[bot][0] * TILE_H + DEC_H + (v->boty[bot][1]
			- v->boty[bot][0]) * TILE_H * v->cur_bot[bot] / NB_FRAMES_MOV;
	if (v->cur_bot[bot] >= NB_FRAMES_MOV)
	{
		v->bot_moving[bot] = 0;
		v->botx[bot][0] = v->botx[bot][1];
		v->boty[bot][0] = v->boty[bot][1];
	}
	show_bot_move(g, bot);
	return (0);
}
