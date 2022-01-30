run.exe : ./src/main.o ./src/game.o ./src/utils/printController.o
	g++ \
	./src/main.o ./src/game.o ./src/utils/printController.o \
	-o run.exe

main.o : ./src/main.cpp ./src/game.h ./src/utils/printController.h
	g++ \
	-c ./src/main.cpp \
	   ./src/game.h \
	   ./src/utils/printController.h \
	-o ./src/main.o

game.o : ./src/game.cpp ./src/game.h ./src/utils/printController.h ./src/utils/models.h
	g++ \
	-c ./src/game.cpp \
	   ./src/game.h \
	   ./src/utils/printController.h \
	   ./src/utils/models.h \
	-o ./src/game.o 
printController.o : ./src/utils/printController.cpp ./src/utils/printController.h
	g++ \
	-c ./src/utils/printController.cpp \
	   ./src/utils/printController.h \
	-o ./src/utils/printController.o
models.o : ./src/utils/models.cpp ./src/utils/models.h
	g++ \
	-c ./src/utils/models.cpp \
	   ./src/utils/models.h \
	-o ./src/utils/models.o

clean : 
	rm \
	run.exe \
	./src/main.o \
	./src/game.o \
	./src/utils/printController.o
