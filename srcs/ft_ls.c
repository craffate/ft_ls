/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:09:27 by craffate          #+#    #+#             */
/*   Updated: 2017/02/04 01:15:18 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	**parse(DIR *d, char *path, int i, size_t *schars)
{
	struct dirent	*s_dir;
	t_file			**files;
	t_file			**dirs;
	t_file			*file;

	files = 0;
	dirs = 0;
	while ((s_dir = readdir(d)))
	{
		file = create_struct(s_dir->d_name, path);
		if (s_dir->d_type == DT_REG)
			files = insert(files, file);
		else if (s_dir->d_type == DT_DIR && *s_dir->d_name != '.')
			dirs = insert(dirs, file);
	}
	files ? maxsizechars(files, schars) : 0;
	dirs ? maxsizechars(dirs, schars) : 0;
	display(files, i, 1, schars);
	freetab(files);
	return (dirs);
}

int				ft_ls(t_file *dir, int i)
{
	t_file			**dirs;
	DIR				*d;
	char			*path;
	unsigned int	j;
	size_t			*schars; /* 0: uid, 1: gid, 2: size 3: hlinks */

	j = 0;
	schars = arrnew(4);
	path = join_path(dir->path, dir->name);
	d = opendir(path);
	i & LS_CR ? ft_printf("\n\n{green}%s:\n{eoc}", (path)) : 0;
	if ((dirs = parse(d, path, i, schars)) && (i & LS_CR))
	{
		display(dirs, i, 0, schars);
		while (dirs[j])
			ft_ls(dirs[j++], i);
	}
	else if (!(i & LS_CR))
		display(dirs, i, 0, schars);
	closedir(d);
	free(schars);
	return (0);
}
