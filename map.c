/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 09:44:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/09 20:07:46 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//#define DOTWO(a, b) do{a; b;}while(0)

void	print_map(char **map, size_t size)
{
	size_t	i;

	i = 0;
	while (i <= size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		++i;
	}
	ft_putchar('\n');
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
	int		i;
	int		j;
	int		n_size;
	char	**map;

	n_size = size + 3;
	CHK((map = (char **)malloc(sizeof(char*) * (n_size + 1))) == 0, 0);
	ft_bzero(map, n_size);
	i = -1;
	while (++i < (int)size)
	{
		CHK1((map[i] = (char*)malloc(sizeof(char) * (n_size))) == 0, delete_map(map), 0);
		ft_bzero(map[i], n_size);
		j = -1;
		while (++j < (int)size)
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
