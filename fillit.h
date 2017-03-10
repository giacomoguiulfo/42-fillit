/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:03:05 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/09 16:36:18 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include "libft.h"
# include <stdlib.h>
# define BUFFER_SIZE 546
# define V1(a) (a == '#' || a == '.')
# define V2(a) (a == '\n')
# define V3(a) (a == '#' || a == '.' || a == '\n')
# define NOTEMPTY(a) (a == '\0' || a == '.')
# define DOT(a) (a == '.')
# define V6(a) (a == '\0')
# define DO2(a, b) if(1){a; b;}
# define DO3(a, b, c) if(1){a; b; c;}
# define DO4(a, b, c, d) if(1){a; b; c; d;}

typedef enum	e_bool
{
	false,
	true
}				t_bool;

int		error(void);
void	change_end(char **src, int bytes);
void	trim_block(char **src);
void	trim_newline(char **src);
t_bool	valid_pattern(char **src, int blocks);
void	rename_block(char **src);
int		solve(char **tbl, size_t blocks);
#endif
