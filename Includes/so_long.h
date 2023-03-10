/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 03:06:23 by rnait-el          #+#    #+#             */
/*   Updated: 2023/03/10 03:06:38 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SPRITE 64
# define UP			13
# define DOWN		1
# define LEFT		0
# define RIGHT	2
# define ESC		53

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map_data;
	int		map_height;
	int		map_width;
	int		player_x;
	int		player_y;
	int		item_count;
	int		item_player;
	int		moves_count;
	void	*img_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_item;
	void	*img_exit;
	int		img_x;
	int		img_y;
	int		count;
	int		coins;
	char	*file;
}				t_game;

typedef struct s_pos
{
	char	next_pos;
	char	last_pos;
}				t_pos;

void	init_run_game(t_game *game, char **argv);
int		check_argv(t_game *game, int argc, char **argv);
void	put_img(t_game *game, int x, int y, void *img);
void	load_img(t_game *game);
int		get_map_height(t_game *game, char **argv);
int		get_map_width(t_game *game, char **argv);
int		load_map(t_game *game, char *argv);
void	display_map(t_game *game);
void	get_player_position(t_game *game);
int		key_hook(int key, t_game *game);
void	key_process(int key, t_game *game);
void	move(t_game *game, int move_x, int move_y);
void	move_help(t_game *game, int move_x, int move_y, t_pos pos);
void	move_exit(t_game *game, char next_pos);
void	get_item_number(t_game *game);
int		check_if_all_collected(t_game *game);
int		check_map(t_game *game);
int		check_map_borders(t_game *game);
int		close_window(t_game *game);
int		count_coins(char **map);
void	check_valid_path(t_game *game);
int		check_unknownchar(t_game *game);

#endif
