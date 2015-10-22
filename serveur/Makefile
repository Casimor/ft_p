# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/16 17:20:54 by bchevali          #+#    #+#              #
#    Updated: 2015/10/22 14:40:13 by bchevali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=		serveur

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
							server_setup.c		\
							run_server.c		\
							handle_client.c		\
							handle_message.c	\
							handle_commands.c	\
							ls_command.c		\
							pwd_command.c		\
							cd_command.c		\
							get_command.c		\
							put_command.c		\
							error_command.c		\
							cd_command_opt.c	\
							home_opt.c			\
							stdin_commands.c

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
