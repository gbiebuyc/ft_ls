/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:34:36 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/21 13:29:01 by gbiebuyc         ###   ########.fr       */
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
