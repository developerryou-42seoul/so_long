/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:21:47 by sryou             #+#    #+#             */
/*   Updated: 2022/08/23 14:24:58 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	throw_error(char *message, t_game *game)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	quit(game, 1);
}

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->mlx && game->win)
			mlx_destroy_window(game->mlx, game->win);
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
