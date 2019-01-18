# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 11:35:12 by gbiebuyc          #+#    #+#              #
#    Updated: 2019/01/17 13:16:08 by gbiebuyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC = src/ft_ls.c \
	  src/options.c \
	  src/parse_args.c \
	  src/list_dir.c \
	  src/lst.c \
	  src/new_file.c \
	  src/print_file.c \
	  src/print_filename.c \
	  src/print_color.c \
	  src/print_xattr_acl.c \
	  src/print_time.c \
	  src/print_permissions.c \
	  src/print_filetype.c \
	  src/dir_read.c \
	  src/dir_sort.c \
	  src/dir_error.c \
	  src/dir_print.c \
	  src/dir_free.c \
	  src/add_file.c \
	  src/add_dir.c \
	  src/add_error.c
OBJ = $(SRC:.c=.o)
CFLAGS = -I libft -I ft_printf -Wall -Wextra -Werror -g
LDFLAGS = -L ft_printf -lftprintf
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C ft_printf
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make -C ft_printf clean
	rm -rf $(OBJ)

fclean:
	make -C ft_printf fclean
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all
