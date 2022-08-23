/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:21:47 by sryou             #+#    #+#             */
/*   Updated: 2022/08/23 16:02:24 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	throw_error(char *message, t_game *game)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	quit(game, 1);
}

void	free_img(t_game *game)
{
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.grass)
		mlx_destroy_image(game->mlx, game->img.grass);
	if (game->img.item)
		mlx_destroy_image(game->mlx, game->img.item);
	if (game->img.user)
		mlx_destroy_image(game->mlx, game->img.user);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
}

void	free_game(t_game *game)
{
	if (game)
	{
		free_img(game);
		if (game->mlx)
		{
			if (game->win)
				mlx_destroy_window(game->mlx, game->win);
			mlx_destroy_image(game->mlx, game->mlx->font);
			free(game->mlx);
		}
		if (game->map)
			free(game->map);
		free(game);
	}
}

void	quit(t_game *game, int code)
{
	free_game(game);
	exit(code);
}
