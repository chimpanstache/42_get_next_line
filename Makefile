# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 17:49:46 by ehafidi           #+#    #+#              #
#    Updated: 2019/11/26 14:11:37 by ehafidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line_utils.c get_next_line.c \

SRCS_B = get_next_line_utils_bonus.c get_next_line_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

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

bonus: $(OBJS_B)
	ar rc $(NAME) $(OBJS_B)
	ranlib $(NAME)

$(OBJS_B): $(SRCS_B)
	$(CC) $(CFLAGS) $(SRCS_B)	

clean:
		$(RM) $(OBJS) 
		$(RM) $(OBJS_B) 

fclean: clean
		$(RM) $(NAME) 

re: fclean all		

.PHONY: all clean fclean re bonus
