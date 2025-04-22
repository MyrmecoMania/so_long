/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:52:43 by enorie            #+#    #+#             */
/*   Updated: 2024/01/17 14:24:31 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_iscomplete(char **map)
{
	int	i[2];

	i[0] = 0;
	while (map[i[0]])
	{
		i[1] = 0;
		while (map[i[0]][i[1]])
		{
			if (ft_ispathcomplete(map, i[0], i[1]))
				return (1);
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}

void	ft_clean(char **map)
{
	int	i[2];

	i[0] = 0;
	while (map[i[0]])
	{
		i[1] = 0;
		while (map[i[0]][i[1]])
		{
			if (map[i[0]][i[1]] == 'G')
				map[i[0]][i[1]] = '0';
			if (map[i[0]][i[1]] == 'F')
				map[i[0]][i[1]] = 'C';
			i[1]++;
		}
		i[0]++;
	}
}

int	ft_isok(char **map)
{
	int	i[2];

	i[0] = 0;
	while (map[i[0]])
	{
		i[1] = 0;
		while (map[i[0]][i[1]])
		{
			if (ft_ok(map, 'C', i[0], i[1]))
				return (ft_clean(map), 1);
			if (ft_ok(map, 'E', i[0], i[1]))
				return (ft_clean(map), 1);
			i[1]++;
		}
		i[0]++;
	}
	return (ft_clean(map), 0);
}

void	ft_pathfind(char **map)
{
	int	i[2];

	i[0] = 0;
	while (map[i[0]])
	{
		i[1] = 0;
		while (map[i[0]][i[1]])
		{
			ft_wich_char(map, i[0], i[1]);
			i[1]++;
		}
		i[0]++;
	}
}

int	ft_pathfinder(char **map)
{
	t_coor	p;

	p = get_coor(map, 'P', 0, 0);
	ft_pathfinder_init(map, p);
	p = get_coor(map, 'C', 0, 0);
	if (p.x == 0 && p.y == 0)
		return (1);
	while (ft_iscomplete(map))
		ft_pathfind(map);
	p = get_coor(map, 'F', 0, 0);
	if (p.x == 0 && p.y == 0)
		return (1);
	return (ft_isok(map));
}
