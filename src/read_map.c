/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:38:49 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/20 09:29:45 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libs/Libft/libft.h"
#include <fcntl.h>
#include <string.h>

static char	*trim_newline(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

int	get_file_descriptor(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

static char	**fill_map(char **map, int rows, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		trim_newline(line);
		map[i] = ft_strdup(line);
		free(line);
		if (!map[i])
		{
			clean_map(map, rows);
			close(fd);
			return (NULL);
		}
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

int	read_map(const char *file, t_game *game)
{
	int	fd;

	fd = get_file_descriptor(file);
	if (fd == -1)
		return (0);
	if (!initialize_map(file, game))
	{
		close(fd);
		return (0);
	}
	game->map = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
	{
		close(fd);
		return (0);
	}
	game->map = fill_map(game->map, game->rows, fd);
	if (!game->map)
		return (0);
	close(fd);
	return (1);
}
