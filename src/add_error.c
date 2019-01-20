/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 09:56:19 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/20 15:00:17 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_error(t_file **error_lst, t_file *new)
{
	t_file	**curr;

	curr = error_lst;
	while (*curr && ft_strcmp((*curr)->path, new->path) <= 0)
		curr = &(*curr)->next;
	new->next = *curr;
	*curr = new;
}
