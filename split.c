/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:04:46 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/10 12:47:17 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	change_end(char **src, int bytes)
{
	int		i;
	char	*ch;

	ch = *src;
	i = 21;
	while (i < bytes)
	{
		ch[i - 1] = '@';
		i += 21;
	}
}

void	trim_newline(char **src)
{
	int		i;
	int		j;
	int		k;
	char	tmp[20];

	i = 0;
	while (src[i])
	{
		j = 0;
		k = 0;
		while (src[i][j])
		{
			if (src[i][j] == '\n')
				++j;
			tmp[k] = src[i][j];
			++k;
			++j;
		}
		ft_strcpy(src[i], tmp);
		i++;
	}
}

void	rename_block(char **src)
{
	int		i;
	char	n;
	char	*tmp;

	i = 0;
	n = 'A';
	while (src[i])
	{
		tmp = src[i];
		while (*tmp)
		{
			if (*tmp == '#')
				*tmp = n;
			tmp++;
		}
		++n;
		++i;
	}
}
