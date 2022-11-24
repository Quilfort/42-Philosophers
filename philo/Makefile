NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror -g -pthread
INC = -I ./Includes
SRC =	./Src/main.c \
		./Src/parsing.c \
		./Src/philo_utils.c \
		./Src/philosopher.c \
		./Src/pthread_protect.c \
		./Src/use_threads.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(INC) $(FLAGS) -c $< -o $@

clean:
	@echo "Cleaning up .o files"
	@rm -f $(OBJ)

fclean: clean
	@echo "Delete ./philo"
	@rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re