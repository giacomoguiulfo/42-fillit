/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:02:04 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/07 12:03:37 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

extern int g_malloc_inject;

int		error()
{
	ft_putstr("error\n");
	return (0);
}

int		valid_1(char *str, int bytes)
{
	int n;
	int i;
	int count1;
	int count2;

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
	return (0);
}

int		valid_0(char *str, int bytes)
{
	if (valid_1(str, bytes) == 1)
		return (1);
	while (*str)
	{
		if (!VALID(*str))
			return (1);
		str++;
	}
	return (0);
}


int		main(int av, char **ac)
{
	int		fd;
	int		rd;
	char	*str;
	char	**tbl;

	g_malloc_inject = 4;

	CHK1(av != 2, ft_putstr("usage: ./fillit source_file\n"), 0);
	CHK1((str = (char*)malloc(sizeof(char) * BUFFER_SIZE)) == NULL,
		 ft_putstr("error\n"), 0);
	ft_bzero((void *)str, BUFFER_SIZE);
	if ((fd = open(ac[1], O_RDONLY)) != 0)
	{
		CHK2((rd = read(fd, str, BUFFER_SIZE)) < 0, error(), free(str), 0);
		CHK2(str[545] != 0, error(), free(str), 0);
		CHK2(valid_0(str, rd) == 1, error(), free(str), 0);
		change_end(&str, rd);
		CHK2((tbl = ft_strsplit(str, '@')) == 0, error(), free(str), 0);
		trim_newline(tbl);
		trim_block(tbl);
		CHK3(valid_pattern(tbl, (rd + 1) / 21) == 1, error(), ft_tbldel(tbl), free(str), 0);
	}
	else
		ft_putstr("error\n");

	return (0);
}
