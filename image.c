/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:54:42 by sryou             #+#    #+#             */
/*   Updated: 2022/08/23 15:12:36 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_image(t_game *game, int width, int height)
{
	int	(*f)();

	f = mlx_put_image_to_window;
	f(game->mlx, game->win, game->img.grass, width * 64, height * 64);
	if (game->map[height * game->width + width] == '1')
		f(game->mlx, game->win, game->img.wall, width * 64, height * 64);
	if (game->map[height * game->width + width] == 'C')
		f(game->mlx, game->win, game->img.item, width * 64, height * 64);
	if (game->map[height * game->width + width] == 'E')
		f(game->mlx, game->win, game->img.exit, width * 64, height * 64);
	if (game->map[height * game->width + width] == 'P')
		f(game->mlx, game->win, game->img.user, width * 64, height * 64);
}

void	print_map(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			place_image(game, width, height);
			width++;
		}
		height++;
	}
}

void	move(t_game *game, int cordMove)
{
	int	flag_quit;

	flag_quit = 0;
	if (game->map[cordMove] == '1')
		return ;
	if (game->map[cordMove] == 'C')
		game->collected_item++;
	if (game->map[cordMove] == 'E')
	{
		if (game->collected_item == game->num_item)
			flag_quit = 1;
		else
			return ;
	}
	game->map[cordMove] = 'P';
	game->map[game->cord_user] = '0';
	game->cord_user = cordMove;
	ft_putnbr_fd(++game->current_move, 1);
	ft_putchar_fd('\n', 1);
	print_map(game);
	if (flag_quit)
		quit(game, 0);
}
