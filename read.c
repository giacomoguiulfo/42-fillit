/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:02:04 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/05 20:00:04 by jkalia           ###   ########.fr       */
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

int		error()
{
	ft_putstr("error1\n");
	return (1);
}

int		valid_input(char **s, int bytes)
{
	int		nblocks;
	char	*str;
	int		n;
	
	str = *s;
	bytes++;
	nblocks = bytes/21;
	CHK
	n = -1;
	while (++n < nblocks)
	{
		if (str[n * 21 + 4] != '\n' || str[n * 21 + 9] != '\n' || str[n * 21 + 14] != '\n' || str[n * 21 + 19] != '\n')
			return (1);
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
		CHK2(valid_input(&str, rd) == 1, ft_putstr("error\n"), free(str), 0):
		close(fd);
	}
	else
		ft_putstr("error\n");
	free(str);
	return (0);
}
