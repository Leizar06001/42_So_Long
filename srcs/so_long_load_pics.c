/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_load_pics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:02:28 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/18 21:02:30 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

void	load_end_anim(t_game *g)
{
	g->pics.endanim[0] = get_xpm(g->vals.mlx, "img/bgd_end.xpm");
	g->pics.endanim[1] = get_xpm(g->vals.mlx, "img/end_anim0.xpm");
	g->pics.endanim[2] = get_xpm(g->vals.mlx, "img/end_anim1.xpm");
	g->pics.endanim[3] = get_xpm(g->vals.mlx, "img/end_anim2.xpm");
	g->pics.endanim[4] = get_xpm(g->vals.mlx, "img/end_anim3.xpm");
	g->pics.endanim[5] = get_xpm(g->vals.mlx, "img/end_anim4.xpm");
	g->pics.endanim[6] = get_xpm(g->vals.mlx, "img/end_anim5.xpm");
	g->pics.endanim[7] = get_xpm(g->vals.mlx, "img/end_anim6.xpm");
	g->pics.endanim[8] = get_xpm(g->vals.mlx, "img/end_anim7.xpm");
	g->pics.endanim[9] = get_xpm(g->vals.mlx, "img/end_anim8.xpm");
	g->pics.endanim[10] = get_xpm(g->vals.mlx, "img/end_anim9.xpm");
	g->pics.endanim[11] = get_xpm(g->vals.mlx, "img/end_anim10.xpm");
	g->pics.endanim[12] = get_xpm(g->vals.mlx, "img/end_anim11.xpm");
	g->pics.endanim[13] = get_xpm(g->vals.mlx, "img/end_anim12.xpm");
	g->pics.endanim[14] = get_xpm(g->vals.mlx, "img/end_anim13.xpm");
}

void	load_chars(t_game *g)
{
	g->pics.player[0] = get_xpm(g->vals.mlx, "img/alien1.xpm");
	g->pics.player[1] = get_xpm(g->vals.mlx, "img/alien2.xpm");
	g->pics.player[2] = get_xpm(g->vals.mlx, "img/alien3.xpm");
	g->pics.poupou[0] = get_xpm(g->vals.mlx, "img/poupour0.xpm");
	g->pics.poupou[1] = get_xpm(g->vals.mlx, "img/poupour1.xpm");
	g->pics.poupou[2] = get_xpm(g->vals.mlx, "img/poupour2.xpm");
	g->pics.poupou[3] = get_xpm(g->vals.mlx, "img/poupour3.xpm");
	g->pics.poupou[4] = get_xpm(g->vals.mlx, "img/poupour2.xpm");
	g->pics.poupou[5] = get_xpm(g->vals.mlx, "img/poupour1.xpm");
	g->pics.poupou[6] = get_xpm(g->vals.mlx, "img/poupoul0.xpm");
	g->pics.poupou[7] = get_xpm(g->vals.mlx, "img/poupoul1.xpm");
	g->pics.poupou[8] = get_xpm(g->vals.mlx, "img/poupoul2.xpm");
	g->pics.poupou[9] = get_xpm(g->vals.mlx, "img/poupoul3.xpm");
	g->pics.poupou[10] = get_xpm(g->vals.mlx, "img/poupoul2.xpm");
	g->pics.poupou[11] = get_xpm(g->vals.mlx, "img/poupoul1.xpm");
	g->pics.score[9] = get_xpm(g->vals.mlx, "img/nb_9.xpm");
	g->pics.score[10] = get_xpm(g->vals.mlx, "img/score.xpm");
}

