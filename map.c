/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 09:44:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/08 22:33:07 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
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
	size_t	n_size;
	char	**map;

	n_size = size + 3;
	CHK((map = (char **)malloc(sizeof(char*) * (n_size + 1))) == 0, 0);
	ft_bzero(map, n_size);
	i = -1;
	while (++i < size)
	{
		CHK1((map[i] = (char*)malloc(sizeof(char) * (n_size))) == 0, delete_map(map), 0);
		ft_bzero(map[i], n_size);
		j = -1;
		while (++j < size)
			map[i][j] = '.';
	}
	while (i < n_size)
	{
		map[i] = (char*)malloc(sizeof(char) * n_size);
		CHK1((map[i] = (char*)malloc(sizeof(char) * (n_size))) == 0, delete_map(map), 0);
		ft_bzero(map[i], n_size);
		++i;
	}
	map[i] = 0;
	return (map);
}

size_t initial_board_size(size_t nb_blocks)
{
	size_t min_size;
	size_t i;

	i = 2;
	min_size = nb_blocks * 4;
	while (min_size > (i * i))
		i++;
	return (i);
}

void	place(char **map, char*tetri, int cols, int rows)
{
	size_t i;
	size_t init_cols;
	size_t init_rows;

	init_rows = rows;
	init_cols = cols;
	i = 0;
	while (*tetri == '.')
	{
		i++;
		//CHK(--init_cols < 0, 0);

	}
	while (*tetri != '\0')
	{
		if (i > 3)
		{
			printf("i > 3\n");
			i = 0;
			cols = init_cols;
			rows++;
		}
		/*if (map[rows][cols] == '\0')
		{
			rows++;
			i = 0;
			cols = init_cols;
			if (*tetri == '.')
				tetri++;
			printf("Map == NULL\n");
		}*/
		else if (*tetri != '.' && map[rows][cols] != '\0')
		{
			map[rows][cols] = *tetri;
			cols++;
			printf("Cols++\n");
			tetri++;
			i++;
		}
		else
		{
			/*
			printf("Else...\n");
			if (i > 3)
			{
				printf("i > 3\n");
				i = 0;
				cols = init_cols;
				rows++;
			}*/
			//else
			//{
				printf("else & else\n");
				i++;
				cols++;
				tetri++;
			//}
		}
	}
}

int		solve(char **tbl, size_t blocks)
{
	char	**map;
	char	**tmp;

	tmp = tbl;
	CHK1((map = new_map(blocks)) == 0, ft_putstr("Error in Map Allocation\n"), 0);
	//place(map, tbl[5], 1, 0);
	print_map(map, blocks);
	delete_map(map);
		return (0);
}
