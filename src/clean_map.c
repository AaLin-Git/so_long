/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:17:11 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/20 09:30:26 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

void	clean_map(char **map, int rows)
{
	int	i;

	i = 0;
	if (map)
	{
		while (i < rows)
		{
			free(map[i]);
			i++;
		}
		free(map);
		map = NULL;
	}
}

void	clean_textures(t_game *game)
{
	if (game->textures->wall_tex)
	{
		mlx_delete_texture(game->textures->wall_tex);
		game->textures->wall_tex = NULL;
	}
	if (game->textures->grass_tex)
	{
		mlx_delete_texture(game->textures->grass_tex);
		game->textures->grass_tex = NULL;
	}
	if (game->textures->player_tex)
	{
		mlx_delete_texture(game->textures->player_tex);
		game->textures->player_tex = NULL;
	}
	if (game->textures->item_tex)
	{
		mlx_delete_texture(game->textures->item_tex);
		game->textures->item_tex = NULL;
	}
	if (game->textures->exit_tex)
	{
		mlx_delete_texture(game->textures->exit_tex);
		game->textures->exit_tex = NULL;
	}
}
