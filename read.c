/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:02:04 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/05 12:55:31 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	error(void)
{
	ft_putstr("error\n");
}

int		main(int av, char **ac)
{
	int		fd;
	int		rd;
	char	*str;

	CHK1(av != 1, error(), 0);
	CHK1((str = (char *)malloc(sizeof(char) * (BUFFER * 1)) == NULL, error(), 0);

	if ((fd = open(ac[0], O_RDONLY)) > 0))
	{
		CHK1(rd = read(fd, str, BUFFER) != BUFFER, error(), 0);
		read, 
	}
	else
		error();

	return (0);
}
