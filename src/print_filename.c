/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:33:07 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/20 15:20:05 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_filename(t_file *f)
{
	if (get_opt()->colors)
		print_color(f->stat.st_mode);
	ft_putstr(f->name);
	if (get_opt()->colors)
		ft_putstr("\e[0m");
	if (S_ISDIR(f->stat.st_mode) &&
			(get_opt()->slashafterdir || get_opt()->classify))
		ft_putchar('/');
	else if (get_opt()->classify)
	{
		if (S_ISLNK(f->stat.st_mode))
			ft_putchar('@');
		else if (S_ISSOCK(f->stat.st_mode))
			ft_putchar('=');
		else if (S_ISFIFO(f->stat.st_mode))
			ft_putchar('|');
		else if (f->stat.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))
			ft_putchar('*');
	}
}
