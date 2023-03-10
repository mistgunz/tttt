/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 03:03:54 by rnait-el          #+#    #+#             */
/*   Updated: 2023/03/10 03:03:55 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	put_img(t_game *game, int x, int y, void *img)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x, y);
}

void	load_img(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"./includes/sprites/player.xpm", &game->img_x, &game->img_y);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./includes/sprites/wall.xpm", &game->img_x, &game->img_y);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"./includes/sprites/background.xpm", &game->img_x, &game->img_y);
	game->img_item = mlx_xpm_file_to_image(game->mlx,
			"./includes/sprites/collectable.xpm", &game->img_x, &game->img_y);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"./includes/sprites/exit.xpm", &game->img_x, &game->img_y);
}

int	count_coins(char **map)
{
	int	i;
	int	j;
	int	coins;

	coins = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	return (coins);
}
