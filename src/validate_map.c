/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalch <akovalch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:03:55 by akovalch          #+#    #+#             */
/*   Updated: 2025/02/20 09:29:47 by akovalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libs/Libft/libft.h"

int	is_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (i < (game->rows - 1))
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (((i == 0 || i == game->rows - 1) && game->map[i][j] != '1') ||
				((j == 0 || j == game->cols - 1) && game->map[i][j] != '1'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_characters(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			c = game->map[i][j];
			if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_elements(t_game *game, int player, int item, int exit)
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
				player++;
			if (game->map[i][j] == 'C')
				item = 1;
			if (game->map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (player != 1 || item != 1 || exit != 1)
		return (0);
	return (1);
}

int	is_enough_elements(t_game *game)
{
	int	has_player;
	int	has_item;
	int	has_exit;

	has_player = 0;
	has_item = 0;
	has_exit = 0;
	if (!check_elements(game, has_player, has_item, has_exit))
		return (0);
	return (1);
}
