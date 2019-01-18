/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xattr_acl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:34:18 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 11:34:21 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_xattr_acl(char *file_path)
{
	acl_t	acl;

	if (listxattr(file_path, 0, 0, XATTR_NOFOLLOW) > 0)
		ft_putchar('@');
	else if ((acl = acl_get_file(file_path, ACL_TYPE_EXTENDED)))
	{
		ft_putchar('+');
		acl_free((void *)acl);
	}
	else
		ft_putchar(' ');
}
