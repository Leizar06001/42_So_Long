/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:38:56 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/18 15:38:58 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

int	deal_key(int key, t_game *g)
{
	if ((key == DIR_LEFT || key == DIR_RIGHT
			|| key == DIR_UP || key == DIR_DOWN))
	{
		g->vals.next_dir = key;
		g->vals.key_pressed = 1;
	}
	if (key == ESCAPE)
		clean_quit(g);
	if (key == SPACE)
		init_game(g);
	return (key);
}

int	reset_key(int key, t_game *g)
{
	g->vals.key_pressed = 0;
	return (0);
}
