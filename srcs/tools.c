/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:38:48 by craffate          #+#    #+#             */
/*   Updated: 2017/02/13 14:41:16 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		maxsizechars(t_file **args, size_t *schars)
{
	int		i;
	int		j;
	size_t	k;

	i = 0;
	j = 0;
	k = 1;
	while (*args && (*args)->stat.st_uid && (*args)->stat.st_gid)
	{
		schars[0] = ft_strlen(getpwuid((*args)->stat.st_uid)->pw_name) >
		*schars ? ft_strlen(getpwuid((*args)->stat.st_uid)->pw_name) : *schars;
		schars[1] = ft_strlen(getgrgid((*args)->stat.st_gid)->gr_name) >
		schars[1] ? ft_strlen(getgrgid((*args)->stat.st_gid)->gr_name) :
		schars[1];
		i = (*args)->stat.st_size > i ? (*args)->stat.st_size : i;
		j = (*args)->stat.st_nlink > j ? (*args)->stat.st_nlink : j;
		args++;
	}
	while (i /= 10)
		k++;
	schars[2] = k > schars[2] ? k : schars[2];
	k = 1;
	while (j /= 10)
		k++;
	schars[3] = k > schars[3] ? k : schars[3];
}

t_file		**insert(t_file **args, t_file *file, int fl)
{
	t_file			**tmp;
	unsigned int	i;
	unsigned int	l;

	if (!args && (args = malloc(sizeof(t_file **))))
		*args = 0;
	l = 0;
	while (args[l])
		l++;
	if (!(tmp = malloc(sizeof(t_file *) * (l + 2))))
		exit(EXIT_FAILURE);
	tmp[l + 1] = 0;
	i = 0;
	while (i <= l)
	{
		if (file && (!args[i] || !cmp(file, args[i], fl)) && (tmp[i] = file))
			file = 0;
		else
			tmp[i] = args[i - (!file)];
		i++;
	}
	free(args);
	return (tmp);
}

t_file		*create_struct(char *name, char *path)
{
	t_file	*arg;
	char	*tmp;

	if (!(arg = malloc(sizeof(t_file))))
		exit(EXIT_FAILURE);
	arg->name = ft_strdup(name);
	arg->path = ft_strdup(path);
	if (lstat((tmp = join_path(path, name)), &arg->stat))
	{
		free(arg);
		return (0);
	}
	free(tmp);
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
	if (!(s3 = malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 2))))
		exit(EXIT_FAILURE);
	while (*s1)
		s3[i++] = *s1++;
	if (i && s3[i - 1] != '/')
		s3[i++] = '/';
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}
