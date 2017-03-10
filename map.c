/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 09:44:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/09 14:47:56 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//#define DOTWO(a, b) do{a; b;}while(0)

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

void	reset_map(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '\0')
				map[i][j] = '.';
			j++;
		}
		i++;
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

char	get_letter(char *str)
{
	while (*str == '.')
		str++;
	return (*str);
}

void remove_tetri(char **map, char ch)
{
	size_t row;
	size_t col;

	row = 0;
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

t_bool	place(char **map, char*tetri, int cols, int rows)
{
	size_t i;
	int init_cols;
	int init_rows;

	init_rows = rows;
	init_cols = cols;
	i = 0;
	while (*tetri == '.')
		DO3(i++, tetri++, init_cols--);
	if (init_cols < 0)
		return (false);
	while (*tetri != '\0')
	{
		if (i > 3)
			DO3(i = 0, cols = init_cols, rows++);
		if (*tetri != '.')
		{
			if (map[rows][cols] != '.' && map[rows][cols] != '\0')
				return (false);
			if (map[rows][cols] == '\0')
			{
				remove_tetri(map ,get_letter(tetri));
				return (false);
			}
			if (map[rows][cols] == '.')
				DO4(map[rows][cols] = *tetri, cols++, tetri++, i++);
		}
		else
			DO3(i++, cols++, tetri++);
	}
	return (true);
}

int		test_place(char **tbl, size_t blocks)
{
	int		i;
	int		j;
	size_t	k;
	char	**map;

	CHK1((map = new_map(6)) == 0, ft_putstr("Error in Map Allocation\n"), 0);
	k = 0;
	while (k < blocks)
	{
		i = 0;
		while (i < 7)
		{
			j = 0;
			while (j < 7)
			{
				place(map, tbl[k], j, i);
				ft_putstr("row = ");
				ft_putnbr(i);
				ft_putstr(" cor = ");
				ft_putnbr(j);
				ft_putchar('\n');
				print_map(map, 6);
				ft_putchar('\n');
				reset_map(map);
				j++;
			}
			i++;
		}
		k++;
	}
	delete_map(map);
	return (0);
}

int		solve(char **tbl, size_t blocks)
{
	//char	**map;
	//size_t	map_size;
	test_place(tbl, blocks);

	//map_size = initial_board_size(blocks);
	//CHK1((map = new_map(map_size)) == 0, ft_putstr("Error in Map Allocation\n"), 0);
	/*while (recursion(tbl, map, 0, 0) == false)
	{
		map_size++;
		delete_map(map);
		CHK1((map = new_map(map_size)) == 0, ft_putstr("Error in Map Allocation\n"), 0);
		recursion(tbl, map, 0, 0);

	}
	print_map(map, blocks);
	delete_map(map);
	*/
	/**
	if (place(map, tbl[4], 26, 0))
		printf("Placed properly\n");
	else
		printf("NOT placed properly\n");
	if (place(map, tbl[2], 24, 0))
		printf("Placed properly\n");
	else
		printf("NOT placed properly\n");
	**/
	return (0);
}



/**
t_bool	recursion(char **tbl, char **map, int row, int col)
{
	while (map[row])
	{
		while (map[row][col])
		{
			if (place(map, *tbl, col, row) == true)
				solver(tbl + 1, map, 0, 0);
			col++;
		}
		row++;
	}


}
**/
