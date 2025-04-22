/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:57:21 by enorie            #+#    #+#             */
/*   Updated: 2024/01/17 11:58:34 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_size(char *filepath)
{
	int		i;
	int		fd;
	char	*ligne;

	i = 0;
	fd = open(filepath, O_RDONLY);
	ligne = get_next_line(fd);
	while (ligne)
	{
		free(ligne);
		ligne = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i + 1);
}

int	ft_check_char(char **map)
{
	int	i[4];

	i[0] = 0;
	i[2] = 0;
	i[3] = 0;
	while (map[i[0]])
	{
		i[1] = 0;
		while (i[1] < ((int)ft_strlen(map[0]) - 2))
		{
			if (map[i[0]][i[1]] != '1' && map[i[0]][i[1]] != '0'
				&& map[i[0]][i[1]] != 'E' && map[i[0]][i[1]] != 'P'
				&& map[i[0]][i[1]] != 'C' && map[i[0]][i[1]] != 'M')
				return (1);
			if (map[i[0]][i[1]] == 'E')
				i[2]++;
			if (map[i[0]][i[1]] == 'P')
				i[3]++;
			i[1]++;
		}
		i[0]++;
	}
	if (i[2] != 1 || i[3] != 1)
		return (1);
	return (0);
}

int	ft_check_close(char **map)
{
	int	i;
	int	l;
	int	h;

	h = ft_gethigh(map) - 1;
	l = ft_strlen(map[0]) - 2;
	i = 0;
	while (i < l)
	{
		if (map[0][i++] != '1')
			return (1);
	}
	i = 0;
	while (i < h)
	{
		if (map[i++][0] != '1')
			return (1);
	}
	i = 0;
	while (i < h)
	{
		if (map[i++][l] != '1')
			return (1);
	}
	return (0);
}

int	ft_checkmap(char **map)
{
	int	temp;
	int	i;
	int	h;

	if (ft_check_char(map))
		return (1);
	i = 0;
	temp = ft_strlen(map[i]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != temp)
			return (1);
		temp = ft_strlen(map[i]);
		i++;
	}
	i = 0;
	h = ft_gethigh(map) - 1;
	while (i < temp - 1)
	{
		if (map[h][i++] != '1')
			return (1);
	}
	if (!ft_check_close(map) && !ft_pathfinder(map))
		return (0);
	return (1);
}

char	**get_map(char *filepath)
{
	char	**map;
	char	*ligne;
	int		fd[2];

	fd[0] = 0;
	fd[1] = open(filepath, O_RDONLY);
	if (fd[1] == -1)
		return (NULL);
	map = malloc(sizeof(char *) * map_size(filepath));
	if (!map)
		return (ft_free_map(NULL, fd[1]));
	map[map_size(filepath) - 1] = NULL;
	ligne = get_next_line(fd[1]);
	while (ligne)
	{
		map[fd[0]] = ft_strdup(ligne);
		if (!map[fd[0]])
			return (ft_free_map(map, fd[1]));
		free(ligne);
		ligne = get_next_line(fd[1]);
		fd[0]++;
	}
	if (ft_checkmap(map))
		return (ft_free_map(map, fd[1]));
	return (map);
}
