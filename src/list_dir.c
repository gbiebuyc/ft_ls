/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 08:41:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/20 19:11:13 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	list_dir(t_dir *d)
{
	if (!dir_read(d))
		return (dir_error(d->info->path));
	//sort_lst(&d->files);
	if (get_opt()->longformat)
		ft_printf("total %jd\n", d->total_block_count);
	dir_print(d, d->errors, d->files, d->dirs);
	dir_free(d);
}
