TARGET = ex01
src = src/main.cpp src/Span.cpp
obj = $(src:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(TARGET)

$(TARGET): $(obj)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re