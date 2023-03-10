/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mappath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 03:03:43 by rnait-el          #+#    #+#             */
/*   Updated: 2023/03/10 03:03:44 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
}

int	check_adjacent(t_game *game, int x, int y)
{
	char	**map;

	map = game->map_data;
	if (map[y][x] == 'P' || map[y][x] == 'E' || map[y][x] == 'C')
		game->count++;
	if (map[y][x] != '1' )
		map[y][x] = 'B';
	return (0);
}

void	recursive_check(t_game *game, int x, int y)
{
	char	**map;

	map = game->map_data;
	if (map[y][x] == '1' || map[y][x] == 'B' )
		return ;
	check_adjacent(game, x, y);
	recursive_check(game, x, y - 1);
	recursive_check(game, x + 1, y);
	recursive_check(game, x, y + 1);
	recursive_check(game, x - 1, y);
}

void	check_amount(t_game *game, int i, int j)
{
	if (game->count != game->coins + 2)
	{
		game->count = 0;
		recursive_check(game, j, i);
	}
}

void	check_valid_path(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	map = game->map_data;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				check_amount(game, i, j);
			j++;
		}
		i++;
	}
	if (game->count != game->coins + 2)
	{
		write(1, "Error\nMap has no valid path.\n", 30);
		close_window(game);
	}
	free_map(game->map_data);
	load_map(game, game->file);
}
