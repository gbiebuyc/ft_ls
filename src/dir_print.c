/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 09:23:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 13:47:02 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	dir_print(t_dirinfo *d,
		t_fileinfo *err, t_fileinfo *file, t_fileinfo *dir)
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
		if (get_opt()->operand_count > 1)
			ft_printf("%s:\n", dir->path);
		list_dir(dir->path);
		dir = dir->next;
	}
}
