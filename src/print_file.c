/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:32:55 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 11:32:56 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*points_to(char *symlink)
{
	static char	buf[PATH_MAX];
	ssize_t		len;

	if ((len = readlink(symlink, buf, sizeof(buf) - 1)) != -1)
		buf[len] = '\0';
	else
		return (NULL);
	return (buf);
}

void	print_file_longformat(t_fileinfo *f, t_dirinfo *d)
{
	print_filetype(f->stat.st_mode);
	print_permissions(f->stat.st_mode);
	print_xattr_acl(f->path);
	ft_printf(" %*d", d->lnk_col_width, f->stat.st_nlink);
	if (!get_opt()->hide_owner)
		ft_printf(" %-*s ",
				d->owner_col_width, getpwuid(f->stat.st_uid)->pw_name);
	if (!get_opt()->hide_group)
		ft_printf(" %-*s ",
				d->group_col_width, getgrgid(f->stat.st_gid)->gr_name);
	if (get_opt()->hide_owner && get_opt()->hide_group)
		ft_putstr("  ");
	if (S_ISBLK(f->stat.st_mode) || S_ISCHR(f->stat.st_mode))
		ft_printf("%4d,%4d", major(f->stat.st_rdev), minor(f->stat.st_rdev));
	else
		ft_printf("%*d", d->bytes_col_width, f->stat.st_size);
	if (get_opt()->completetime)
		print_complete_time(f->stat.st_mtime);
	else
		print_time(f->stat.st_mtime);
	ft_putchar(' ');
	print_filename(f);
	if (S_ISLNK(f->stat.st_mode))
		ft_printf(" -> %s", points_to(f->path));
}

void	print_file(t_fileinfo *f, t_dirinfo *d)
{
	if (get_opt()->longformat)
		print_file_longformat(f, d);
	else
		print_filename(f);
	ft_putchar('\n');
}
