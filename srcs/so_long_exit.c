/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:02:48 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/18 21:02:49 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	free_pics_2(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		mlx_destroy_image(g->vals.mlx, g->pics.portal[i]);
		mlx_destroy_image(g->vals.mlx, g->pics.player[i]);
	}
}

void	free_pics(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 15)
		mlx_destroy_image(g->vals.mlx, g->pics.endanim[i]);
	i = -1;
	while (++i < 16)
		mlx_destroy_image(g->vals.mlx, g->pics.walls[i]);
	i = -1;
	while (++i < 4)
	{
		mlx_destroy_image(g->vals.mlx, g->pics.bgd[i]);
		mlx_destroy_image(g->vals.mlx, g->pics.flames[i]);
		mlx_destroy_image(g->vals.mlx, g->pics.item[i]);
		mlx_destroy_image(g->vals.mlx, g->pics.gameover[i]);
	}
	i = -1;
	while (++i < 12)
		mlx_destroy_image(g->vals.mlx, g->pics.poupou[i]);
	i = -1;
	while (++i < 11)
		mlx_destroy_image(g->vals.mlx, g->pics.score[i]);
	free_pics_2(g);
}

void	clean_quit_2(t_game *g)
{
	int	i;

	if (g->vals.bgd_malloc)
	{
		i = -1;
		while (++i < g->vals.h)
			free_ptr(g->maps.bgd[i]);
		free_ptr(g->maps.bgd);
	}
	if (g->vals.map_malloc)
	{
		i = -1;
		while (++i < g->vals.h + 2)
			free_ptr(g->maps.main[i]);
		free_ptr(g->maps.main);
	}
	if (g->vals.tot_items > 0)
		free_ptr(g->vals.items);
}

int	clean_quit(t_game *g)
{
	int	i;

	ft_printf("## Clean ##\n");
	if (g->vals.win_loaded)
		free_pics(g);
	if (g->vals.win_loaded)
		mlx_destroy_window(g->vals.mlx, g->vals.win);
	if (g->vals.mlx)
		mlx_destroy_display(g->vals.mlx);
	free_ptr(g->vals.mlx);
	clean_quit_2(g);
	ft_printf("## Exit ##\n");
	exit(0);
	return (0);
}
