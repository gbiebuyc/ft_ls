# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 11:35:12 by gbiebuyc          #+#    #+#              #
#    Updated: 2019/01/21 15:58:23 by gbiebuyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC = src/ft_ls.c \
	  src/options.c \
	  src/parse_args.c \
	  src/list_dir.c \
	  src/new_file.c \
	  src/print_file.c \
	  src/print_filename.c \
	  src/print_color.c \
	  src/print_time.c \
	  src/print_mode.c \
	  src/dir_read.c \
	  src/check_sort.c \
	  src/dir_print.c \
	  src/dir_free.c \
	  src/add_file.c \
	  src/add_dir.c \
	  src/add_error.c
OBJ = $(SRC:.c=.o)
FTPRINTF_DIR = src/ft_printf
CFLAGS = -I $(FTPRINTF_DIR) -Wall -Wextra -Werror
LDFLAGS = -L $(FTPRINTF_DIR) -lftprintf
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(FTPRINTF_DIR)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make -C $(FTPRINTF_DIR) clean
	rm -rf $(OBJ)

fclean:
	make -C $(FTPRINTF_DIR) fclean
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all
