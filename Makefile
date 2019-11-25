# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 17:49:46 by ehafidi           #+#    #+#              #
#    Updated: 2019/11/21 16:22:46 by ehafidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line_utils.c get_next_line.c \

OBJS = $(SRCS:.c=.o)

NAME = get_next_line.a

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)	

clean:
		$(RM) $(OBJS) 
		$(RM) $(OBJS_B) 

fclean: clean
		$(RM) $(NAME) 

re: fclean all		

.PHONY: all clean fclean re bonus
