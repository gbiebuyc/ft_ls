/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:39:31 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/20 18:46:20 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	file_lst_free(t_file **lst, t_file **tail)
{
	t_file	*tmp;

	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	if (tail)
		*tail = NULL;
}

void	dir_lst_free(t_dir **lst, t_dir **tail)
{
	t_dir	*tmp;

	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free((*lst)->info);
		free(*lst);
		*lst = tmp;
	}
	if (tail)
		*tail = NULL;
}

void	dir_free(t_dir *d)
{
	file_lst_free(&d->files, &d->files_tail);
	dir_lst_free(&d->dirs, &d->dirs_tail);
	file_lst_free(&d->errors, 0);
}
