/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:32:40 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 11:32:41 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_color(mode_t mode)
{
	if (S_ISDIR(mode) && (mode & S_IWOTH) && (mode & S_ISVTX))
		ft_putstr("\e[30;42m");
	else if (S_ISDIR(mode) && (mode & S_IWOTH))
		ft_putstr("\e[30;43m");
	else if (S_ISDIR(mode))
		ft_putstr("\e[34;49m");
	else if (S_ISLNK(mode))
		ft_putstr("\e[35;49m");
	else if (S_ISSOCK(mode))
		ft_putstr("\e[32;49m");
	else if (S_ISFIFO(mode))
		ft_putstr("\e[33;49m");
	else if (mode & (S_IXUSR | S_IXGRP | S_IXOTH) && (mode & S_ISUID))
		ft_putstr("\e[30;41m");
	else if (mode & (S_IXUSR | S_IXGRP | S_IXOTH) && (mode & S_ISGID))
		ft_putstr("\e[30;46m");
	else if (mode & (S_IXUSR | S_IXGRP | S_IXOTH))
		ft_putstr("\e[31;49m");
	else if (S_ISBLK(mode))
		ft_putstr("\e[34;46m");
	else if (S_ISCHR(mode))
		ft_putstr("\e[34;43m");
}
