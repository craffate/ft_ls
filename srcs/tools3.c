/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:31:04 by craffate          #+#    #+#             */
/*   Updated: 2017/02/12 18:41:06 by craffate         ###   ########.fr       */
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

int		cmp(t_file *file, t_file *args, int fl)
{
	if (fl & LS_F)
		return (1);
	if (fl & LS_T)
	{
		if (fl & LS_U)
		{
			return (fl & LS_R ? (file->stat.st_atime > args->stat.st_atime) :
					(file->stat.st_atime <= args->stat.st_atime));
		}
		return (fl & LS_R ? (file->stat.st_mtime > args->stat.st_mtime) :
				(file->stat.st_mtime <= args->stat.st_mtime));
	}
	if (fl & LS_R)
		return (ft_strcmp(file->name, args->name) < 1) ? 1 : 0;
	return (ft_strcmp(file->name, args->name) > 0) ? 1 : 0;
}

int		pathcheck(char *s, int i)
{
	if (*s == '.' && (!(i & LS_A) || (!*(s + 1) ||
		(*(s + 1) == '.' && !*(s + 2)))))
		return (1);
	else
		return (0);
}
