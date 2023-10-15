/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bots.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:03:00 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/18 21:03:01 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

int	check_wall(int bot, int incx, int incy, t_game *g)
{
	t_vals	*v;
	t_maps	*m;

	v = &g->vals;
	m = &g->maps;
	if (incx != 0)
	{
		if (incx > 0)
			v->bot_dir[bot] = 0;
		else
			v->bot_dir[bot] = 6;
		if (m->main[v->boty[bot][0] + 1][v->botx[bot][0] + 1 + incx] != '1')
			return (1);
	}
	if (incy != 0)
	{
		if (m->main[v->boty[bot][0] + 1 + incy][v->botx[bot][0] + 1] != '1')
			return (1);
	}
	return (0);
}

int	find_player_dir(t_game *g, t_maps *m, int bot)
{
	t_vals	*v;

	v = &g->vals;
	v->botx[bot][1] = v->botx[bot][0];
	v->boty[bot][1] = v->boty[bot][0];
	if (v->x[0] < v->botx[bot][0] && check_wall(bot, -1, 0, g))
		v->botx[bot][1] = v->botx[bot][0] - 1;
	else if (v->x[0] > v->botx[bot][0] && check_wall(bot, 1, 0, g))
		v->botx[bot][1] = v->botx[bot][0] + 1;
	else if (v->y[0] < v->boty[bot][0] && check_wall(bot, 0, -1, g))
		v->boty[bot][1] = v->boty[bot][0] - 1;
	else if (v->y[0] > v->boty[bot][0] && check_wall(bot, 0, 1, g))
		v->boty[bot][1] = v->boty[bot][0] + 1;
	else
	{
		v->bot_esc[bot] = 3;
		return (0);
	}
	return (1);
}

int	check_gameover(t_vals *v, int bot)
{
	if (v->botx[bot][1] == v->x[0] && v->boty[bot][1] == v->y[0])
	{
		v->gameover = 1;
		return (1);
	}
	return (0);
}

int	find_random_dir(t_game *g, char bot)
{
	int		i;
	char	dirx;
	char	diry;

	i = -1;
	while (++i < 100)
	{
		diry = 0;
		dirx = random() % 3 - 1;
		if (dirx == 0)
		{
			while (diry == 0)
				diry = random() % 3 - 1;
		}
		if (check_wall(bot, dirx, diry, g))
		{
			g->vals.botx[bot][1] = g->vals.botx[bot][0] + dirx;
			g->vals.boty[bot][1] = g->vals.boty[bot][0] + diry;
			break ;
		}
	}
	return (0);
}

int	move_poupou_main(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		if (!g->vals.bot_moving[i] && g->vals.bot_esc[i])
		{
			find_random_dir(g, i);
			g->vals.bot_esc[i]--;
			g->vals.bot_moving[i] = 1;
			g->vals.cur_bot[i] = 0;
		}
		else if (!g->vals.bot_moving[i] && find_player_dir(g, &g->maps, i))
		{
			g->vals.cur_bot[i] = 0;
			g->vals.bot_moving[i] = 1;
		}
		move_poupou(g, i);
		if (check_gameover(&g->vals, i))
			break ;
	}
	return (0);
}
