/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 09:23:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/20 15:06:06 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	dir_print(t_dirinfo *d,
		t_file *err, t_file *file, t_dir *dir)
{
	while (err)
	{
		lstat(err->path, &err->stat);
		ft_dprintf(2, "ls: %s: %s\n", err->path, strerror(errno));
		err = err->next;
	}
	while (file)
	{
		print_file(file, d);
		file = file->next;
	}
	while (dir)
	{
		if (d->files || dir != d->dirs)
			ft_putchar('\n');
		if (!(ft_strequ(dir->path, ".") && get_opt()->operand_count == 0) &&
				get_opt()->operand_count > 1)
			ft_printf("%s:\n", dir->path);
		list_dir(dir);
		dir = dir->next;
	}
}
