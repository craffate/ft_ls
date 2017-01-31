/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:09:27 by craffate          #+#    #+#             */
/*   Updated: 2017/01/31 23:26:45 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
static int	ft_ls_rights(t_stat stat)
{
	ft_printf(stat.st_mode & S_IFDIR ? "d" : "-");
	ft_printf(stat.st_mode & S_IRUSR ? "r" : "-");
	ft_printf(stat.st_mode & S_IWUSR ? "w" : "-");
	ft_printf(stat.st_mode & S_IXUSR ? "x" : "-");
	ft_printf((stat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((stat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((stat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((stat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((stat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((stat.st_mode & S_IXOTH) ? "x" : "-");
	return (0);
}
*/

static char		*join_path(char *s1, char *s2)
{
	unsigned int	i;
	char			*s3;

	i = 0;
	if (!(s3 = (char *)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	while (*s1)
		s3[i++] = *s1++;
	s3[i++] = '/';
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}

t_file	*create_struct(char *name, char *path)
{
	t_file	*arg;

	if (!(arg = (t_file *)malloc(sizeof(t_file))))
		return (0);
	arg->name = ft_strdup(name);
	arg->path = ft_strdup(path);
	lstat(path, &arg->stat);
	return (arg);
}

static void		freetab(t_file **tab)
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

static t_file	**parse(DIR *d, char *path)
{
	unsigned int	i;
	struct dirent	*s_dir;
	t_file			**files;
	t_file			**dirs;
	t_file			*file;

	files = 0;
	dirs = 0;
	i = 0;
	while ((s_dir = readdir(d)))
	{
		file = create_struct(s_dir->d_name, path);
		if (s_dir->d_type == DT_REG)
			files = insert(files, file);
		else if (s_dir->d_type == DT_DIR && *s_dir->d_name != '.')
			dirs = insert(dirs, file);
	}
	while (files[i])
		ft_printf("%s\t", (files[i++])->name);
	i = 0;
	freetab(files);
	return (dirs);
}

int			ft_ls(t_file *dir, int i)
{
	t_file			**dirs;
	DIR				*d;
	char			*path;
	unsigned int	j;
	unsigned int	k;

	j = 0;
	k = 0;
	path = join_path(dir->path, dir->name);
	d = opendir(path);
	i & LS_CR ? ft_printf("\n{green}%s:\n{eoc}", (path + 2)) : 0;
	if ((dirs = parse(d, path)) && (i & LS_CR))
	{
		while (dirs[j])
			ft_ls(dirs[j++], i);
		while (dirs[k])
			ft_printf("%s\t", (dirs[k++])->name);
	}
	else if (!(i & LS_CR))
	{
		while (dirs[k])
			ft_printf("%s\t", (dirs[k++])->name);
	}
	closedir(d);
	return (0);
}