void	load_walls(t_game *g)
{
	g->pics.walls[0] = get_xpm(g->vals.mlx, "img/wall_h.xpm");
	g->pics.walls[1] = get_xpm(g->vals.mlx, "img/wall_v.xpm");
	g->pics.walls[2] = get_xpm(g->vals.mlx, "img/wall_cross.xpm");
	g->pics.walls[3] = get_xpm(g->vals.mlx, "img/wall_c1.xpm");
	g->pics.walls[4] = get_xpm(g->vals.mlx, "img/wall_c2.xpm");
	g->pics.walls[5] = get_xpm(g->vals.mlx, "img/wall_c3.xpm");
	g->pics.walls[6] = get_xpm(g->vals.mlx, "img/wall_c4.xpm");
	g->pics.walls[7] = get_xpm(g->vals.mlx, "img/wall_t1.xpm");
	g->pics.walls[8] = get_xpm(g->vals.mlx, "img/wall_t2.xpm");
	g->pics.walls[9] = get_xpm(g->vals.mlx, "img/wall_t3.xpm");
	g->pics.walls[10] = get_xpm(g->vals.mlx, "img/wall_t4.xpm");
	g->pics.walls[11] = get_xpm(g->vals.mlx, "img/wall_e1.xpm");
	g->pics.walls[12] = get_xpm(g->vals.mlx, "img/wall_e2.xpm");
	g->pics.walls[13] = get_xpm(g->vals.mlx, "img/wall_e3.xpm");
	g->pics.walls[14] = get_xpm(g->vals.mlx, "img/wall_e4.xpm");
	g->pics.walls[15] = get_xpm(g->vals.mlx, "img/wall_0.xpm");
	g->pics.score[0] = get_xpm(g->vals.mlx, "img/nb_0.xpm");
	g->pics.score[1] = get_xpm(g->vals.mlx, "img/nb_1.xpm");
	g->pics.score[2] = get_xpm(g->vals.mlx, "img/nb_2.xpm");
	g->pics.score[3] = get_xpm(g->vals.mlx, "img/nb_3.xpm");
	g->pics.score[4] = get_xpm(g->vals.mlx, "img/nb_4.xpm");
	g->pics.score[5] = get_xpm(g->vals.mlx, "img/nb_5.xpm");
	g->pics.score[6] = get_xpm(g->vals.mlx, "img/nb_6.xpm");
	g->pics.score[7] = get_xpm(g->vals.mlx, "img/nb_7.xpm");
	g->pics.score[8] = get_xpm(g->vals.mlx, "img/nb_8.xpm");
}

int	load_pics(t_game *g)
{
	printf("# Loading pics\n");
	g->pics.bgd[0] = get_xpm(g->vals.mlx, "img/base0.xpm");
	g->pics.bgd[1] = get_xpm(g->vals.mlx, "img/base1.xpm");
	g->pics.bgd[2] = get_xpm(g->vals.mlx, "img/base2.xpm");
	g->pics.bgd[3] = get_xpm(g->vals.mlx, "img/base3.xpm");
	g->pics.flames[0] = get_xpm(g->vals.mlx, "img/flames0.xpm");
	g->pics.flames[1] = get_xpm(g->vals.mlx, "img/flames1.xpm");
	g->pics.flames[2] = get_xpm(g->vals.mlx, "img/flames2.xpm");
	g->pics.flames[3] = get_xpm(g->vals.mlx, "img/flames3.xpm");
	g->pics.portal[0] = get_xpm(g->vals.mlx, "img/end1.xpm");
	g->pics.portal[1] = get_xpm(g->vals.mlx, "img/end2.xpm");
	g->pics.portal[2] = get_xpm(g->vals.mlx, "img/end3.xpm");
	g->pics.item[0] = get_xpm(g->vals.mlx, "img/h2g2_0.xpm");
	g->pics.item[1] = get_xpm(g->vals.mlx, "img/h2g2_1.xpm");
	g->pics.item[2] = get_xpm(g->vals.mlx, "img/h2g2_2.xpm");
	g->pics.item[3] = get_xpm(g->vals.mlx, "img/h2g2_1.xpm");
	g->pics.gameover[0] = get_xpm(g->vals.mlx, "img/gameover0.xpm");
	g->pics.gameover[1] = get_xpm(g->vals.mlx, "img/gameover1.xpm");
	g->pics.gameover[2] = get_xpm(g->vals.mlx, "img/gameover2.xpm");
	g->pics.gameover[3] = get_xpm(g->vals.mlx, "img/gameover3.xpm");
	load_walls(g);
	load_chars(g);
	load_end_anim(g);
	return (0);
}
