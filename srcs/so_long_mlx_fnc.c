/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_fnc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:03:42 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/13 20:03:43 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

t_img	*get_xpm(void *mlx, char *p)
{
	int	i;
	int	j;

	return (mlx_xpm_file_to_image(mlx, p, &i, &j));
}

void	img_map(t_game *g, t_img *pic, int x, int y)
{
	int	posx;
	int	posy;

	posx = x * TILE_W + DEC_W;
	posy = y * TILE_H + DEC_H;
	mlx_put_image_to_window(g->vals.mlx, g->vals.win, pic, posx, posy);
}

void	img_coord(t_game *g, t_img *pic, int px, int py)
{
	mlx_put_image_to_window(g->vals.mlx, g->vals.win, pic, px, py);
}

void	img_bgd(t_game *g, int x, int y)
{
	int		posx;
	int		posy;
	t_img	*pic;

	if (x > 0 && x < g->vals.w && y > 0 && y < g->vals.h)
	{
		posx = x * TILE_W + DEC_W;
		posy = y * TILE_H + DEC_H;
		pic = g->pics.bgd[g->maps.bgd[y][x]];
		mlx_put_image_to_window(g->vals.mlx, g->vals.win, pic, posx, posy);
	}
}
