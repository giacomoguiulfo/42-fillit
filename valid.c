/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_ttmn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:27:17 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/10 16:53:11 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_bool	bool_strstr(const char *src, const char *to_find)
{
	int			len;

	while (*src)
	{
		len = 0;
		while (*src == *to_find)
		{
			to_find++;
			src++;
			len++;
			if (!*to_find)
				return (true);
		}
		src = src - len;
		to_find = to_find - len;
		src++;
	}
	return (false);
}

void	populate_valid(int i, char valid[20][15])
{
	while (++i < 20)
	{
		ft_bzero(valid[i], sizeof(valid[i]));
	}
	ft_strcpy(valid[0], "###...#");
	ft_strcpy(valid[1], ".#...#..##");
	ft_strcpy(valid[2], "#...###");
	ft_strcpy(valid[3], "##..#...#");
	ft_strcpy(valid[4], "###.#");
	ft_strcpy(valid[5], "##...#...#");
	ft_strcpy(valid[6], "..#.###");
	ft_strcpy(valid[7], "#...#...##");
	ft_strcpy(valid[8], "###..#");
	ft_strcpy(valid[9], ".#..##...#");
	ft_strcpy(valid[10], ".#..###");
	ft_strcpy(valid[11], "#...##..#");
	ft_strcpy(valid[12], ".##.##");
	ft_strcpy(valid[13], "#...##...#");
	ft_strcpy(valid[14], "##..##");
	ft_strcpy(valid[15], "#...#...#...#");
	ft_strcpy(valid[16], "####");
	ft_strcpy(valid[17], ".#..##..#");
	ft_strcpy(valid[18], "##...##");
}

t_bool	valid_pattern(char **src, int blocks)
{
	char	valid[20][15];
	int		i;
	int		j;
	int		valid_flg;

	populate_valid(-1, valid);
	i = -1;
	while (++i < blocks)
	{
		valid_flg = 0;
		j = -1;
		while (++j < 19)
		{
			if (bool_strstr(src[i], valid[j]) == true)
			{
				ft_bzero(src[i], ft_strlen(src[i]));
				ft_strcpy(src[i], valid[j]);
				valid_flg = 1;
				break ;
			}
		}
		if (!valid_flg)
			return (false);
	}
	return (true);
}
