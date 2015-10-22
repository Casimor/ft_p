# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/25 18:16:27 by bchevali          #+#    #+#              #
#    Updated: 2015/10/19 13:34:39 by bchevali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=		client

SRC_DIR				=		srcs
INCLUDE_DIR			=		includes
OBJ_DIR				=		objs

LIBFT				=		ft
LIBFT_DIR			=		libft
LIBFT_NAME			=		$(LIBFT_DIR)/libft.a
LIBFT_INCLUDE_DIR	=		$(LIBFT_DIR)

COMPILER			=		gcc
CFLAGS				=		-g3 -O3 -Wall -Wextra -Werror -c \
							-I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR)
LFLAGS				=		-L$(LIBFT_DIR) -l$(LIBFT) -o

SRC					=		main.c				\
							run_client.c		\
							prompt.c			\
							client_setup.c 		\
							parse.c				\
							user.c				\
							commands.c			\
							get_command.c		\
							put_command.c		\
							cd_command.c		\
							pwd_commands.c		\
							ls_commands.c		\
							error.c				\
							get_pwd.c			\
							send_wrapper.c		\
							recv_wrapper.c		\
							get_cmd_opt.c		\
							lcd_command_opt.c	\
							home_opt.c

OBJ					=		$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(LIBFT_NAME)
	$(MAKE) $(NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(COMPILER) $(LFLAGS) $@ $^

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)
	rm -df $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
