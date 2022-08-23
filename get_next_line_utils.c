/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:02:05 by sryou             #+#    #+#             */
/*   Updated: 2022/08/16 14:33:07 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **line)
{
	if (line != 0 && *line != 0)
	{
		free(*line);
		*line = 0;
	}
	return (0);
}

int	ft_strmylen(char *str)
{
	int	idx;

	if (str == 0)
		return (0);
	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

void	ft_strmycat(char *dst, char *src, int dstsize, int srcsize)
{
	int	idx;

	idx = 0;
	dst = dst + dstsize;
	while (idx < srcsize)
	{
		*dst = *src;
		dst++;
		src++;
		idx++;
	}
	*dst = '\0';
}

int	ft_strmyjoin(char **line, char *buffer)
{
	int		len1;
	int		len2;
	char	*mkstr;

	len1 = ft_strmylen(*line);
	len2 = ft_strmylen(buffer);
	mkstr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (mkstr == 0)
		return (0);
	mkstr[0] = '\0';
	ft_strmycat(mkstr, *line, 0, len1);
	ft_strmycat(mkstr, buffer, len1, len2);
	ft_free(line);
	*line = mkstr;
	return (len1 + len2);
}
