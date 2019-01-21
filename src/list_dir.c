/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 08:41:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/21 01:47:55 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	list_dir(t_dir *d)
{
	if (!dir_read(d))
		return (dir_error(d->info.path));
	dir_print(d, d->errors, d->files, d->dirs);
	dir_free(d);
}
