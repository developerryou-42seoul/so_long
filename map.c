/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:47:24 by sryou             #+#    #+#             */
/*   Updated: 2022/08/23 15:59:03 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map_loop(int fd, t_game *game)
{
	char	*ln;
	char	*temp;
	int		len;

	while (1)
	{
		game->height++;
		ln = get_next_line(fd);
		if (ln)
		{
			len = ft_strlen(ln);
			if (ln[len - 1] == '\n')
				ln[--len] = '\0';
			if (len != game->width)
				throw_error("MAP ERROR | Map is not Rectangular.", game);
			temp = ft_strjoin(game->map, ln);
			free(game->map);
			free(ln);
			game->map = temp;
		}
		else
			return ;
	}
}

void	read_map(char *map, t_game *game)
{
	int		fd;
	int		len;
	char	*ln;

	fd = open(map, O_RDONLY);
	ln = get_next_line(fd);
	if (ln == NULL)
		throw_error("FILE ERROR | Invalid File.", game);
	len = ft_strlen(ln);
	if (ln[len - 1] == '\n')
		ln[--len] = '\0';
	game->width = len;
	game->map = ft_strdup(ln);
	free(ln);
	read_map_loop(fd, game);
}

void	check_valid_map(int num_user, int num_exit, \
	int invalid_wall, t_game *game)
{
	if (invalid_wall)
		throw_error("MAP ERROR | Map is not surrounded by Walls.", game);
	if (num_user < 1)
		throw_error("MAP ERROR | Map does not have User.", game);
	if (num_user > 1)
		throw_error("MAP ERROR | Map has too many User.", game);
	if (num_exit < 1)
		throw_error("MAP ERROR | Map does not have Exit.", game);
	if (game->num_item < 1)
		throw_error("MAP ERROR | Map does not have Item.", game);
}

void	interpret_map(t_game *game)
{
	int	num_user;
	int	num_exit;
	int	idx;

	num_user = 0;
	num_exit = 0;
	idx = -1;
	while (++idx < game->width * game->height)
	{
		if (idx < game->width || idx >= game->width * (game->height - 1) || \
			idx % game->width == 0 || idx % game->width == game->width - 1)
			if (game->map[idx] != '1')
				check_valid_map(num_user, num_exit, 1, game);
		if (game->map[idx] == 'P' && (num_user++ || 1))
			game->cord_user = idx;
		else if (game->map[idx] == 'C')
			game->num_item++;
		else if (game->map[idx] == 'E')
			num_exit++;
		else if (game->map[idx] != '1' && game->map[idx] != '0')
			throw_error("MAP ERROR | Map has Wrong Character.", game);
	}
	check_valid_map(num_user, num_exit, 0, game);
}
