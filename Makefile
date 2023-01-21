NAME = push_swap
NAME_B = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

ARC = ar -rc

FILES = push_swap.c  utils1.c utils2.c rules_0.c rules_1.c rules_2.c low_sort.c \
		hight_sort.c check_numbers.c
FILES_B = bonus/checker.c bonus/utils_bonus_1.c bonus/rules_bonus_0.c \
		bonus/rules_bonus_1.c bonus/rules_bonus_2.c bonus/check_numbers_bonus.c\
		bonus/checker_utils_1.c

OBJCS = $(FILES:.c=.o)

OBJCS_B = $(FILES_B:.c=.o)

INCLUDES = libft/libft.a
INCLUDES_B = libft/libft.a bonus/get_next_line/get_next_line.a


all : $(NAME)

$(NAME) : $(OBJCS)
	@cd libft && $(MAKE)
	@$(CC) $(OBJCS) $(CFLAGS) -fsanitize=address $(INCLUDES) -o $(NAME)

bonus : $(NAME_B)

$(NAME_B) : $(OBJCS_B)
	@cd libft && $(MAKE)
	@cd bonus/get_next_line && $(MAKE)
	@$(CC) $(OBJCS_B) $(CFLAGS) -fsanitize=address $(INCLUDES_B) -o $(NAME_B)

%.o:%.c
	@$(CC)  $(CFLAGS)  -c $<  -o $@

clean :
	@rm -fr libft/*.o && rm -fr libft/*.a
	@rm -fr bonus/get_next_line/*.o && rm -fr bonus/get_next_line/*.a
	@rm -fr $(OBJCS)
	@rm -fr $(OBJCS_B)

fclean : clean
	@rm -fr $(NAME)
	@rm -fr $(NAME_B)

re :fclean all bonus