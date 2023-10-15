/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:02:26 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/13 20:02:28 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	draw_wall_pic(t_game *g, int y, int x, int pic)
{
	img_map(g, g->pics.walls[pic], x - 1, y - 1);
}

void	draw_wall_1(t_game *g, int y, int x)
{
	if (g->maps.main[y][x - 1] == '1')
		draw_wall_pic(g, y, x, 12);
	else if (g->maps.main[y - 1][x] == '1')
		draw_wall_pic(g, y, x, 13);
	else if (g->maps.main[y][x + 1] == '1')
		draw_wall_pic(g, y, x, 14);
	else if (g->maps.main[y + 1][x] == '1')
		draw_wall_pic(g, y, x, 11);
}

void	draw_wall_2(t_game *g, int y, int x)
{
	if (g->maps.main[y][x - 1] == '1' && g->maps.main[y][x + 1] == '1')
		draw_wall_pic(g, y, x, 0);
	else if (g->maps.main[y - 1][x] == '1' && g->maps.main[y + 1][x] == '1')
		draw_wall_pic(g, y, x, 1);
	else if (g->maps.main[y + 1][x] == '1' && g->maps.main[y][x + 1] == '1')
		draw_wall_pic(g, y, x, 3);
	else if (g->maps.main[y + 1][x] == '1' && g->maps.main[y][x - 1] == '1')
		draw_wall_pic(g, y, x, 4);
	else if (g->maps.main[y - 1][x] == '1' && g->maps.main[y][x - 1] == '1')
		draw_wall_pic(g, y, x, 5);
	else if (g->maps.main[y - 1][x] == '1' && g->maps.main[y][x + 1] == '1')
		draw_wall_pic(g, y, x, 6);
}

void	draw_wall_3(t_game *g, int y, int x)
{
	if (g->maps.main[y][x - 1] == '0')
		draw_wall_pic(g, y, x, 7);
	else if (g->maps.main[y - 1][x] == '0')
		draw_wall_pic(g, y, x, 8);
	else if (g->maps.main[y][x + 1] == '0')
		draw_wall_pic(g, y, x, 9);
	else if (g->maps.main[y + 1][x] == '0')
		draw_wall_pic(g, y, x, 10);
}

void	draw_wall_0_4(t_game *g, int y, int x, char cross)
{
	if (cross == 0)
		draw_wall_pic(g, y, x, 15);
	else
		draw_wall_pic(g, y, x, 2);
}
