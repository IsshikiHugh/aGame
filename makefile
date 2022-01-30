run.exe : ./src/main.o ./src/game.o ./src/utils/printController.o ./src/utils/models.o
	g++ -o run.exe ./src/main.o ./src/game.o ./src/utils/printController.o ./src/utils/models.o

main.o : ./src/main.cpp ./src/game.h ./src/utils/models.h
	g++ \
	-c ./src/main.cpp \
	-o ./src/main.o

game.o : ./src/game.cpp ./src/game.h ./src/utils/printController.h ./src/utils/models.h
	g++ \
	-o ./src/game.o \
	-c ./src/game.cpp
printController.o : ./src/utils/printController.cpp ./src/utils/printController.h
	g++ \
	-o ./src/utils/printController.o \
	-c ./src/utils/printController.cpp 
models.o : ./src/utils/models.cpp ./src/utils/models.h
	g++ \
	-o ./src/utils/models.o \
	-c ./src/utils/models.cpp

clean : 
	rm \
	run.exe \
	./src/main.o \
	./src/game.o \
	./src/utils/printController.o \
	./src/utils/models.o
