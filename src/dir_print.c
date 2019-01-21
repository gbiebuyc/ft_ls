/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 09:23:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/21 02:03:07 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	dir_print(t_dir *d,
		t_file *err, t_file *file, t_dir *dir)
{
	while (err)
	{
		lstat(err->path, &err->stat);
		ft_dprintf(2, "ls: %s: %s\n", err->name, strerror(errno));
		err = err->next;
	}
	if (file && get_opt()->longformat && get_opt()->print_block_count)
		ft_printf("total %jd\n", d->total_block_count);
	get_opt()->print_block_count = true;
	while (file)
	{
		print_file(file, d);
		file = file->next;
	}
	while (dir)
	{
		if (d->files || dir != d->dirs)
			ft_putchar('\n');
		if ((d->errors || d->files || d->dirs->next) &&
			!(ft_strequ(dir->info.path, ".") && get_opt()->no_operands_given))
			ft_printf("%s:\n", dir->info.path);
		list_dir(dir);
		dir = dir->next;
	}
}
