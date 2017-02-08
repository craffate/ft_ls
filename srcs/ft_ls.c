/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:09:27 by craffate          #+#    #+#             */
/*   Updated: 2017/02/08 17:37:33 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		displayfiles(int i, size_t *schars, t_file **files,
				t_file **hfiles)
{
	i & LS_L ? ft_printf("Total: %lld\n", schars[4]) : 0;
	i & LS_A && hfiles ? display(hfiles, i, schars) : 0;
	files ? display(files, i, schars) : 0;
	files ? freetab(files) : 0;
	hfiles ? freetab(hfiles) : 0;
}

static t_file	**parse(DIR *d, char *path, int i, size_t *schars)
{
	struct dirent	*s_dir;
	t_file			**files;
	t_file			**dirs;
	t_file			**hfiles;
	t_file			*file;

	files = 0;
	dirs = 0;
	hfiles = 0;
	while ((s_dir = readdir(d)))
	{
		file = create_struct(s_dir->d_name, path);
		if (s_dir->d_type == DT_REG && *s_dir->d_name == '.')
			hfiles = insert(hfiles, file);
		else if (s_dir->d_type == DT_DIR && *s_dir->d_name == '.')
			hfiles = insert(hfiles, file);
		else if (s_dir->d_type == DT_REG && *s_dir->d_name != '.')
			files = insert(files, file);
		else if (s_dir->d_type == DT_DIR && *s_dir->d_name != '.')
			dirs = insert(dirs, file);
	}
	i & LS_L ? getsizes(schars, files, dirs, hfiles) : 0;
	gettotals(schars, i, files, hfiles);
	displayfiles(i, schars, files, hfiles);
	closedir(d);
	return (dirs);
}

int				ft_ls(t_file *dir, int i)
{
	t_file			**dirs;
	DIR				*d;
	char			*path;
	unsigned int	j;
	size_t			*schars;

	j = 0;
	schars = arrnew(5);
	path = join_path(dir->path, dir->name);
	d = opendir(path);
	dirs = NULL;
	(i & LS_CR || i & MUL_ARGS) ? ft_printf("{green}%s:{eoc}\n", (path)) : 0;
	!d ? ft_printf(DENIED) : 0;
	if (d && (dirs = parse(d, path, i, schars)) && i & LS_CR && dirs)
	{
		display(dirs, i, schars);
		while (dirs[j])
			ft_ls(dirs[j++], i);
	}
	else if (d && dirs && !(i & LS_CR))
	{
		display(dirs, i, schars);
	}
	free(path);
	dirs ? freetab(dirs) : 0;
	schars ? free(schars) : 0;
	return (0);
}
