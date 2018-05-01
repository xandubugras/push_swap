# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubugra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 18:20:10 by adubugra          #+#    #+#              #
#    Updated: 2018/05/01 15:26:53 by adubugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= checker
TESTER	= push_swap

# src / obj files
SRC		= elem.c \
		  input_check.c \
		  sorting.c \
		  operations.c \
		  operations2.c \
		  number_stack.c \
		  execute_commands.c \
		  errors.c \
		  helpers.c \
		  helpers2.c \
		  stack.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# directories
SRCDIR	= ./src/
INCDIR	= ./include/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(NAME)

test: obj $(FT_LIB) $(TESTER)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o obj/checker.o -c src/checker.c
	$(CC) $(OBJ) obj/checker.o $(FT_LNK) -lm -o $(NAME)

$(TESTER): $(OBJ)
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o obj/push_swap.o -c src/push_swap.c
	$(CC) $(OBJ) obj/push_swap.o $(FT_LNK) -lm -o $(TESTER)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
