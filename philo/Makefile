NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror 
INC = -I ./Includes
SRC = ./Src/main.c 
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

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