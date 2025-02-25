/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_a_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:58:49 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/20 09:29:27 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libs/Libft/libft.h"
#include <stdlib.h>

int	is_valid_name(const char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

static char	**copy_map(char **map, int rows)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (0);
	while (i < rows)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			clean_map(copy, rows);
			return (0);
		}
		i++;
	}
	copy[rows] = NULL;
	return (copy);
}

static void	flood_fill(char **map, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->rows || y >= game->cols
		|| map[x][y] == '1' || map[x][y] == 'F')
		return ;
	map[x][y] = 'F';
	flood_fill(map, game, x + 1, y);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x, y - 1);
}

static int	find_path(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map[i][j] == 'C' || game->map[i][j] == 'E')
			{
				if (map[i][j] != 'F')
				{
					clean_map(map, game->rows);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_path(t_game *game)
{
	char	**map_copy;

	map_copy = copy_map(game->map, game->rows);
	if (!map_copy)
		return (0);
	initialize_player(game);
	flood_fill(map_copy, game, game->player_x, game->player_y);
	if (find_path(map_copy, game))
	{
		clean_map(map_copy, game->rows);
		return (1);
	}
	return (0);
}
