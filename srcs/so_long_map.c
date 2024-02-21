/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:03:00 by rloussig          #+#    #+#             */
/*   Updated: 2023/03/13 20:03:01 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib.h"

int	get_map_size(t_game *g, t_vals *v, char *path)
{
	int		fd;
	char	*line;

	v->h = 1;
	fd = open(path, O_RDONLY);
	if (fd < 1)
		return (4);
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (v->h == 1)
			v->w = ft_strlen(line);
		if (v->w != ft_strlen(line))
			free(line);
		if (v->w != ft_strlen(line))
			return (5);
		v->h++;
		free(line);
		line = get_next_line(fd);
	}
	v->h--;
	close(fd);
	return (0);
}

int	malloc_map(t_game *g)
{
	int	i;

	g->maps.main = (char **) malloc((g->vals.h + 2) * sizeof(char *));
	g->maps.tmp = (char **) malloc((g->vals.h + 2) * sizeof(char *));
	if (!g->maps.main || !g->maps.tmp)
		return (1);
	i = 0;
	while (i < g->vals.h + 2)
	{
		g->maps.main[i] = (char *) malloc((g->vals.w + 2) * sizeof(char));
		g->maps.tmp[i] = (char *) malloc((g->vals.w + 2) * sizeof(char));
		if (!g->maps.main[i] || !g->maps.tmp[i])
			return (1);
		ft_bzero_char(g->maps.main[i], g->vals.w + 2);
		ft_bzero_char(g->maps.tmp[i], g->vals.w + 2);
		i++;
	}
	g->vals.map_malloc = 1;
	return (0);
}

int	read_file(t_game *g, char *path)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line && ++i)
	{
		j = -1;
		while (++j < g->vals.w)
		{
			g->maps.main[i][j + 1] = line[j];
			if (line[j] == 'C')
				g->vals.tot_items++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}

int	load_map(t_game *g)
{
	ft_printf("# Loading map\n");
	g->vals.err = get_map_size(g, &g->vals, g->vals.map_path);
	if (g->vals.err)
		return (1);
	ft_printf(">  [%i : %i]\n", g->vals.h, g->vals.w);
	if (malloc_map(g) != 0)
	{
		ft_printf("### MALLOC ERROR ###\n");
		clean_quit(g);
	}
	read_file(g, g->vals.map_path);
	if (g->vals.tot_items > 0)
	{
		g->vals.nb_items = g->vals.tot_items;
		g->vals.items = malloc(g->vals.tot_items * sizeof(char [2]));
		if (!g->vals.items)
			clean_quit(g);
	}
	else
	{
		ft_printf("ERROR: There is not enough items in the loaded map !\n");
		clean_quit(g);
	}
	return (0);
}
