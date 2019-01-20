/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:34:36 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/20 19:15:40 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool	check_sort(t_file *f1, t_file *f2)
{
	t_file *tmp;

	if (get_opt()->nosort)
		return (true);
	if (get_opt()->sortreverse)
	{
		tmp = f1;
		f1 = f2;
		f2 = tmp;
	}
	if (get_opt()->sortbysize)
	{
		if (f1->stat.st_size - f2->stat.st_size < 0)
			return (false);
		if (f1->stat.st_size - f2->stat.st_size > 0)
			return (true);
	}
	else if (get_opt()->sortbytime)
	{
		if (f1->stat.st_mtime - f2->stat.st_mtime < 0)
			return (false);
		if (f1->stat.st_mtime - f2->stat.st_mtime > 0)
			return (true);
	}
	return (ft_strcmp(f1->name, f2->name) <= 0);
}

/*
** Simple bubble sort on a linked list
*/
/*
void	sort_lst(t_file **lst)
{
	t_file	**pcurr;
	t_file	*curr;
	t_file	*next;
	bool	done;

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
*/
