# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubugra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 18:20:10 by adubugra          #+#    #+#              #
#    Updated: 2018/05/06 11:46:29 by adubugra         ###   ########.fr        #
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

SRCALL	= $(SRC)
SRCALL	+= push_swap.c
SRCALL	+= checker.c

SRCPS	= $(SRC)
SRCPS	+= push_swap.c

SRCCH	= $(SRC)
SRCCH	+= checker.c

OBJ	= $(addprefix $(OBJDIR),$(SRCALL:.c=.o))
OBJCH	= $(addprefix $(OBJDIR),$(SRCCH:.c=.o))
OBJPS	= $(addprefix $(OBJDIR),$(SRCPS:.c=.o))

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
	$(CC) $(CFLAGS) $(OBJCH) $(FT_LNK) -lm -o $(NAME)
	$(CC) $(CFLAGS) $(OBJPS) $(FT_LNK) -lm -o $(TESTER)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(TESTER)
	make -C $(FT) fclean

re: fclean all
