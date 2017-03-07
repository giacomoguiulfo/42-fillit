/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:02:04 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/06 17:37:44 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

# define BUFFER_SIZE 546
# define V1(a) (a == '#' || a == '.')
# define V2(a) (a == '\n')
# define V3(a) (a == '#')
# define RGT(a) (a + 1)
# define LFT(a) (a - 1)
# define TOP(a) (a - 5)
# define BTM(a) (a + 5)

int		error()
{
	ft_putstr("error\n");
	return (0);
}

int		valid_input(char *str, int bytes)
{
	int		nblocks;
	int		n;
	int		i;
	int		k;
	int		x;
	int		count1;
	int		count2;
	
	bytes++;
	count1 = 0;
	nblocks = bytes/21;
	n = 0;
	while (n < bytes)
	{
		i = 0;
		while (i <= 15)
		{
			k = -1;
			while (++k <= 3)
			{
				x = n + i + k;
				if (str[x] == '#')
				{
					if (!((i >= 5 && V3(str[TOP(x)])) || (i <= 10 && V3(str[BTM(x)]))
							|| (k < 3 && V3(str[RGT(x)])) || (k > 0 && V3(str[LFT(x)]))))
								return (1);
				}
			}
			i += 5;
		}
		n += 21;
	}
	n = 0;
	while (n < bytes)
	{
		i = -1;
		count1 = 0;
		count2 = 0;
		while (++i < 19)
		{
			if (str[n + i] == '#')
				count1++;
			if (str[n + i] == '.')
				count2++;
		}
		if (count1 != 4)
			return (1);
		if (count2 != 12)
			return (1);
		n += 21;
	}
	n = 0;
	while (++n < nblocks - 1)
	{
		if (str[n * 20 + (n - 1)] != '\n')
			return (1);
	}
	n = 0;
	while (n < bytes)
	{
		i = 0;
		while (i <= 15)
		{
			if (!V1(str[n + i + 0]) || !V1(str[n + i + 1]) || !V1(str[n + i + 2])
					|| !V1(str[n + i + 3]) || !V2(str[n + i + 4]))
				return (1);
			i += 5;
		}
		n += 21;
	}
	return (0);
}


int		main(int av, char **ac)
{
	int		fd;
	int		rd;
	char	*str;
	char	**tbl;

	CHK1(av != 2, ft_putstr("usage: ./fillit source_file\n"), 0);
	CHK1((str = (char*)malloc(sizeof(char) * BUFFER_SIZE)) == NULL, ft_putstr("error\n"), 0);
	ft_bzero((void *)str, BUFFER_SIZE);
	if ((fd = open(ac[1], O_RDONLY)) != 0)
	{
		CHK2((rd = read(fd, str, BUFFER_SIZE)) < 0, error(), free(str), 0);
		CHK2(str[545] != 0, error(), free(str), 0);
		CHK2(valid_input(str, rd) == 1, error(), free(str), 0);
		change_end(&str, rd);
		CHK2((tbl = ft_strsplit(str, '@')) == 0, error(), free(str), 0);
		trim_newline(tbl);
		trim_block(tbl);
		CHK2(valid_pattern(tbl, rd) == 1, error(), free(str), 0);
		/**
		int		i = 0;

		while (tbl[i])
		{
			printf("%s\n", tbl[i]);
			i++;
		}
		close(fd);
		**/
	}
	else
		ft_putstr("error\n");

	return (0);
}
