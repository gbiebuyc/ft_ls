/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:06:27 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/20 21:01:52 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_file(t_file *new, t_dir *d)
{
	t_file	**curr;

	curr = &d->files;
	while (*curr && check_sort(*curr, new))
		curr = &(*curr)->next;
	new->next = *curr;
	*curr = new;
	d->total_block_count += new->stat.st_blocks;
	d->lnk_col_width = ft_max(d->lnk_col_width,
			(int)ft_strlen(ft_itoa_static(new->stat.st_nlink)));
	d->owner_col_width = ft_max(d->owner_col_width,
			(int)ft_strlen(getpwuid(new->stat.st_uid)->pw_name));
	d->group_col_width = ft_max(d->group_col_width,
			(int)ft_strlen(getgrgid(new->stat.st_gid)->gr_name));
	if (S_ISBLK(new->stat.st_mode) || S_ISCHR(new->stat.st_mode))
		d->bytes_col_width = ft_max(d->bytes_col_width, 9);
	else
		d->bytes_col_width = ft_max(d->bytes_col_width,
				ft_strlen(ft_itoa_static(new->stat.st_size)) + 1);
}
