/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <anrzepec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:23:13 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/29 11:56:15 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	free_error(char **tetris, t_tetri **lst)
{
	tab_free(tetris);
	free(tetris);
	lst_del(lst);
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*line;
	char	**tetris;
	t_tetri	**lst;

	fd = -42;
	ret = -1;
	if (!(lst = (t_tetri**)malloc(sizeof(t_tetri*))) \
			|| !(tetris = (char**)ft_memalloc(sizeof(char*) * 7)) \
			|| !(line = (char*)ft_memalloc(1)))
		return (1);
	*lst = NULL;
	if (ac == 2)
		if ((fd = open(av[1], O_RDONLY)) > 0)
			ret = read_file(fd, line, tetris, lst);
	free(line);
	if (ft_print_errors(ac, fd, ret))
		return (free_error(tetris, lst));
	free(tetris);
	if (ft_print_solution(fillit_solver(lst)))
		return (1);
	return (0);
}
