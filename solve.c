/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:10:56 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/11 10:18:29 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_tetri(char **map, char *tetri, int col, int row)
{
	char	ch;
	int		i;

	ch = get_letter(tetri);
	i = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (i == 4)
				return ;
			if (map[row][col] == ch)
			{
				i++;
				map[row][col] = '.';
			}
			col++;
		}
		row++;
	}
}

void	place(char **map, char *tetri, int col, int row)
{
	size_t	i;
	int		init_col;

	init_col = col;
	i = 0;
	while (*tetri == '.')
		DO3(i++, tetri++, init_col--);
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
		if (DOT(map[row][col]) && !DOT(*tetri))
			DO3(map[row][col] = *tetri, col++, i++);
		tetri++;
	}
}

t_bool	is_safe(char **map, char *tetri, int col, int row)
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
		CHK(!DOT(map[row][col]) && map[row][col] && !DOT(*tetri), false);
		CHK(!map[row][col] && !DOT(*tetri), false);
		if (DOT(map[row][col]) && !DOT(*tetri))
			DO2(col++, i++);
		tetri++;
	}
	return (true);
}

int		solve(char **tbl, size_t blocks)
{
	char	**map;
	size_t	map_size;

	map_size = initial_board_size(blocks);
	CHK1((map = new_map(map_size)) == 0, error(), 0);
	while (recursion(tbl, map, 0, 0) == false)
	{
		map_size++;
		delete_map(map);
		CHK1((map = new_map(map_size)) == 0, error(), 0);
	}
	print_map(map, map_size);
	delete_map(map);
	return (0);
}

t_bool	recursion(char **tbl, char **map, int col, int row)
{
	if (!*tbl)
		return (true);
	while (map[row])
	{
		while (map[row][col])
		{
			if (is_safe(map, *tbl, col, row) == true)
			{
				place(map, *tbl, col, row);
				if (recursion(tbl + 1, map, 0, 0) == true)
					return (true);
				else
					remove_tetri(map, *tbl, col, row);
			}
			col++;
		}
		row++;
		col = 0;
	}
	return (false);
}
