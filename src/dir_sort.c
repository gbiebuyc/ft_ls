/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:34:36 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 11:55:15 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool	checkswap(t_fileinfo *f1, t_fileinfo *f2)
{
	t_fileinfo *tmp;

	if (get_opt()->nosort)
		return (false);
	if (get_opt()->sortreverse)
	{
		tmp = f1;
		f1 = f2;
		f2 = tmp;
	}
	if (get_opt()->sortbysize)
	{
		if (f1->stat.st_size - f2->stat.st_size < 0)
			return (true);
		if (f1->stat.st_size - f2->stat.st_size > 0)
			return (false);
	}
	else if (get_opt()->sortbytime)
	{
		if (f1->stat.st_mtime - f2->stat.st_mtime < 0)
			return (true);
		if (f1->stat.st_mtime - f2->stat.st_mtime > 0)
			return (false);
	}
	return (ft_strcmp(f1->name, f2->name) > 0);
}

/*
** Simple bubble sort on a linked list
*/

void	sort_lst(t_fileinfo **lst)
{
	t_fileinfo	**pcurr;
	t_fileinfo	*curr;
	t_fileinfo	*next;
	bool		done;

	done = false;
	while (!done && *lst)
	{
		pcurr = lst;
		curr = *lst;
		done = true;
		while ((next = curr->next) != 0)
		{
			if (checkswap(curr, next))
			{
				curr->next = next->next;
				next->next = curr;
				*pcurr = next;
				done = false;
			}
			pcurr = &curr->next;
			curr = next;
		}
	}
}

void	dir_sort(t_dirinfo *d)
{
	sort_lst(&d->files);
	sort_lst(&d->dirs);
}
