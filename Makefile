INCLUDE = inc 
OBJ_DIR = bin
SRC_DIR = src
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

CPP = g++
CPPFLAGS = -c -std=c++14 -I$(INCLUDE)

application: $(OBJ_DIR)/application.o
	$(CPP) $(OBJ_DIR)/*.o -o application.out

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) $^ -o $@


$(OBJ_DIR)/application.o: $(OBJ_FILES)
	$(CPP) $(CPPFLAGS) application.cpp  -o $@



clean:
	rm -f $(OBJ_DIR)/*.o *.out

run:
	./application.out


