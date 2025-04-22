/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pathfinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:03:48 by enorie            #+#    #+#             */
/*   Updated: 2024/01/17 14:25:33 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_ok(char **map, char f, int y, int x)
{
	if ((map[y][x] == f && map[y][x + 1] && map[y][x + 1] != 'G' && map[y][x
		+ 1] != 'F') && (map[y][x] == f && map[y + 1][x] && map[y + 1][x] != 'G'
		&& map[y + 1][x] != 'F')
		&& (map[y][x] == f && map[y][x - 1] && map[y][x - 1] != 'G' && map[y][x
		- 1] != 'F') && (map[y][x] == f && map[y - 1][x] && map[y - 1][x] != 'G'
		&& map[y - 1][x] != 'F'))
		return (1);
	return (0);
}

void	ft_wich_char(char **map, int y, int x)
{
	if (map[y][x] == '0' && map[y][x + 1] && (map[y][x
		+ 1] == 'G' || map[y][x + 1] == 'F'))
		map[y][x] = 'G';
	if (map[y][x] == '0' && map[y + 1][x] && (map[y
		+ 1][x] == 'G' || map[y + 1][x] == 'F'))
		map[y][x] = 'G';
	if (map[y][x] == '0' && map[y][x - 1] && (map[y][x
		- 1] == 'G' || map[y][x - 1] == 'F'))
		map[y][x] = 'G';
	if (map[y][x] == '0' && map[y - 1][x] && (map[y
		- 1][x] == 'G' || map[y - 1][x] == 'F'))
		map[y][x] = 'G';
	if (map[y][x] == 'C' && map[y][x + 1] && (map[y][x
		+ 1] == 'G' || map[y][x + 1] == 'F'))
		map[y][x] = 'F';
	if (map[y][x] == 'C' && map[y + 1][x] && (map[y
		+ 1][x] == 'G' || map[y + 1][x] == 'F'))
		map[y][x] = 'F';
	if (map[y][x] == 'C' && map[y][x - 1] && (map[y][x
		- 1] == 'G' || map[y][x - 1] == 'F'))
		map[y][x] = 'F';
	if (map[y][x] == 'C' && map[y - 1][x] && (map[y
		- 1][x] == 'G' || map[y - 1][x] == 'F'))
		map[y][x] = 'F';
}

void	ft_pathfinder_init(char **map, t_coor c)
{
	if (map[c.y - 1][c.x] == '0')
		map[c.y - 1][c.x] = 'G';
	if (map[c.y + 1][c.x] == '0')
		map[c.y + 1][c.x] = 'G';
	if (map[c.y][c.x - 1] == '0')
		map[c.y][c.x - 1] = 'G';
	if (map[c.y][c.x + 1] == '0')
		map[c.y][c.x + 1] = 'G';
	if (map[c.y - 1][c.x] == 'C')
		map[c.y - 1][c.x] = 'F';
	if (map[c.y + 1][c.x] == 'C')
		map[c.y + 1][c.x] = 'F';
	if (map[c.y][c.x - 1] == 'C')
		map[c.y][c.x - 1] = 'F';
	if (map[c.y][c.x + 1] == 'C')
		map[c.y][c.x + 1] = 'F';
}

int	ft_ispathcomplete(char **map, int y, int x)
{
	if ((map[y][x] == '0' || map[y][x] == 'C')
		&& map[y][x + 1] && (map[y][x + 1] == 'G'
		|| map[y][x + 1] == 'F'))
		return (1);
	if ((map[y][x] == '0' || map[y][x] == 'C')
		&& map[y + 1][x] && (map[y + 1][x] == 'G'
		|| map[y + 1][x] == 'F'))
		return (1);
	if ((map[y][x] == '0' || map[y][x] == 'C')
		&& map[y][x - 1] && (map[y][x - 1] == 'G'
		|| map[y][x - 1] == 'F'))
		return (1);
	if ((map[y][x] == '0' || map[y][x] == 'C')
		&& map[y + 1][x] && (map[y - 1][x] == 'G'
		|| map[y - 1][x] == 'F'))
		return (1);
	return (0);
}
