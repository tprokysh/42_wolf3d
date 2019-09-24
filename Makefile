# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:      tal <     tal@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 14:40:37 by      tal          #+#    #+#              #
#    Updated: 2019/06/13 14:40:53 by tprokysh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

INCDIR = includes/

SRC = draw.c init.c keys.c move_and_rotation.c map.c main.c ray.c textures.c errors.c utils.c

OBJDIR = objects

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

LIB = libft/libft.a

MLX = -lmlx -L /usr/local/lib

INCDIR = includes

FLAGS = -Wall -Werror -Wextra -O3 -g

FRAMEWORKS = -framework OpenGL -framework AppKit

.PHONY: all clean fclean re cleanlib fcleanlib relib

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	gcc -g3 $(OBJ) $(LIB) $(MLX) $(FRAMEWORKS) -o $(NAME)

$(LIB):
	make -C libft all

$(OBJDIR)/%.o: ./%.c $(INCDIR)/*.h | $(OBJDIR)
	gcc -g3 -o $@ -c $< -I $(INCDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -Rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

cleanlib:
	make -C libft clean

fcleanlib:
	make -C libft fclean

relib:
	make -C libft re

cleanmlx:
	make -C minilibx_macos clean

fcleanmlx:
	make -C minilibx_macos clean

remlx:
	make -C minilibx_macos re

