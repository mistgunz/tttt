/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 03:03:28 by rnait-el          #+#    #+#             */
/*   Updated: 2023/03/10 03:03:49 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	check_if_all_collected(t_game *game)
{
	if (game->item_player == game->item_count)
		return (1);
	return (0);
}

int	check_map_rectangular(t_game *game)
{
	int	line_lenght;
	int	i;
	int	j;

	line_lenght = game->map_width;
	i = 1;
	while (i < game->map_height)
	{
		j = 0;
		while (game->map_data[i][j] && game->map_data[i][j] != '\n')
		{
			j++;
		}
		if (j != line_lenght)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map_borders(t_game *game)
{
	int	i;

	i = game->map_width;
	while (i--)
		if (game->map_data[0][i] != '1' ||
				game->map_data[game->map_height - 1][i] != '1')
			return (0);
	i = game->map_height;
	while (i--)
		if (game->map_data[i][0] != '1' ||
				game->map_data[i][game->map_width - 1] != '1')
			return (0);
	return (1);
}

int	check_map_elements(t_game *game)
{
	int	player;
	int	exit;
	int	i;
	int	j;

	player = 0;
	exit = 0;
	i = 0;
	j = 0;
	while (game->map_data[i])
	{
		while (game->map_data[i][j])
		{
			if (game->map_data[i][j] == 'P')
				player++;
			else if (game->map_data[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
		j = 0;
	}
	if (game->item_count == 0 || player != 1 || exit != 1)
		return (0);
	return (1);
}

int	check_map(t_game *game)
{
	if (!check_map_rectangular(game))
	{
		write(1, "Error\nMap has to be rectangular.\n", 34);
		return (0);
	}
	if (!check_map_borders(game))
	{
		write(1, "Error\nMap has to be surrounded by walls.\n", 42);
		return (0);
	}
	if (!check_map_elements(game))
	{
		write(1, "Error\nMap must contain ONE player, ", 36);
		write(1, "ONE exit, and at least ONE item.\n", 34);
		return (0);
	}
	if (!check_unknownchar(game))
	{
		write(1, "Error\nUse only : 1, 0, C, P and E to build your map.\n", 54);
		return (0);
	}
	return (1);
}
