/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:15:22 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/20 09:29:25 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/errors.h"
#include "../libs/Libft/libft.h"

void	initialize_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
			}
			j++;
		}
		i++;
	}
}

int	initialize_map(const char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = get_file_descriptor(file);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		game->cols = ft_strlen(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	game->rows = i;
	close(fd);
	return (1);
}

int	is_valid_map(const char *file, t_game *game)
{
	if (!game->map[0])
		return (ft_printf(ERR_VALID_MAP), 0);
	if (!is_rectangular(game))
		return (ft_printf(ERR_RECT), 0);
	if (!is_valid_walls(game))
		return (ft_printf(ERR_WALL), 0);
	if (!is_valid_characters(game))
		return (ft_printf(ERR_CHAR), 0);
	if (!is_enough_elements(game))
		return (ft_printf(ERR_AMOUNT), 0);
	if (!is_valid_name(file))
		return (ft_printf(ERR_NAME), 0);
	if (!is_valid_path(game))
		return (ft_printf(ERR_PATH), 0);
	return (1);
}

int	initialize_game(t_game *game)
{
	int	width;
	int	height;

	width = game->cols * TILE_SIZE;
	height = game->rows * TILE_SIZE;
	game->total_items = 0;
	game->collected_items = 0;
	game->count_moves = 0;
	game->mlx = mlx_init(width, height, "so_long", false);
	if (!game->mlx)
		return (0);
	load_images(game);
	draw_map(game, game->images);
	mlx_key_hook(game->mlx, handle_input, game);
	mlx_loop(game->mlx);
	return (1);
}
