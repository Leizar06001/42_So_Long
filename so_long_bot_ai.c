#include "so_long_lib.h"

void	reset_map_ai(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (++i < g->vals.h + 1)
	{
		j = 0;
		while (++j < g->vals.w + 1)
		{
			g->maps.tmp[i][j] = g->maps.main[i][j];
		}
	}
}

int	find_path(char **map, t_ai *ai)
{
	int	i;

	if (map[ai->y][ai->x] == 'P')
	{

	}
	map[ai->y][ai->x] = 'X';

	i = 0;
	if (map[ai->y][ai->x + 1] != '1' && map[ai->y][ai->x + 1] != 'X')
		find_path(map, ai);
	if (map[ai->y][ai->x - 1] != '1' && map[ai->y][ai->x - 1] != 'X')
		find_path(map, ai);
	if (map[ai->y + 1][ai->x] != '1' && map[ai->y + 1][ai->x] != 'X')
		find_path(map, ai);
	if (map[ai->y - 1][ai->x] != '1' && map[ai->y - 1][ai->x] != 'X')
		find_path(map, ai);
	return (0);
}

int	bot_ai_main(t_game *g, char bot)
{
	t_ai	ai;

	ai.x = g->vals.botx[bot][0];
	ai.y = g->vals.boty[bot][0];
	ai.steps = 0;
	ai.min_steps = 0;
	reset_map_ai(g);
	//find_path(g->maps.tmp, &ai);
}
