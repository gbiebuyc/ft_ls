/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:34:01 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 11:34:03 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_year(char *timestr)
{
	int		i_year;

	i_year = 0;
	while (timestr[i_year] && timestr[i_year] != '\n')
		i_year++;
	timestr[i_year] = '\0';
	while ((i_year - 1) >= 0 && timestr[i_year - 1] != ' ')
		i_year--;
	return (timestr + i_year);
}

void	print_time(time_t t)
{
	time_t	now;
	char	*timestr;

	time(&now);
	timestr = ctime(&t) + 4;
	if (ft_abs(t - now) > 15778800)
		ft_printf(" %.6s  %s", timestr, get_year(timestr));
	else
		ft_printf(" %.12s", timestr);
}

void	print_complete_time(time_t t)
{
	char	*timestr;

	timestr = ctime(&t) + 4;
	ft_printf(" %.15s %s", timestr, get_year(timestr));
}
