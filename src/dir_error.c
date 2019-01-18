/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 09:28:59 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 09:29:24 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	dir_error(char *path)
{
	char *dirname;

	dirname = path;
	while (*path)
	{
		if (*path == '/')
			dirname = path + 1;
		path++;
	}
	ft_dprintf(2, "ls: %s: %s\n", dirname, strerror(errno));
}
