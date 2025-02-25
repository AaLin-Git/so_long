/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:30:48 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/20 09:29:39 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libs/Libft/libft.h"

static void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->images->player_img->instances->x / TILE_SIZE;
	y = game->images->player_img->instances->y / TILE_SIZE;
	if (game->map[y - 1][x] != '1')
	{
		game->images->player_img->instances->y -= TILE_SIZE;
		game->count_moves++;
		ft_printf("You made %i moves\n", game->count_moves);
	}
}

static void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->images->player_img->instances->x / TILE_SIZE;
	y = game->images->player_img->instances->y / TILE_SIZE;
	if (game->map[y + 1][x] != '1')
	{
		game->images->player_img->instances->y += TILE_SIZE;
		game->count_moves++;
		ft_printf("You made %i moves\n", game->count_moves);
	}
}

static void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->images->player_img->instances->x / TILE_SIZE;
	y = game->images->player_img->instances->y / TILE_SIZE;
	if (game->map[y][x - 1] != '1')
	{
		game->images->player_img->instances->x -= TILE_SIZE;
		game->count_moves++;
		ft_printf("You made %i moves\n", game->count_moves);
	}
}

static void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->images->player_img->instances->x / TILE_SIZE;
	y = game->images->player_img->instances->y / TILE_SIZE;
	if (game->map[y][x + 1] != '1')
	{
		game->images->player_img->instances->x += TILE_SIZE;
		game->count_moves++;
		ft_printf("You made %i moves\n", game->count_moves);
	}
}

void	handle_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_RELEASE)
		move_up(game);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_RELEASE)
		move_down(game);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_RELEASE)
		move_left(game);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
	&& keydata.action == MLX_RELEASE)
		move_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	check_player_position(game);
}
