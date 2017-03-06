/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:02:04 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/05 22:34:29 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

# define BUFFER_SIZE 546
# define V1(a) (a == '#' || a == '.')
# define V2(a) (a == '\n')

int		error()
{
	ft_putstr("error1\n");
	return (1);
}

int		valid_input(char *str, int bytes)
{
	int		nblocks;
	int		n;
	int		i;
	int		count1;
	int		count2;
	
	bytes++;
	nblocks = bytes/21;
	count2 = 0;
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
		if (count1 != 4 && count1 != 0)
			return (1);
		if (count2 != 12 && count2 != 16)
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

	CHK1(av != 2, ft_putstr("usage: ./fillit source_file\n"), 0);
	CHK1((str = (char*)malloc(sizeof(char) * BUFFER_SIZE)) == NULL, ft_putstr("error\n"), 0);
	ft_bzero((void *)str, BUFFER_SIZE);
	if ((fd = open(ac[1], O_RDONLY)) != 0)
	{
		CHK2((rd = read(fd, str, BUFFER_SIZE)) < 0, ft_putstr("error\n"), free(str), 0);
		CHK2(str[545] != 0, ft_putstr("error\n"), free(str), 0);
		CHK2(valid_input(str, rd) == 1, ft_putstr("error\n"), free(str), 0);
		close(fd);
	}
	else
		ft_putstr("error\n");
	free(str);
	return (0);
}
