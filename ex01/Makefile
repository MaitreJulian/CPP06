# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvenkata <jvenkata@student.42belgium.be    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/21 16:52:18 by jvenkata          #+#    #+#              #
#    Updated: 2026/04/03 20:51:07 by jvenkata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer
C = c++
CFLAGS = -Iinclude -Wall -Wextra -Werror -std=c++98 -g
SRC = 	main.cpp Serializer.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(OBJ) -o $@

%.o: %.cpp
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re