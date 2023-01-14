NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

ARC = ar -rc

FILES = push_swap.c  utils1.c utils2.c rules_2.c rules3.c sort_3.c sort_5.c

OBJCS = $(FILES:.c=.o)

INCLUDES = libft/libft.a
all : $(NAME)

$(NAME) : $(OBJCS)
	@cd libft && $(MAKE)
	@$(CC) $(OBJCS) $(CFLAGS) $(INCLUDES) -o $(NAME)

%.o:%.c
	@$(CC)  $(CFLAGS)  -c $<  -o $@

clean :
	@rm -fr libft/*.o
	@rm -fr $(OBJCS)

fclean : clean
	@rm -fr $(NAME)

re :fclean all