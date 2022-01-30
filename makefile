run.exe : ./src/main.o \
		  ./src/game.o
	g++ -o run.exe \
		./src/main.o \
		./src/game.o

main.o : ./src/main.cpp \
		 ./src/game.h \
		 ./src/utils/printController.h
	g++ -c ./src/main.cpp \
		   ./src/game.h \
		   ./src/utils/printController.h

game.o : ./src/game.h \
		 ./src/game.cpp \
	     ./src/utils/printController.h
	g++ -c ./src/game.h \
		   ./src/game.cpp \
		   ./src/utils/printController.h
printController.o : ./src/utils/printController.h \
					./src/utils/printController.cpp
	g++ -c ./src/utils/printController.cpp \
		   ./src/utils/printController.h


clean : 
	rm run.exe \
	   ./src/main.o \
	   ./src/game.o
