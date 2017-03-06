/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_ttmn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:27:17 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/06 13:57:45 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h";

int		valid_pattern(char **ttnm, int	blocks)
{
	char 	valid[20][15];
	int		i;
	int		j;
	int		valid_flg;
	i = -1;
	while (++i < 18)
	{
		ft_bzero(valid[i], 15);
	}
	populate_valid(valid);
	i = -1;
	j = 0;
	while (++i < blocks)
	{
		while (++j < 19)
		{
			if (ft_strequ(block[i], valid[j]) == 1)
			{
				valid_flg = 1;
				break ;
			}
		}
	}
	return ((valid_flg == 1) ? 0 : 1);
}

void	populate_valid(char **valid)
{
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
	ft_strcpy(valid[16], "####"),
	ft_strcpy(valid[17], ".#..##..#");
	ft_strcpy(valid[18], "##...##");
}
