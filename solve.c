/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:10:56 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/09 18:36:12 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		test_place(char **tbl, size_t blocks);

int		solve(char **tbl, size_t blocks)
{
	char	**map;
	size_t	map_size;
	//test_place(tbl, blocks);
	map_size = initial_board_size(blocks);
	CHK1((map = new_map(map_size)) == 0, ft_putstr("Error in Map Allocation\n"), 0);
	while (recursion(tbl, map, 0, 0) == false)
	{
		map_size++;
		delete_map(map);
		CHK1((map = new_map(map_size)) == 0, ft_putstr("Error in Map Allocation\n"), 0);
		recursion(tbl, map, 0, 0);
	}
	print_map(map, blocks);
	delete_map(map);
	return (0);
}

t_bool	recursion(char **tbl, char **map, int row, int col)
{
	while (map[row])
	{
		while (map[row][col])
		{
			if (place(map, *tbl, col, row) == true)
			{
				if (recursion(tbl + 1, map, 0, 0) == false)
					remove_tetri(map, *tbl);
				else
					return (false);
			}
			col++;
		}
		row++;
		col = 0;
	}
	return (true);
}
