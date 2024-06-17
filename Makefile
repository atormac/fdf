# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 21:03:29 by atorma            #+#    #+#              #
#    Updated: 2024/06/17 19:06:05 by atorma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS := -Wall -Wextra -Werror 
LDFLAGS = -ldl -lglfw -pthread -lm
LIBDIR = ./libft
MLXDIR = ./MLX42
LIBS = $(LIBDIR)/libft.a $(MLXDIR)/build/libmlx42.a
INCLUDE_DIR = ./include
SOURCE_DIR = source
SOURCES = main.c fdf.c matrix.c map.c draw.c color.c
OBJECTS = $(addprefix $(SOURCE_DIR)/,$(SOURCES:.c=.o))

target debug: CFLAGS += -fsanitize=address -static-libasan -g
target debug: CDEBUG = -DDEBUG=1

all: $(NAME)

export CFLAGS

$(NAME): $(OBJECTS)
	cmake $(MLXDIR) -B $(MLXDIR)/build $(CDEBUG)
	cmake --build $(MLXDIR)/build -j4
	$(MAKE) -C $(LIBDIR)
	$(CC) -o $@ $(CFLAGS) $^ $(LIBS) $(LDFLAGS)

$(SOURCE_DIR)/%.o: %.c
	$(CC) -I$(INCLUDE_DIR) -c $(CFLAGS) $(LIBS) $< -o $@

clean:
	$(MAKE) -C $(LIBDIR) $@
	rm -rf $(MLXDIR)/build
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: re

.PHONY: debug all clean fclean re
