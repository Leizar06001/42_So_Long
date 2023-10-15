/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_anims.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:06:01 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/18 21:06:02 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	show_bot_move(t_game *g, int bot)
{
	t_vals	*v;

	v = &g->vals;
	img_bgd(g, v->botx[bot][0], v->boty[bot][0]);
	img_bgd(g, v->botx[bot][1], v->boty[bot][1]);
	img_coord(g, g->pics.poupou[v->pou_step + v->bot_dir[bot]],
		v->botpx[bot], v->botpy[bot]);
}

int	move_items(t_game *g)
{
	int		n;
	t_vals	*v;

	v = &g->vals;
	if (++v->item_step > 3)
		v->item_step = 0;
	n = -1;
	while (++n < v->nb_items)
		img_map(g, g->pics.item[v->item_step], v->items[n][1],
			v->items[n][0]);
	return (0);
}

int	anim_lights_portal(t_game *g)
{
	t_vals	*v;

	v = &g->vals;
	if (++v->player_step > 2)
		v->player_step = 0;
	if (++v->portal_step > 2)
		v->portal_step = 0;
	img_coord(g, g->pics.player[v->player_step], v->px, v->py);
	img_coord(g, g->pics.portal[v->portal_step], v->exitpyx[1], v->exitpyx[0]);
	return (0);
}

void	gameover_screen(t_game *g, t_vals *v)
{
	if (++v->gameover_pic > 3)
		v->gameover_pic = 0;
	img_coord(g, g->pics.gameover[v->gameover_pic],
		v->pw / 2 - 300, v->ph / 2 - 200);
}
