/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:30:12 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/22 19:28:12 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

char	**create_tetri(char *l0, char *l1, char *l2, char *l3)
{
	char **tetri;
	int i;

	if (!(tetri = (char**)malloc(sizeof(char*)*5)))
		return (NULL);
	i = -1;
	if (l0)
		if (!(tetri[++i] = ft_strdup(l0)))
			return (NULL);
	if (l1)
		if (!(tetri[++i] = ft_strdup(l1)))
			return (NULL);
	if (l2)
		if (!(tetri[++i] = ft_strdup(l2)))
			return (NULL);
	if (l3 != NULL)
		if (!(tetri[++i] = ft_strdup(l3)))
			return (NULL);
	while(++i < 5)
		tetri[i] = NULL;
	return (tetri);
}

int main()
{
	char	**tetri;
	t_tetri	**lst;
	t_tetri	*tmp;

	if (!(lst = (t_tetri**)malloc(sizeof(t_tetri))))
		return(-1);
	*lst = NULL;
	if (!(tetri = create_tetri("#", "#", "#", "#")))
		return (-1);
	if (!(tmp = lst_new(tetri, 0)))
		return (-1);
	lst_add_back(lst, tmp);
	printf("index : %d\n", (*lst)->index);
	free(tmp);
	printf("index : %d\n", (*lst)->index);
	if (!(tetri = create_tetri("##", "##", NULL, NULL)))
		return (-1);
//	if (!(tmp = lst_new(tetri, 1)))
//		return (-1);
	printf("before index : %d\n", (*lst)->index);
	printf("before address : %p\n", (*lst));
	tmp = lst_new(tetri, 1);
	printf("before index : %d\n", (*lst)->index);
	printf("before address : %p\n", (*lst));
	lst_add_back(lst, tmp);
	printf("index : %d\n", (*lst)->index);
	printf("next : %p\n", (*lst)->next);
	lst_iter(*lst, &print_node);
}
