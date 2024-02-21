/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:02:46 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/13 20:02:47 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	init_bots(t_game *g)
{
	int		i;
	t_vals	*v;

	v = &g->vals;
	ft_printf("# Placing bots\n");
	i = -1;
	while (++i < 2)
	{
		while (1)
		{
			v->botx[i][0] = random() % v->w;
			v->boty[i][0] = random() % v->h;
			if (g->maps.main[v->boty[i][0] + 1][v->botx[i][0] + 1] == '0')
				break ;
			if (g->maps.main[v->boty[i][0] + 1][v->botx[i][0] + 1] == 'C')
				break ;
			if (g->maps.main[v->boty[i][0] + 1][v->botx[i][0] + 1] == 'E')
				break ;
		}
		ft_printf(">  Bot %i > %i:%i\n", i, v->boty[i][0], v->botx[i][0]);
	}
}

int	init_datas(t_vals *v)
{
	v->bot_moving[0] = 0;
	v->bot_moving[1] = 0;
	v->cur_bot[0] = 0;
	v->cur_bot[1] = 0;
	v->score = 0;
	v->key_pressed = 0;
	v->gameover = 0;
	v->gameover_pic = 0;
	v->gamewin = 0;
	v->endanim_pic = 0;
	v->itm_test = 0;
	v->exit_test = 0;
	v->nb_items = 0;
	v->tot_items = 0;
}

int	init_datas_2(t_vals *v)
{
	v->frame = 0;
	v->ticks = 0;
	v->pw = v->w * TILE_W + DEC_W * 2;
	v->ph = v->h * TILE_H + 20 + DEC_H;
	v->px = v->x[0] * TILE_W + DEC_W;
	v->py = v->y[0] * TILE_H + DEC_H;
	v->player_step = 0;
	v->flames_step = 0;
	v->portal_step = 0;
	v->item_step = 0;
	v->pou_step = 0;
	v->moving = 0;
	v->dir = 0;
	return (1);
}

int	init_window(t_vals *v)
{
	ft_printf("# Create mlx\n");
	v->mlx = mlx_init();
	ft_printf("# Create win\n");
	ft_printf(">  [%i : %i]\n", v->ph, v->pw);
	v->win = mlx_new_window(v->mlx, v->pw, v->ph, "So Long");
	return (0);
}
