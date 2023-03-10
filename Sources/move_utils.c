/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 03:04:15 by rnait-el          #+#    #+#             */
/*   Updated: 2023/03/10 03:05:27 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	move(t_game *game, int move_x, int move_y)
{
	t_pos	pos;

	pos.next_pos = game->map_data[game->player_y + move_y] \
	[game->player_x + move_x];
	pos.last_pos = game->map_data[game->player_y][game->player_x];
	if (pos.next_pos == '0' || pos.next_pos == 'C' || pos.next_pos == 'P')
	{
		move_help(game, move_x, move_y, pos);
		game->player_x += move_x;
		game->player_y += move_y;
		put_img(game, SPRITE * game->player_x + move_x,
			SPRITE * game->player_y + move_y, game->img_player);
		game->moves_count++;
		ft_printf("Moves : %i\r", game->moves_count);
	}
	if (pos.next_pos == 'E')
		move_exit(game, pos.next_pos);
}

void	move_help(t_game *game, int move_x, int move_y, t_pos pos)
{
	if (pos.last_pos == 'E')
	{
		put_img(game, SPRITE * game->player_x, SPRITE * game->player_y,
			game->img_exit);
	}
	if (pos.last_pos != 'E')
	{
		put_img(game, SPRITE * game->player_x, SPRITE * game->player_y,
			game->img_floor);
	}
	if (pos.next_pos == 'C')
	{
		game->item_player++;
		game->map_data[game->player_y + move_y][game->player_x + move_x] = '0';
	}
}

int	check_unknownchar(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map_data[i])
	{
		while (game->map_data[i][j])
		{
			if (game->map_data[i][j] != 'P' && game->map_data[i][j] != 'E' \
			&& game->map_data[i][j] != '1' && game->map_data[i][j] != 'C' \
			&& game->map_data[i][j] != '0' && game->map_data[i][j] != '\n')
			{
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}
