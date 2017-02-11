/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:31:04 by craffate          #+#    #+#             */
/*   Updated: 2017/02/11 15:17:35 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*getdate_ls(time_t t)
{
	char			*time;
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 4;
	time = ft_strnew(12);
	tmp = ctime(&t);
	while (tmp[j - 3] != ':')
		time[i++] = tmp[j++];
	return (time);
}

char	rights_type(t_file *file)
{
	char	c;

	c = 0;
	if (S_ISLNK((*file).stat.st_mode))
		c = 'l';
	else if (S_ISSOCK((*file).stat.st_mode))
		c = 's';
	else if (S_ISBLK((*file).stat.st_mode))
		c = 'b';
	else if (S_ISCHR((*file).stat.st_mode))
		c = 'c';
	else if (S_ISFIFO((*file).stat.st_mode))
		c = 'p';
	else if (S_ISDIR((*file).stat.st_mode))
		c = 'd';
	else
		c = '-';
	return (c);
}
