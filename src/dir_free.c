/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:39:31 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 11:45:07 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	dir_free(t_dirinfo *d)
{
	lst_free(&d->files, &d->files_tail);
	lst_free(&d->dirs, &d->dirs_tail);
	lst_free(&d->errors, 0);
}
