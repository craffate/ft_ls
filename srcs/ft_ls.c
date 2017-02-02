/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:09:27 by craffate          #+#    #+#             */
/*   Updated: 2017/02/02 16:48:34 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	**parse(DIR *d, char *path, int i)
{
	unsigned int	j;
	struct dirent	*s_dir;
	t_file			**files;
	t_file			**dirs;
	t_file			*file;

	files = 0;
	dirs = 0;
	j = 0;
	while ((s_dir = readdir(d)))
	{
		file = create_struct(s_dir->d_name, path);
		if (s_dir->d_type == DT_REG)
			files = insert(files, file);
		else if (s_dir->d_type == DT_DIR && *s_dir->d_name != '.')
			dirs = insert(dirs, file);
	}
	while (files[j])
		display(files[j++], i);
	freetab(files);
	return (dirs);
}

int				ft_ls(t_file *dir, int i)
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
	i & LS_CR ? ft_printf("\n\n{green}%s:\n{eoc}", (path)) : 0;
	if ((dirs = parse(d, path, i)) && (i & LS_CR))
	{
		while (dirs[k])
			display(dirs[k++], i);
		while (dirs[j])
			ft_ls(dirs[j++], i);
	}
	else if (!(i & LS_CR))
	{
		while (dirs[k])
			display(dirs[k++], i);
	}
	closedir(d);
	return (0);
}
