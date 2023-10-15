/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:01:57 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/13 20:01:59 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	win_screen(t_game *g, t_vals *v)
{
	int	h;

	h = v->ph / 2 - 300;
	if (h < 140)
		h = 140;
	if (v->endanim_pic == 0)
	{
		img_coord(g, g->pics.endanim[0], v->pw / 2 - 400, h);
		v->endanim_pic++;
	}
	if (v->endanim_pic < 15)
	{
		img_coord(g, g->pics.endanim[v->endanim_pic], v->pw / 2 - 250, h + 100);
		v->endanim_pic++;
	}
}

void	errors(t_game *g)
{
	if (g->vals.err == 1)
		ft_printf("ERROR: Entrance or exit not defined in map !\n");
	else if (g->vals.err == 2)
		ft_printf("ERROR: The walls are not correctly defined in map !\n");
	else if (g->vals.err == 3)
		ft_printf("ERROR: The selected map as NO solution !\n");
	else if (g->vals.err == 4)
		ft_printf("ERROR: The selected map does not exists !\n");
	else if (g->vals.err == 5)
		ft_printf("ERROR: Map's lines size are not consistent !\n");
	clean_quit(g);
}

int	init_game(t_game *g)
{
	printf("\n\n# Initialization\n");
	init_datas(&g->vals);
	load_map(g);
	if (g->vals.err)
		errors(g);
	read_items(g);
	g->vals.err = check_map(g);
	if (g->vals.err)
		errors(g);
	init_bots(g);
	if (!g->vals.win_loaded)
	{
		init_window(&g->vals);
		load_pics(g);
	}
	create_bgd(g);
	draw_walls(g);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	g;
	void	*mlx;
	void	*win;

	g.vals.win_loaded = 0;
	g.vals.map_malloc = 0;
	g.vals.bgd_malloc = 0;
	if (argc > 1)
		g.vals.map_path = argv[1];
	else
		g.vals.map_path = "maps/2.ber";
	init_game(&g);
	g.vals.win_loaded = 1;
	mlx_hook(g.vals.win, ON_DESTROY, 0, clean_quit, &g);
	mlx_hook(g.vals.win, ON_KEYDOWN, 1, deal_key, &g);
	mlx_hook(g.vals.win, ON_KEYUP, 2, reset_key, &g);
	mlx_loop_hook(g.vals.mlx, next_frame, &g);
	ft_printf("# Entering game !\n");
	mlx_loop(g.vals.mlx);
	return (0);
}
