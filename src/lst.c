/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:31:39 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 11:49:02 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lst_add(t_fileinfo *new, t_fileinfo **head, t_fileinfo **tail)
{
	if (!*tail)
		*head = new;
	else
		(*tail)->next = new;
	*tail = new;
}

void	lst_free(t_fileinfo **lst, t_fileinfo **tail)
{
	t_fileinfo	*tmp;

	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	if (tail)
		*tail = NULL;
}
