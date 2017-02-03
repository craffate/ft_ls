/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:38:48 by craffate          #+#    #+#             */
/*   Updated: 2017/02/03 23:14:32 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		maxsizechars(t_file **args, size_t *schars)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 1;
	while (*args)
	{
		schars[0] = ft_strlen(getpwuid((*args)->stat.st_uid)->pw_name) >
			schars[0] ? ft_strlen(getpwuid((*args)->stat.st_uid)->pw_name) :
			schars[0];
		schars[1] = ft_strlen(getgrgid((*args)->stat.st_gid)->gr_name) >
			schars[1] ? ft_strlen(getgrgid((*args)->stat.st_gid)->gr_name) :
			schars[1];
		i = (*args)->stat.st_size > i ? (*args)->stat.st_size : i;
		args++;
	}
	while (i /= 10)
		k++;
	schars[2] = k > schars[2] ? k : schars[2];
}

t_file		**insert(t_file **args, t_file *file)
{
	t_file			**tmp;
	unsigned int	i;

	i = 0;
	while (args && args[i])
		i++;
	if (!(tmp = (t_file **)malloc(sizeof(t_file *) * (i + 2))))
	{
		ft_printf(ERROR);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (args && args[i])
	{
		tmp[i] = args[i];
		i++;
	}
	tmp[i++] = file;
	tmp[i] = 0;
	args ? free(args) : 0;
	return (tmp);
}

t_file		*create_struct(char *name, char *path)
{
	t_file	*arg;

	if (!(arg = (t_file *)malloc(sizeof(t_file))))
		return (0);
	arg->name = ft_strdup(name);
	arg->path = ft_strdup(path);
	lstat(join_path(path, name), &arg->stat);
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
