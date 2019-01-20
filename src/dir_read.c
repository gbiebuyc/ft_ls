/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 09:36:23 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/20 23:51:32 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool	dir_read(t_dir *d)
{
	DIR				*dir;
	struct dirent	*entry;
	t_file			*new;

	if (!(dir = opendir(d->info.path)))
		return (false);
	while ((entry = readdir(dir)))
	{
		if ((entry->d_name[0] != '.') || get_opt()->all ||
				(get_opt()->a_maj && !ft_strequ(entry->d_name, ".") &&
				 !ft_strequ(entry->d_name, "..")))
		{
			if (!new_file(&new, d->info.path, entry->d_name))
				add_error(new, &d->errors);
			else
			{
				add_file(new, d);
				if (!ft_strequ(new->name, ".") && !ft_strequ(new->name, "..")
						&& get_opt()->recursive && S_ISDIR(new->stat.st_mode))
					add_dir(new, d);
			}
		}
	}
	closedir(dir);
	return (true);
}
