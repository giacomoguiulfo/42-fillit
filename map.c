/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 09:44:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/08 10:29:15 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		++i;
	}
}

void	delete_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
}

char	**new_map(size_t size)
{
	size_t	i;
	size_t	j;
	char	**map;
	
	CHK((map = (char **)malloc(sizeof(char*) * size + 1)) == 0, 0);
	i = -1;
	while (++i < size)
	{
		CHK1((map[i] = (char*)malloc(sizeof(char) * size + 1)) == 0, delete_map(map), 0);
		j = -1;
		ft_bzero(map[i], size + 1);
		while (++j < size)
			map[i][j] = '.';
	}
	map[i] = 0;
	return (map);
}

int		solve(char **tbl, size_t blocks)
{
	char	**map;
	char	**tmp;

	tmp = tbl;
	
	CHK1((map = new_map(blocks * 4)) == 0, ft_putstr("Error in Map Allocation\n"), 0);
	print_map(map);
	delete_map(map);
	return (0);
}
