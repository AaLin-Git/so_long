/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:00:19 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/20 09:29:10 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	collect_item(t_game *game)
{
	int				i;
	int				n;
	mlx_instance_t	*item;
	mlx_instance_t	*player;

	i = 0;
	n = game->total_items;
	item = game->images->item_img->instances;
	player = game->images->player_img->instances;
	while (i < n)
	{
		if (((item[i].y == player->y) && (item[i].x == player->x))
			&& item[i].enabled == true)
		{
			item[i].enabled = false;
			n--;
			return ;
		}
		i++;
	}
}

void	check_player_position(t_game *game)
{
	int	x;
	int	y;

	x = game->images->player_img->instances->x / TILE_SIZE;
	y = game->images->player_img->instances->y / TILE_SIZE;
	if (game->map[y][x] == 'C')
	{
		collect_item(game);
		game->collected_items++;
		game->map[y][x] = '0';
	}
	if (game->map[y][x] == 'E')
	{
		if (game->collected_items == game->total_items)
		{
			mlx_close_window(game->mlx);
		}
	}
}
