/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:45:43 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/20 09:28:58 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx42/include/MLX42/MLX42.h"
# include <stdio.h>

# define TILE_SIZE	150

typedef struct s_textures
{
	mlx_texture_t	*wall_tex;
	mlx_texture_t	*grass_tex;
	mlx_texture_t	*player_tex;
	mlx_texture_t	*item_tex;
	mlx_texture_t	*exit_tex;
}		t_textures;

typedef struct s_images
{
	mlx_image_t	*wall_img;
	mlx_image_t	*grass_img;
	mlx_image_t	*player_img;
	mlx_image_t	*item_img;
	mlx_image_t	*exit_img;
}		t_images;

typedef struct s_game
{
	struct s_textures	*textures;
	struct s_images		*images;
	mlx_t				*mlx;
	char				**map;
	int					player_x;
	int					player_y;
	int					rows;
	int					cols;
	int					collected_items;
	int					total_items;
	int					count_moves;
}		t_game;

int		initialize_map(const char *file, t_game *game);
int		initialize_game(t_game *game);
int		get_file_descriptor(const char *file);
int		read_map(const char *file, t_game *game);
int		is_rectangular(t_game *game);
int		is_valid_walls(t_game *game);
int		is_valid_characters(t_game *game);
int		is_enough_elements(t_game *game);
int		is_valid_map(const char *file, t_game *game);
int		is_valid_name(const char *file);
int		is_valid_path(t_game *game);
void	initialize_player(t_game *game);
void	check_player_position(t_game *game);
void	load_images(t_game *game);
void	draw_map(t_game *game, t_images *images);
void	clean_map(char **map, int rows);
void	clean_textures(t_game *game);
void	handle_input(mlx_key_data_t keydata, void *param);

#endif