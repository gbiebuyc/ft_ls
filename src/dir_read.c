/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 09:36:23 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 11:26:28 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool	dir_read(t_dirinfo *d)
{
	DIR				*dir;
	struct dirent	*entry;
	t_fileinfo		*new;

	if (!(dir = opendir(d->dir_path)))
		return (false);
	while ((entry = readdir(dir)))
	{
		if ((entry->d_name[0] != '.') || get_opt()->all ||
				(get_opt()->a_maj && !ft_strequ(entry->d_name, ".") &&
				 !ft_strequ(entry->d_name, "..")))
		{
			if (!new_file(&new, d->dir_path, entry->d_name))
				add_error(&d->errors, new);
			else
				add_file(new, d);
		}
	}
	closedir(dir);
	return (true);
}
