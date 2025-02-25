/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:45:57 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/20 09:29:21 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libs/Libft/libft.h"

static void	load_textures(t_game *game)
{
	t_textures	*tex;

	tex = ft_calloc(1, sizeof(t_textures));
	if (!tex)
		return ;
	game->textures = tex;
	tex->wall_tex = mlx_load_png("./textures/wall.png");
	tex->grass_tex = mlx_load_png("./textures/grass.png");
	tex->player_tex = mlx_load_png("./textures/player.png");
	tex->item_tex = mlx_load_png("./textures/item.png");
	tex->exit_tex = mlx_load_png("./textures/exit.png");
}

static void	load_images_helper(t_game *game, t_images *img, t_textures *tex)
{
	img->wall_img = mlx_texture_to_image(game->mlx, tex->wall_tex);
	img->grass_img = mlx_texture_to_image(game->mlx, tex->grass_tex);
	img->player_img = mlx_texture_to_image(game->mlx, tex->player_tex);
	img->item_img = mlx_texture_to_image(game->mlx, tex->item_tex);
	img->exit_img = mlx_texture_to_image(game->mlx, tex->exit_tex);
}

void	load_images(t_game *game)
{
	t_images	*img;

	load_textures(game);
	img = ft_calloc(1, sizeof(t_images));
	if (!img)
		return ;
	game->images = img;
	load_images_helper(game, img, game->textures);
	clean_textures(game);
	free(game->textures);
}

static void	draw_base(t_game *game, t_images *images)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			x = j * TILE_SIZE;
			y = i * TILE_SIZE;
			mlx_image_to_window(game->mlx, images->grass_img, x, y);
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, images->wall_img, x, y);
			if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, images->exit_img, x, y);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game, t_images *images)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	draw_base(game, images);
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			x = j * TILE_SIZE;
			y = i * TILE_SIZE;
			if (game->map[i][j] == 'C')
			{
				mlx_image_to_window(game->mlx, images->item_img, x, y);
				game->total_items++;
			}
			if (game->map[i][j] == 'P')
				mlx_image_to_window(game->mlx, images->player_img, x, y);
			j++;
		}
		i++;
	}
}
