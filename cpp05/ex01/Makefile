TARGET = ex01

SRCS =	./src/main.cpp ./src/Bureaucrat.cpp ./src/Form.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

distclean: clean
	rm -f *~

re: fclean all

.PHONY: all clean fclean distclean re