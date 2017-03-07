/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:03:05 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/06 17:41:26 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>

# define BUFFER_SIZE 546
# define VALID(a) (a == '#' || a == '.' || a == '\n')

int		error(void);
void	change_end(char **src, int bytes);
void	trim_block(char **src);
void	trim_newline(char **src);
int		valid_pattern(char **src, int blocks);
#endif
