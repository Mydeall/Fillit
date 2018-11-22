/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrewrzepecki <anrzepec@student.42.f      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:35:43 by andrewrze         #+#    #+#             */
/*   Updated: 2018/11/22 18:00:29 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

typedef struct		s_tetri
{
	char			**tetrimino;
	int				index;
	struct s_tetri	*next;
}					t_tetri;

int     read_file(int fd, char **content);
t_tetri	*lst_new(char **tetri, int index);
void    lst_add_back(t_tetri **lst, t_tetri *new);
void    lst_iter(t_tetri *lst, void (*f)(t_tetri *ielem));
void    print_node(t_tetri *lst);

#endif
