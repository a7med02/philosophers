NAME = philosopher
SRC = main.c init.c routine.c touls.c
FLGS = -Wall -Wextra -Werror -pthread -g
CC = cc 
RM = rm -rf
OBJ = $(SRC:%.c=%.o)

all : $(NAME)
%.o : %.c philo.h 
	$(CC) $(FLGS)  -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(FLGS) $(OBJ)  -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all