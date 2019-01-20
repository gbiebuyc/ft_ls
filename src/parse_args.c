/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:32:24 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/20 17:41:56 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool	is_dir(char *filepath, bool longformat)
{
	struct stat	s;

	if (longformat)
		lstat(filepath, &s);
	else
		stat(filepath, &s);
	return (S_ISDIR(s.st_mode));
}

/*
** I hardcoded a fake error in the following function to imitate
** a behaviour that seems to only happen on crapOS Sierra and below.
*/

bool	parse_options(char *s)
{
	if (s[0] == '\0')
	{
		ft_putstr_fd("ls: fts_open: No such file or directory\n", 2);
		exit(EXIT_FAILURE);
	}
	if (s[0] == '-' && s[1] && !get_opt()->endofoptions)
	{
		if (ft_strequ(s, "--"))
			get_opt()->endofoptions = true;
		else
			while (*++s)
				toggle_option(*s);
		return (true);
	}
	return (false);
}

void	add_operand(char *path, t_dir *d)
{
	t_file	*new;

	if (is_dir(path, get_opt()->longformat) && !get_opt()->listdirasfile)
		add_dir(path, d);
	else if (!new_file(&new, 0, path))
		add_error(&d->errors, new);
	else
		add_file(new, d);
}

void	parse_args(char **av, t_dir *d)
{
	get_opt()->no_operands_given = true;
	while (*++av)
	{
		if (parse_options(*av))
			continue ;
		get_opt()->no_operands_given = false;
		get_opt()->endofoptions = true;
		add_operand(*av, d);
	}
	if (get_opt()->no_operands_given)
		add_operand(".", d);
}
