/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:13:38 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/20 14:58:48 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_dir(char *dir_path, t_dir *d)
{
	t_dir	*new;

	if (!(new = malloc(sizeof(t_dir))))
	{
		ft_putstr_fd("malloc error\n", 2);
		exit(EXIT_FAILURE);
	}
	*new = (t_dir){.dir_path = dir_path};
	if (!d->dirs_tail)
		d->dirs = new;
	else
		d->dirs_tail->next = new;
	d->dirs_tail = new;
}
