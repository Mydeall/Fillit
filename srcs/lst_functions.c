/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:01:03 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/22 19:26:41 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

t_tetri	*lst_new(char **tetri, int index)
{
	t_tetri	*new;

	if (!(new = (t_tetri*)malloc(sizeof(t_list))))
		return (NULL);
	new->tetrimino = tetri;
	new->index = index;
	new->next = NULL;
	return (new);
}

void	lst_add_back(t_tetri **lst, t_tetri *new)
{
	t_tetri *current;

	if (!(lst))
	{
		ft_putendl("lst_add_back error : lst is NULL");
		return ;
	}
	if (!(*lst))
	{
		printf("NULL\n");
		*lst = new;
		(*lst)->next = NULL;
		return ;
	}
	printf("before 2 index : %d\n", (*lst)->index);
	printf("before 2 address : %p\n", *lst);
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
	current->next->next = NULL;
	printf("pointeur : %p\n", *lst);
}

void	lst_iter(t_tetri *lst, void (*f)(t_tetri *ielem))
{
	t_tetri *cpy;

	if (!(lst))
	{
		ft_putendl("lst_iter error : lst is NULL");
		return ;
	}
	cpy = lst;
	while (cpy)
	{
		f(cpy);
		cpy = cpy->next;
	}
}

void	print_node(t_tetri *lst)
{
	int i;

	if (!(lst))
	{
		ft_putendl("print_node : WARNING, node is (null)");
		return ;
	}
	i = -1;
	ft_putstr("Tetrimino ");
	ft_putnbr(lst->index);
	ft_putendl(" : ");
	while (lst->tetrimino[++i])
	{
		ft_putendl(lst->tetrimino[i]);
	}
}
