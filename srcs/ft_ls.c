/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:09:27 by craffate          #+#    #+#             */
/*   Updated: 2017/01/28 12:27:46 by craffate         ###   ########.fr       */
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

	if (!s1 || !s2)
		return (NULL);
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
	arg->name = name;
	arg->path = path;
	lstat(path, &arg->stat);
	return (arg);
}

static t_file	**parse(DIR *d, char *path)
{
	unsigned int	i;
	struct dirent	*s_dir;
	t_file			**files;
	t_file			**dirs;
	t_file			*file;
	char			*s;

	files = 0;
	dirs = 0;
	i = 0;
	while ((s_dir = readdir(d)))
	{
		s = ft_strdup(s_dir->d_name);
		file = create_struct(s, path);
		if (s_dir->d_type == DT_REG)
			files = insert(files, file);
		else if (s_dir->d_type == DT_DIR && *s_dir->d_name != '.')
			dirs = insert(dirs, file);
	}
	while (files[i])
		ft_printf("%s\n", (files[i++])->name);
	return (dirs);
}

int			ft_ls(t_file *dir, int i)
{
	t_file			**dirs;
	DIR				*d;
	char			*path;

	path = join_path(dir->path, dir->name);
	d = opendir(path);
	if ((dirs = parse(d, path)) && (i & LS_CR))
		while (*dirs)
			ft_ls(*dirs++, i);
	return (0);
}
