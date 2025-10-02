TARGET = GBU

CXX = g++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = Account.cpp tests.cpp

OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

distclean: clean
	rm -f *~

.PHONY: all clean distclean