TARGET = zombie

CXX = g++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)

distclean: clean
	rm -f *~

.PHONY: all clean distclean