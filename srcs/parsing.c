/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:58:25 by gmarre            #+#    #+#             */
/*   Updated: 2023/12/07 16:14:56 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	invalid_char(t_game *param)
{
	int	y;
	int	x;

	y = 0;
	while (param->map[y])
	{
		x = 0;
		while (param->map[y][x])
		{
			if (param->map[y][x] != WALL && param->map[y][x] != FLOOR
				&& param->map[y][x] != PLAYER && param->map[y][x] != COLLEC
				&& param->map[y][x] != EXIT)
			{
				puts("Error,\nInvalid character");
				return (FALSE);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

int	check_coin(t_game *param)
{
	int	c;
	int	y;
	int	x;

	c = 0;
	y = -1;
	while (param->map[++y])
	{
		x = 0;
		while (param->map[y][x])
		{
			if (param->map[y][x] == COLLEC)
				c++;
			x++;
		}
	}
	if (c >= 1)
		return (TRUE);
	puts("Error,\nNo coins placed");
	return (FALSE);
}

int	check_player(t_game *param)
{
	int	p;
	int	y;
	int	x;

	p = 0;
	y = -1;
	while (param->map[++y])
	{
		x = 0;
		while (param->map[y][x])
		{
			if (param->map[y][x] == PLAYER)
				p++;
			x++;
		}
	}
	if (p > 1)
		puts("Error,\nYou can only place one player");
	else if (p < 1)
		puts("Error,\nNo player placed");
	else
		return (TRUE);
	return (FALSE);
}

int	check_exit(t_game *param)
{
	int	e;
	int	y;
	int	x;

	e = 0;
	y = -1;
	while (param->map[++y])
	{
		x = 0;
		while (param->map[y][x])
		{
			if (param->map[y][x] == EXIT)
				e++;
			x++;
		}
	}
	if (e > 1)
		puts("Error,\nYou can only place one exit");
	else if (e < 1)
		puts("Error,\nNo exit placed");
	else
		return (TRUE);
	return (FALSE);
}

int	ft_parsing(t_game *param)
{
	if (!check_lenght(param))
		return (FALSE);
	if (!invalid_char(param))
		return (FALSE);
	if (!check_walls(param))
	{
		puts("Error,\nMissing walls");
		return (FALSE);
	}
	if (!is_square(param))
		return (FALSE);
	if (!check_coin(param) || !check_player(param) || !check_exit(param))
		return (FALSE);
	if (!is_possible(param, 0, 0, 0))
	{
		puts("Error,\nMap is not possible");
		return (FALSE);
	}
	return (TRUE);
}
