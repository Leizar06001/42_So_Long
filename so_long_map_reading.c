/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_reading.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:03:14 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/13 20:03:15 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

int	walls_check(t_game *g)
{
	int	i;

	i = -1;
	while (++i < g->vals.w)
	{
		if (g->maps.main[1][i + 1] != '1'
			|| g->maps.main[g->vals.h][i + 1] != '1')
			return (1);
	}
	i = -1;
	while (++i < g->vals.h)
	{
		if (g->maps.main[i + 1][1] != '1'
			|| g->maps.main[i + 1][g->vals.w] != '1')
			return (1);
	}
	return (0);
}

int	pe_check(t_game *g, char *checks)
{
	int	i;
	int	j;

	ft_bzero(checks, 3);
	i = 0;
	while (++i < g->vals.h)
	{
		j = 0;
		while (++j < g->vals.w)
		{
			if (g->maps.main[i][j] == 'P')
			{
				checks[0]++;
				g->vals.x[0] = j - 1;
				g->vals.y[0] = i - 1;
			}
			else if (g->maps.main[i][j] == 'E')
			{
				checks[1]++;
				g->vals.exityx[1] = (j - 1);
				g->vals.exityx[0] = (i - 1);
			}
		}
	}
	return ((checks[0] == 1) + (checks[1] == 1));
}

void	reset_map(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->vals.h + 2)
	{
		j = -1;
		while (++j < g->vals.w + 2)
		{
			if (g->maps.main[i][j] == 'X')
				g->maps.main[i][j] = '0';
		}
	}
	i = -1;
	while (++i < g->vals.tot_items)
		g->maps.main[g->vals.items[i][0] + 1][g->vals.items[i][1] + 1] = 'C';
	g->maps.main[g->vals.y[0] + 1][g->vals.x[0] + 1] = 'P';
	g->maps.main[g->vals.exityx[0] + 1][g->vals.exityx[1] + 1] = 'E';
}

int	check_path(t_game *g, int x, int y)
{
	int	i;

	if (g->maps.main[y][x] == 'C')
		g->vals.itm_test++;
	else if (g->maps.main[y][x] == 'E')
		g->vals.exit_test = 1;
	g->maps.main[y][x] = 'X';
	i = 0;
	if (g->maps.main[y][x + 1] != '1' && g->maps.main[y][x + 1] != 'X')
		check_path(g, x + 1, y);
	if (g->maps.main[y][x - 1] != '1' && g->maps.main[y][x - 1] != 'X')
		check_path(g, x - 1, y);
	if (g->maps.main[y + 1][x] != '1' && g->maps.main[y + 1][x] != 'X')
		check_path(g, x, y + 1);
	if (g->maps.main[y - 1][x] != '1' && g->maps.main[y - 1][x] != 'X')
		check_path(g, x, y - 1);
	return (0);
}

int	check_map(t_game *g)
{
	char	checks[3];

	ft_printf("# Checking map\n");
	if (pe_check(g, checks) != 2)
		return (1);
	ft_printf(">  Player & Exit found\n");
	g->vals.exitpyx[1] = (g->vals.exityx[1]) * TILE_W + DEC_W;
	g->vals.exitpyx[0] = (g->vals.exityx[0]) * TILE_H + DEC_H;
	if (walls_check(g) != 0)
		return (2);
	ft_printf(">  Walls correct\n");
	init_datas_2(&g->vals);
	check_path(g, g->vals.x[0] + 1, g->vals.y[0] + 1);
	ft_printf(">  Items : %i/%i - Exit clear : %i\n",
		g->vals.itm_test, g->vals.tot_items, g->vals.exit_test);
	if (g->vals.itm_test != g->vals.tot_items || g->vals.exit_test != 1)
		return (3);
	ft_printf(">>  Path found in current map !\n");
	reset_map(g);
	return (0);
}
