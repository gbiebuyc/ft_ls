/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:09:31 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/17 13:24:17 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include <stdint.h>
# include <stdbool.h>

# include <libft.h>
# include <ft_printf.h>

typedef enum		e_time_field
{
	LAST_MOFIFICATION,
	LAST_ACCESS,
	LAST_STATUS_CHANGE,
	FILE_CREATION,
}					t_time_field;

typedef struct			s_opt
{
	bool				longformat;
	bool				recursive;
	bool				all;
	bool				a_maj;
	bool				sortreverse;
	bool				sortbytime;
	bool				sortbysize;
	bool				nosort;
	bool				slashafterdir;
	bool				classify;
	bool				colors;
	t_time_field		time_field;
	bool				hide_owner;
	bool				hide_group;
	bool				listdirasfile;
	bool				completetime;
	bool				endofoptions;
	size_t				operand_count;
}						t_opt;

typedef struct			s_fileinfo
{
	char				name[NAME_MAX];
	char				path[PATH_MAX];
	struct stat			stat;
	struct s_fileinfo	*next;
}						t_fileinfo;

typedef struct			s_dirinfo
{
	char				*dir_path;
	t_fileinfo			*files;
	t_fileinfo			*files_tail;
	t_fileinfo			*dirs;
	t_fileinfo			*dirs_tail;
	t_fileinfo			*errors;
	int					lnk_col_width;
	int					owner_col_width;
	int					group_col_width;
	int					bytes_col_width;
	intmax_t			total_block_count;
}						t_dirinfo;

t_opt					*get_opt(void);
void					toggle_option(char c);
void					parse_args(char **av, t_dirinfo *oper);
bool					new_file(t_fileinfo **new, char *path, char *name);
void					lst_add(t_fileinfo *new,
		t_fileinfo **head, t_fileinfo **tail);
void					lst_free(t_fileinfo **lst, t_fileinfo **tail);
void					print_file(t_fileinfo *f, t_dirinfo *d);
void					print_filename(t_fileinfo *f);
void					print_color(mode_t mode);
void					print_xattr_acl(char *file_path);
void					print_time(time_t t);
void					print_complete_time(time_t t);
void					print_permissions(mode_t mode);
void					print_filetype(mode_t mode);
void					list_dir(char *dir_path);
bool					dir_read(t_dirinfo *d);
void					dir_error(char *path);
void					dir_sort(t_dirinfo *d);
void					dir_print(t_dirinfo *d,
		t_fileinfo *err, t_fileinfo *file, t_fileinfo *dir);
void					dir_free(t_dirinfo *d);
void					add_file(t_fileinfo *new, t_dirinfo *d);
void					add_dir(t_fileinfo *new, t_dirinfo *d);
void					add_error(t_fileinfo **error_lst, t_fileinfo *new);

#endif
