# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvenkata <jvenkata@student.42belgium.be    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/21 16:52:18 by jvenkata          #+#    #+#              #
#    Updated: 2026/04/03 20:50:55 by jvenkata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ABaseC
C = c++
CFLAGS = -Iinclude -Wall -Wextra -Werror -std=c++98 -g
SRC = 	main.cpp Base.cpp
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