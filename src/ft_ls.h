/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:09:31 by gbiebuyc          #+#    #+#             */
/*   Updated: 2019/01/21 01:48:33 by gbiebuyc         ###   ########.fr       */
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
	bool				no_operands_given;
	bool				need_stat;
	bool				print_block_count;
}						t_opt;

typedef struct			s_file
{
	char				name[NAME_MAX];
	char				path[PATH_MAX];
	struct stat			stat;
	struct s_file		*next;
}						t_file;

typedef struct			s_dir
{
	t_file				info;
	t_file				*files;
	t_file				*files_tail;
	struct s_dir		*dirs;
	struct s_dir		*dirs_tail;
	t_file				*errors;
	int					lnk_col_width;
	int					owner_col_width;
	int					group_col_width;
	int					bytes_col_width;
	intmax_t			total_block_count;
	struct s_dir		*next;
}						t_dir;

t_opt					*get_opt(void);
void					toggle_option(char c);
void					parse_args(char **av, t_dir *oper);
bool					new_file(t_file **new, char *path, char *name);
void					print_file(t_file *f, t_dir *d);
void					print_filename(t_file *f);
void					print_color(mode_t mode);
void					print_xattr_acl(char *file_path);
void					print_time(time_t t);
void					print_complete_time(time_t t);
void					print_permissions(mode_t mode);
void					print_filetype(mode_t mode);
void					list_dir(t_dir *d);
bool					dir_read(t_dir *d);
void					dir_error(char *path);
void					sort_lst(t_file **lst);
void					dir_print(t_dir *d,
		t_file *err, t_file *file, t_dir *dir);
void					dir_free(t_dir *d);
void					add_file(t_file *new, t_dir *d);
void					add_dir(t_file *info, t_dir *d);
void					add_error(t_file *new, t_file **error_lst);
bool					check_sort(t_file *f1, t_file *f2);

#endif
