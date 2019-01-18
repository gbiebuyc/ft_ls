/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 08:41:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 13:47:30 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	list_subdirs(t_dirinfo *d)
{
	t_fileinfo	*f;

	f = d->files;
	while (f)
	{
		if (S_ISDIR(f->stat.st_mode) &&
				!ft_strequ(f->name, ".") && !ft_strequ(f->name, ".."))
		{
			ft_printf("\n%s:\n", f->path);
			list_dir(f->path);
		}
		f = f->next;
	}
}

void	list_dir(char *dir_path)
{
	t_dirinfo	d;

	d = (t_dirinfo){.dir_path = dir_path};
	if (!dir_read(&d))
		return (dir_error(dir_path));
	dir_sort(&d);
	if (get_opt()->longformat)
		ft_printf("total %jd\n", d.total_block_count);
	dir_print(&d, d.errors, d.files, d.dirs);
	if (get_opt()->recursive)
		list_subdirs(&d);
	dir_free(&d);
}
