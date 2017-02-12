/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 01:11:19 by craffate          #+#    #+#             */
/*   Updated: 2017/02/12 17:54:48 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t			*arrnew(size_t s)
{
	size_t			*arr;
	unsigned int	i;

	if (!(arr = malloc(sizeof(size_t) * s)))
		return (0);
	i = 0;
	while (i != s)
		arr[i++] = 0;
	return (arr);
}

long long int	total(t_file **dir)
{
	long long int	t;

	t = 0;
	while (*dir)
	{
		t += (**dir).stat.st_blocks;
		dir++;
	}
	return (t);
}

int				execcheck(t_file *file)
{
	return ((*file).stat.st_mode & S_IXUSR || (*file).stat.st_mode & S_IXGRP ||
			(*file).stat.st_mode & S_IXOTH ? 1 : 0);
}

void			getsizes(size_t *schars, t_file **files, t_file **dirs,
				t_file **hfiles)
{
	files ? maxsizechars(files, schars) : 0;
	dirs ? maxsizechars(dirs, schars) : 0;
	hfiles ? maxsizechars(hfiles, schars) : 0;
}

size_t			gettotals(int i, t_file **files,
				t_file **hfiles, t_file **dirs)
{
	size_t	t;

	t = 0;
	t = files ? total(files) : t;
	t += dirs ? total(dirs) : 0;
	t += i & LS_A && hfiles ? total(hfiles) : 0;
	return (t);
}
