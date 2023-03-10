/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 03:04:28 by rnait-el          #+#    #+#             */
/*   Updated: 2023/03/10 03:04:47 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	get_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map_data[i])
	{
		while (game->map_data[i][j])
		{
			if (game->map_data[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	move_exit(t_game *game, char next_pos)
{
	if (next_pos == 'E')
	{
		if (check_if_all_collected(game) == 1)
		{
			game->moves_count++;
			ft_printf("Well done, is %i moves the best you can do?\n",
				game->moves_count);
			close_window(game);
		}
	}
}

void	key_process(int key, t_game *game)
{
	if (key == UP)
		move(game, 0, -1);
	if (key == DOWN)
		move(game, 0, +1);
	if (key == LEFT)
		move(game, -1, 0);
	if (key == RIGHT)
		move(game, +1, 0);
	if (key == ESC)
		close_window(game);
}

int	key_hook(int key, t_game *game)
{
	key_process(key, game);
	return (0);
}
