/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 03:04:04 by rnait-el          #+#    #+#             */
/*   Updated: 2023/03/10 03:04:39 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	init_run_game(t_game *game, char **argv)
{
	game->file = argv[1];
	game->item_player = 0;
	game->moves_count = 0;
	get_player_position(game);
	game->coins = count_coins(game->map_data);
	check_valid_path(game);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->map_width * SPRITE,
			game->map_height * SPRITE, "so_long");
	load_img(game);
	display_map(game);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, close_window, game);
	mlx_loop(game->mlx);
}

int	check_extension(char **argv)
{
	int	checker;

	checker = 0;
	if (argv[1][ft_strlen(argv[1]) - 4] != '.')
		checker = 1;
	if (argv[1][ft_strlen(argv[1]) - 3] != 'b')
		checker = 1;
	if (argv[1][ft_strlen(argv[1]) - 2] != 'e')
		checker = 1;
	if (argv[1][ft_strlen(argv[1]) - 1] != 'r')
		checker = 1;
	return (checker);
}

int	close_window(t_game *game)
{
	int	i;

	i = 0;
	if (game->map_data)
	{
		while (game->map_data[i])
		{
			free(game->map_data[i]);
			i++;
		}
		free(game->map_data);
	}
	exit(0);
}

int	check_argv(t_game *game, int ac, char **argv)
{
	if (ac != 2)
	{
		write(1, "Error\nUse <./so_long maps/mapx.ber>\n", 37);
		close_window(game);
	}
	if (check_extension(argv) == 1)
	{
		write(1, "Error\nMap has to be a <.ber> file.\n", 36);
		close_window(game);
	}
	return (0);
}

int	main(int ac, char **argv)
{
	t_game	game;

	game.map_data = NULL;
	check_argv(&game, ac, argv);
	if (get_map_width(&game, argv) == 1)
	{
		write(1, "Error\nPath to map incorrect or map empty.\n", 43);
		close_window(&game);
	}
	if (get_map_height(&game, argv) == 1)
	{
		write(1, "Error\nPath to map incorrect or map empty.\n", 43);
		close_window(&game);
	}
	if (load_map(&game, argv[1]) == 1)
	{
		write(1, "Error\nCalloc failed.\n", 22);
		close_window(&game);
	}
	game.item_count = 0;
	get_item_number(&game);
	if (!check_map(&game))
		close_window(&game);
	init_run_game(&game, argv);
}
