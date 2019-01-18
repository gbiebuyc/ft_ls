/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 09:56:19 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 11:26:46 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_error(t_fileinfo **error_lst, t_fileinfo *new)
{
	t_fileinfo	**curr;

	curr = error_lst;
	while (*curr && ft_strcmp((*curr)->path, new->path) <= 0)
		curr = &(*curr)->next;
	new->next = *curr;
	*curr = new;
}
