NAME = Scalar

C_BLUE    = \033[0;34m
C_YELLOW  = \033[33m
C_RESET   = \033[0m

CC = c++

CFLAGS = -Wall -Wextra -Werror #-std=c++98 

RM = rm -rf

HEADER = ScalarConverter.hpp

SRCS = main.cpp ScalarConverter.cpp

OBJS = ${SRCS:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(C_BLUE)    - Compilation finished!....$(C_RESET)"

%.o:%.cpp $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(C_YELLOW)    - Removed Object File finished!....$(C_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(C_YELLOW)    - Removed finished!....$(C_RESET)"

re: fclean all

.PHONY: all fclean clean re
