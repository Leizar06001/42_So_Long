/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:02:12 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/13 20:02:14 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

int	create_bgd(t_game *g)
{
	int	i;
	int	j;

	ft_printf("# Mapping background\n");
	g->maps.bgd = (char **)malloc(g->vals.h * sizeof(char *));
	if (!g->maps.bgd)
		return (0);
	i = 0;
	while (i < g->vals.h)
	{
		g->maps.bgd[i] = (char *)malloc(g->vals.w * sizeof(char));
		if (!g->maps.bgd[i])
			return (0);
		j = 0;
		while (j < g->vals.w)
		{
			g->maps.bgd[i][j] = rand() % 4;
			img_bgd(g, j, i);
			j++;
		}
		i++;
	}
	return (0);
}

void	read_items(t_game *g)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	i = 0;
	while (++i < g->vals.h + 1)
	{
		j = 0;
		while (++j < g->vals.w + 1)
		{
			if (g->maps.main[i][j] == 'C')
			{
				g->vals.items[n][0] = i - 1;
				g->vals.items[n][1] = j - 1;
				n++;
			}
		}
	}
	g->vals.nb_items = n;
}

int	count_side_walls(t_game *g, int i, int j)
{
	int	n;

	n = (g->maps.main[i - 1][j] == '1');
	n += (g->maps.main[i + 1][j] == '1');
	n += (g->maps.main[i][j + 1] == '1');
	n += (g->maps.main[i][j - 1] == '1');
	return (n);
}

void	draw_score_display(t_game *g)
{
	int	i;

	i = -1;
	while (++i * TILE_W < g->vals.pw)
		img_coord(g, g->pics.walls[0], i * TILE_W, 30);
	img_coord(g, g->pics.score[10], g->vals.pw / 2 - 105, 15);
	show_score(g);
}

void	draw_walls(t_game *g)
{
	int	i;
	int	j;
	int	links;

	i = 0;
	while (++i < g->vals.h + 1)
	{
		j = 0;
		while (++j < g->vals.w + 1)
		{
			if (g->maps.main[i][j] == '1')
			{
				links = count_side_walls(g, i, j);
				if (links == 1)
					draw_wall_1(g, i, j);
				else if (links == 2)
					draw_wall_2(g, i, j);
				else if (links == 3)
					draw_wall_3(g, i, j);
				else
					draw_wall_0_4(g, i, j, links);
			}
		}
	}
	draw_score_display(g);
}
