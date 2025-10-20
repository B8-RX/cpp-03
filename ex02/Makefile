SOURCE = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp 

OBJECTS = $(SOURCE:.cpp=.o)

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = repetitive-work 

all: $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CXX) $(FLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

