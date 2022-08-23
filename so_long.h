/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:35:55 by sryou             #+#    #+#             */
/*   Updated: 2022/08/23 14:48:32 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./mlx/mlx.h"
# include "./get_next_line.h"
# include <fcntl.h>

# define KEY_PRESSED	2
# define EXIT_CLICKED	17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img
{
	void	*wall;
	void	*grass;
	void	*user;
	void	*item;
	void	*exit;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		width;
	int		height;
	char	*map;
	int		cord_user;
	int		current_move;
	int		num_item;
	int		collected_item;
}	t_game;

t_game	*init_game(char *map);

void	read_map(char *map, t_game *game);
void	interpret_map(t_game *game);
void	print_map(t_game *game);

void	throw_error(char *message, t_game *game);
void	quit(t_game *game, int code);

void	move(t_game *game, int cordMove);

#endif