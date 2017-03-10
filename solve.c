/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:10:56 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/09 21:35:26 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		test_place(char **tbl, size_t blocks);

void	remove_tetri(char **map, char *tetri)
{
	size_t 	row;
	size_t 	col;
	char	ch;

	row = 0;
	ch = get_letter(tetri);
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == ch)
				map[row][col] = '.';
			col++;
		}
		row++;
	}
}

t_bool	is_safe(char **map, char*tetri, int col, int row)
{
	size_t	i;
	int		init_col;

	init_col = col;
	i = 0;

	if (!tetri)
		return (end);

	while (*tetri == '.')
		DO3(i++, tetri++, init_col--);
	CHK(init_col < 0, false);
	while (*tetri != '\0')
	{
		if (i > 3)
		{
			i = 0;
			col = init_col;
			row++;
		}
		if (*tetri == '.')
			DO2(i++, col++);
		CHK(!DOT(map[row][col]) && map[row][col] && !DOT(*tetri),false);
		CHK1(!map[row][col] && !DOT(*tetri), remove_tetri(map, tetri), false);
		if (DOT(map[row][col]) && !DOT(*tetri))
			DO2(col++, i++);
		tetri++;
	}
	return (true);
}

t_bool	place(char **map, char*tetri, int col, int row)
{
	size_t	i;
	int		init_col;

	init_col = col;
	i = 0;

	while (*tetri == '.')
		DO3(i++, tetri++, init_col--);
	CHK(init_col < 0, false);
	while (*tetri != '\0')
	{
		if (i > 3)
		{
			i = 0;
			col = init_col;
			row++;
		}
		if (*tetri == '.')
			DO2(i++, col++);
		CHK(!DOT(map[row][col]) && map[row][col] && !DOT(*tetri),false);
		CHK1(!map[row][col] && !DOT(*tetri), remove_tetri(map, tetri), false);
		if (DOT(map[row][col]) && !DOT(*tetri))
			DO3(map[row][col] = *tetri, col++, i++);
		tetri++;
	}
	return (true);
}

int		solve(char **tbl, size_t blocks)
{
	char	**map;
	size_t	map_size;
	
	map_size = 5;
	//CHK1((map = new_map(map_size)) == 0, ft_putstr("Error in Map Allocation\n"), 0);
	//test_place(tbl, blocks);
	
	map_size = initial_board_size(blocks);
	CHK1((map = new_map(map_size)) == 0, ft_putstr("Error in Map Allocation\n"), 0);

	printf("Starting Map Size = %zu\n", map_size);
	while (recursion(tbl, map, 0, 0, map_size, 0, blocks) == false)
	{
		map_size++;
		delete_map(map);
		CHK1((map = new_map(map_size)) == 0, ft_putstr("Error in Map Allocation\n"), 0);
		printf("Map Size = %zu\n", map_size);
		recursion(tbl, map, 0, 0, map_size, 0, blocks);
		delete_map(map);
		CHK1((map = new_map(map_size)) == 0, ft_putstr("Error in Map Allocation\n"), 0);
	}

	print_map(map, map_size);
	delete_map(map);
	return (0);
}

t_bool	recursion(char **tbl, char **map, int col, int row, size_t map_size, int i, int limit)
{
	if (i == limit)
	{
		//printf("I am here!");
		return (true);
	}

	while (map[row])
	{
		while (map[row][col])
		{
			if (is_safe(map, *tbl, col, row) == true)
			{
				place(map, *tbl, col, row);
				//print_map(map, map_size);
				if (recursion(tbl + 1, map, 0, 0, map_size, i + 1, limit) == false)
				{
					remove_tetri(map, *tbl);
					return (false);
				}
				else 
					return (true);
			}
			col++;
		}
		row++;
		col = 0;
	}
	if (!tbl)
		return (true);
	return (false);
}
