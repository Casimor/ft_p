# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoirier <kpoirier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 15:53:24 by kpoirier          #+#    #+#              #
#    Updated: 2015/09/30 16:07:30 by kpoirier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_DIR	=	serveur
SERVER_NAME	=	serveur

CLIENT_DIR	=	client
CLIENT_NAME	=	client

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_DIR)/$(SERVER_NAME)
$(CLIENT_NAME): $(CLIENT_DIR)/$(CLIENT_NAME)

$(SERVER_DIR)/$(SERVER_NAME):
	make -C $(SERVER_DIR)

$(CLIENT_DIR)/$(CLIENT_NAME):
	make -C $(CLIENT_DIR)

clean:
	make -C $(SERVER_DIR) $@
	make -C $(CLIENT_DIR) $@

fclean:
	make -C $(SERVER_DIR) $@
	make -C $(CLIENT_DIR) $@

re: fclean all
