TARGET = btc

SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98
CCXX = c++

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CCXX) $(FLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re