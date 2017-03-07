/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_ttmn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:27:17 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/07 12:06:29 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	populate_valid(int i, char valid[20][15])
{
	while (++i < 20)
	{
		ft_bzero(valid[i], sizeof(valid[i]));
	}
	ft_strcpy(valid[0], "###...#");
	ft_strcpy(valid[1], "#...#..##");
	ft_strcpy(valid[2], "#...###");
	ft_strcpy(valid[3], "##..#...#");
	ft_strcpy(valid[4], "###.#");
	ft_strcpy(valid[5], "##...#...#");
	ft_strcpy(valid[6], "#.###");
	ft_strcpy(valid[7], "#...#...##");
	ft_strcpy(valid[8], "###..#");
	ft_strcpy(valid[9], "#..##...#");
	ft_strcpy(valid[10], "#..###");
	ft_strcpy(valid[11], "#...##..#");
	ft_strcpy(valid[12], "##.##");
	ft_strcpy(valid[13], "#...##...#");
	ft_strcpy(valid[14], "##..##");
	ft_strcpy(valid[15], "#...#...#...#");
	ft_strcpy(valid[16], "####"),
	ft_strcpy(valid[17], "#..##..#");
	ft_strcpy(valid[18], "##...##");
}

int		valid_pattern(char **src, int blocks)
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
			if (ft_strequ(src[i], valid[j]) == 1)
			{
				valid_flg = 1;
				break ;
			}
		}
		if (!valid_flg)
			return (1);
	}
	return (0);
}
