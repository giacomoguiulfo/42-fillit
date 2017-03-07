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

# define EXT(a, b) do{if(a){exit(b);}}while(0)
# define EXT1(a, b, c) do{if(a){b; exit(c);}}while(0)

# include <stdio.h>

int		error(void);
void	change_end(char **src, int bytes);
void	trim_block(char **src);
void	trim_newline(char **src);
int		valid_pattern(char **src, int blocks);
#endif
