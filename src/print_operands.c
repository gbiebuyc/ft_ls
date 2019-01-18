/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 09:43:21 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 09:52:51 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_operands(t_operands *oper,
		t_fileinfo *file, t_fileinfo *dir, t_fileinfo *err)
{
	while (err)
	{
		lstat(err->path, &err->stat);
		ft_dprintf(2, "ls: %s: %s\n", err->path, strerror(errno));
		err = err->next;
	}
	while (file)
	{
		print_file(file, &oper->files);
		file = file->next;
	}
	while (dir)
	{
		if (oper->files.files || dir != oper->dirs)
			ft_putchar('\n');
		if (oper->operand_count > 1)
			ft_printf("%s:\n", dir->path);
		list_dir(dir->path);
		dir = dir->next;
	}
}
