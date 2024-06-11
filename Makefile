# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 21:03:29 by atorma            #+#    #+#              #
#    Updated: 2024/06/11 21:03:33 by atorma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE_DIR = source
SOURCES = main.c 
OBJECTS = $(addprefix $(SOURCE_DIR)/,$(SOURCES:.c=.o))
LIBDIR = ./libft

target debug: CFLAGS += -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIBDIR)
	$(CC) -o $@ $(CFLAGS) $^ ./libft/libft.a

$(SOURCE_DIR)/%.o: %.c
	$(CC) -I$(SOURCE_DIR) -c $(CFLAGS) $< -o $@

clean:
	$(MAKE) -C $(LIBDIR) $@
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: re

.PHONY: debug all clean fclean re
