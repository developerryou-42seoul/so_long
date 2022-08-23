/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:35:55 by sryou             #+#    #+#             */
/*   Updated: 2022/08/23 16:09:49 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include <OpenGL/gl3.h>
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

typedef struct s_mlx_img_list
{
	int						width;
	int						height;
	char					*buffer;
	GLfloat					vertexes[8];
	struct s_mlx_img_list	*next;
}	t_mlx_img_list;

typedef struct s_mlx_img_ctx
{
	GLuint					texture;
	GLuint					vbuffer;
	t_mlx_img_list			*img;
	struct s_mlx_img_ctx	*next;
}	t_mlx_img_ctx;

typedef struct s_mlx_win_list
{
	void					*winid;
	t_mlx_img_ctx			*img_list;
	int						nb_flush;
	int						pixmgt;
	struct s_mlx_win_list	*next;
}	t_mlx_win_list;

typedef struct mlx_ptr
{
	void			*appid;
	t_mlx_win_list	*win_list;
	t_mlx_img_list	*img_list;
	void			(*loop_hook)(void *);
	void			*loop_hook_data;
	void			*loop_timer;
	t_mlx_img_list	*font;
	int				main_loop_active;
}	t_mlx_ptr;

typedef struct s_game
{
	t_mlx_ptr	*mlx;
	void		*win;
	t_img		img;
	int			width;
	int			height;
	char		*map;
	int			cord_user;
	int			current_move;
	int			num_item;
	int			collected_item;
}	t_game;

t_game	*init_game(char *map);

void	read_map(char *map, t_game *game);
void	interpret_map(t_game *game);
void	print_map(t_game *game);

void	throw_error(char *message, t_game *game);
void	quit(t_game *game, int code);

void	move(t_game *game, int cordMove);

#endif