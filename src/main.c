/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:46:56 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/20 09:29:35 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/errors.h"
#include "../libs/Libft/libft.h"
#include <string.h>

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf(ERR_ARG), 1);
	if (!read_map(argv[1], &game))
		return (ft_printf(ERR_READ_MAP), 1);
	if (!is_valid_map(argv[1], &game))
		return (clean_map(game.map, game.rows), 1);
	initialize_game(&game);
	mlx_terminate(game.mlx);
	game.mlx = NULL;
	free(game.images);
	clean_map(game.map, game.rows);
	return (0);
}
