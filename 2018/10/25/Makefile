SRC = file.c

OBJ = file.o

BIN = prog

FLAGS = -g -std=c11 --save-temps

CXXFLAGS = -o

CXX = gcc

all: $(SRC)
	$(CXX) $(FLAGS) $(SRC) $(CXXFLAGS) $(BIN)

p1: p1.c
	$(CXX) $(FLAGS) p1.c $(CXXFLAGS) $(BIN)

p2: p2.c
	$(CXX) $(FLAGS) p2.c $(CXXFLAGS) $(BIN)

clean:
	rm -f $(BIN) $(OBJ) *.i *.o *.s *~
	clear
