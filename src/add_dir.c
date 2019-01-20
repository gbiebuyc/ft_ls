/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:13:38 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/20 19:07:04 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_dir(t_file *info, t_dir *d)
{
	t_dir	*new;
	t_dir	**curr;

	if (!(new = malloc(sizeof(t_dir))))
	{
		ft_putstr_fd("malloc error\n", 2);
		exit(EXIT_FAILURE);
	}
	*new = (t_dir){.info = info};
	curr = &d->dirs;
	while (*curr && check_sort((*curr)->info, new->info))
		curr = &(*curr)->next;
	new->next = *curr;
	*curr = new;
}
