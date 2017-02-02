/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:38:48 by craffate          #+#    #+#             */
/*   Updated: 2017/02/02 16:48:33 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*create_struct(char *name, char *path)
{
	t_file	*arg;

	if (!(arg = (t_file *)malloc(sizeof(t_file))))
		return (0);
	arg->name = ft_strdup(name);
	arg->path = ft_strdup(path);
	lstat(path, &arg->stat);
	return (arg);
}

void		freetab(t_file **tab)
{
	t_file **start;

	start = tab;
	while (*tab)
	{
		free((*tab)->name);
		free((*tab)->path);
		free(*tab++);
	}
	free(start);
}

char		*join_path(char *s1, char *s2)
{
	unsigned int	i;
	char			*s3;

	i = 0;
	if (!(s3 = (char *)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	while (*s1)
		s3[i++] = *s1++;
	if (i)
		s3[i++] = '/';
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}
