/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 01:11:19 by craffate          #+#    #+#             */
/*   Updated: 2017/02/05 04:02:35 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	*arrnew(size_t s)
{
	size_t			*arr;
	unsigned int	i;

	if (!(arr = malloc(sizeof(size_t) * s)))
		return (0);
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
