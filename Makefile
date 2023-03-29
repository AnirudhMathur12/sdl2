APP_NAME = game

SRC_FILES = main.cpp renderwindow.cpp

INC = -I include
LIB = -L lib -l SDL2-2.0.0 -lSDL2_image

CC = g++

#game:
#	g++ main.cpp renderwindow.cpp -o game -I include -L lib -l SDL2-2.0.0 -lSDL2_image 

game:
	$(CC) $(SRC_FILES) -o $(APP_NAME) $(INC) $(LIB)
	./$(APP_NAME)

clean:
	rm game

