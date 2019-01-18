/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:31:23 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 13:14:38 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	static t_dirinfo	d;

	(void)ac;
	parse_args(av, &d);
	dir_sort(&d);
	dir_print(&d, d.errors, d.files, d.dirs);
	dir_free(&d);
}
