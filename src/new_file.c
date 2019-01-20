/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:31:53 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/20 14:52:32 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool	new_file(t_file **new, char *path, char *name)
{
	if (!(*new = malloc(sizeof(t_file))))
	{
		ft_putstr_fd("malloc error\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_strcpy((*new)->name, name);
	(*new)->path[0] = '\0';
	if (path && *path)
	{
		ft_strcat((*new)->path, path);
		ft_strcat((*new)->path, "/");
	}
	ft_strcat((*new)->path, name);
	(*new)->next = NULL;
	if (lstat((*new)->path, &(*new)->stat) == -1)
		return (false);
	if (get_opt()->time_field == LAST_ACCESS)
		(*new)->stat.st_mtime = (*new)->stat.st_atime;
	if (get_opt()->time_field == LAST_STATUS_CHANGE)
		(*new)->stat.st_mtime = (*new)->stat.st_ctime;
	if (get_opt()->time_field == FILE_CREATION)
		(*new)->stat.st_mtime = (*new)->stat.st_birthtime;
	return (true);
}
