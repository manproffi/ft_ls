# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/21 12:02:20 by sprotsen          #+#    #+#              #
#    Updated: 2017/05/21 12:02:22 by sprotsen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIB_NAME = ft

LIB_NAME2 = ftprintf

LIB_DIR = ./libft

LIB_DIR2 = ./ft_printf

LIB_ALL = -L$(LIB_DIR) -l$(LIB_NAME) -L$(LIB_DIR2) -l$(LIB_NAME2)

SRC = main.c read_window_parameters.c parsing_command.c \
		reading.c delete.c print_column.c work_with_parameters.c sort.c \
		recursion.c get_filetype.c choise_print_function.c \
		flag_1.c \
		flag_i.c \
		flag_l.c \
		get_extended_atribute.c \
		print_part_l_g.c \
		check_time.c \
		sort_input_param.c \
		work_with_file.c \
		work_with_link.c \
		work_with_other.c
 
OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): lib $(OBJ) head_ls.h
	gcc $(FLAG) $(OBJ) -o $(NAME) $(LIB_ALL)

%.o: %.c head_ls.h
	gcc $(FLAG) -c -o $@ $<

lib:
	make -C libft
	make -C ft_printf

clean:
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf
	rm -f $(OBJ)

fclean:	clean
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf
	rm -f $(NAME)

re: fclean lib all	