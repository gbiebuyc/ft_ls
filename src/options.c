/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:18:08 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/21 01:16:35 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt	*get_opt(void)
{
	static t_opt	options;

	return (&options);
}

void	toggle_option3(char c)
{
	if (c == 'o')
	{
		get_opt()->hide_group = true;
		get_opt()->longformat = true;
		get_opt()->need_stat = true;
	}
	else if (c == 'd')
		get_opt()->listdirasfile = true;
	else if (c == 'T')
		get_opt()->completetime = true;
	else
	{
		ft_dprintf(2, "ls: illegal option -- %c\nusage: ls [-ABC"
				"FGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", c);
		exit(EXIT_FAILURE);
	}
}

void	toggle_option2(char c)
{
	if (c == 'F')
	{
		get_opt()->classify = true;
		get_opt()->slashafterdir = false;
		get_opt()->need_stat = true;
	}
	else if (c == 'G')
	{
		get_opt()->colors = true;
		get_opt()->need_stat = true;
	}
	else if (c == 'u')
		get_opt()->time_field = LAST_ACCESS;
	else if (c == 'c')
		get_opt()->time_field = LAST_STATUS_CHANGE;
	else if (c == 'U')
		get_opt()->time_field = FILE_CREATION;
	else if (c == 'f')
	{
		get_opt()->nosort = true;
		get_opt()->all = true;
	}
	else if (c == 'g')
	{
		get_opt()->hide_owner = true;
		get_opt()->longformat = true;
		get_opt()->need_stat = true;
	}
	else
		toggle_option3(c);
}

void	toggle_option(char c)
{
	if (c == '1')
		get_opt()->longformat = false;
	else if (c == 'l')
	{
		get_opt()->longformat = true;
		get_opt()->need_stat = true;
	}
	else if (c == 'R')
	{
		get_opt()->recursive = true;
		get_opt()->need_stat = true;
	}
	else if (c == 'a')
		get_opt()->all = true;
	else if (c == 'A')
		get_opt()->a_maj = true;
	else if (c == 'r')
		get_opt()->sortreverse = true;
	else if (c == 't')
	{
		get_opt()->sortbytime = true;
		get_opt()->need_stat = true;
	}
	else if (c == 'S')
	{
		get_opt()->sortbysize = true;
		get_opt()->need_stat = true;
	}
	else if (c == 'p')
	{
		get_opt()->slashafterdir = true;
		get_opt()->classify = false;
		get_opt()->need_stat = true;
	}
	else
		toggle_option2(c);
}
