/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:25:41 by sryou             #+#    #+#             */
/*   Updated: 2022/08/23 15:27:37 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	init_img(t_game *game)
{
	void	*(*f)();
	t_img	img;
	int		width;
	int		height;

	f = mlx_xpm_file_to_image;
	img.grass = f(game->mlx, "./images/grass.xpm", &width, &height);
	img.wall = f(game->mlx, "./images/wall.xpm", &width, &height);
	img.user = f(game->mlx, "./images/user.xpm", &width, &height);
	img.item = f(game->mlx, "./images/item.xpm", &width, &height);
	img.exit = f(game->mlx, "./images/exit.xpm", &width, &height);
	return (img);
}

void	init_game_zero(t_game *game)
{
	game->mlx = 0;
	game->win = 0;
	game->width = 0;
	game->height = 0;
	game->map = 0;
	game->num_item = 0;
	game->collected_item = 0;
	game->current_move = 0;
	game->cord_user = 0;
	game->img.exit = 0;
	game->img.grass = 0;
	game->img.item = 0;
	game->img.user = 0;
	game->img.wall = 0;
}

t_game	*init_game(char *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		return (NULL);
	init_game_zero(game);
	game->mlx = mlx_init();
	read_map(map, game);
	interpret_map(game);
	game->img = init_img(game);
	game->win = mlx_new_window(game->mlx, \
		game->width * 64, game->height * 64, "so_long");
	print_map(game);
	return (game);
}
