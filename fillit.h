/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:03:05 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/08 22:29:12 by jkalia           ###   ########.fr       */
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

typedef enum	e_bool
{
	false,
	true
}				t_bool;

int		error(void);
void	change_end(char **src, int bytes);
void	trim_block(char **src);
void	trim_newline(char **src);
int		valid_pattern(char **src, int blocks);
void	rename_block(char **src);
int		solve(char **tbl, size_t blocks);
#endif
