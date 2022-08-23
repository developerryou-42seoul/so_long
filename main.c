/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:17:21 by sryou             #+#    #+#             */
/*   Updated: 2022/08/23 15:10:09 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit_game(t_game *game)
{
	quit(game, 0);
	return (0);
}

int	key_pressed(int code, t_game *game)
{
	if (code == KEY_ESC)
		quit_game(game);
	if (code == KEY_W)
		move(game, game->cord_user - game->width);
	if (code == KEY_S)
		move(game, game->cord_user + game->width);
	if (code == KEY_A)
		move(game, game->cord_user - 1);
	if (code == KEY_D)
		move(game, game->cord_user + 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
		throw_error("ARGUMENT ERROR | Argument missing.", NULL);
	if (argc > 2)
		throw_error("ARGUMENT ERROR | Too many Arguments.", NULL);
	if (ft_strlen(argv[1]) - 4 <= 0 || \
		ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		throw_error("ARGUMENT ERROR | Wrong Extention.", NULL);
	game = init_game(argv[1]);
	if (game == NULL)
		throw_error("INIT ERROR | Game init Error.", NULL);
	mlx_hook(game->win, KEY_PRESSED, 0, &key_pressed, game);
	mlx_hook(game->win, EXIT_CLICKED, 0, &quit_game, game);
	mlx_loop(game->mlx);
	quit_game(game);
}
