run.exe : ./src/main.o ./src/game.o ./src/utils/printController.o ./src/utils/models.o ./src/utils/logger.o ./src/utils/data_reader/dataReader.o
	g++ -o run.exe \
	./src/main.o \
	./src/game.o \
	./src/utils/printController.o \
	./src/utils/models.o \
	./src/utils/logger.o \
	./src/utils/data_reader/dataReader.o

main.o : ./src/main.cpp ./src/game.h ./src/utils/models.h /src/utils/logger.h ./src/utils/data_reader/dataReader.h
	g++ \
	-o ./src/main.o \
	-c ./src/main.cpp 

game.o : ./src/game.cpp ./src/game.h ./src/utils/printController.h ./src/utils/models.h /src/utils/logger.h ./utils/data_reader/dataReader.h
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
dataReader.o : ./src/utils/data_reader/dataReader.cpp ./src/utils/data_reader/dataReader.h
	g++ \
	-o ./src/utils/data_reader/dataReader.o \
	-c ./src/utils/data_reader/dataReader.cpp
logger.o : ./src/utils/logger.cpp ./src/utils/logger.h
	g++ \
	-o ./src/utils/logger.o \
	-c ./src/utils/logger.cpp 

clean : 
	rm \
	run.exe \
	./src/main.o \
	./src/game.o \
	./src/utils/printController.o \
	./src/utils/models.o \
	./src/utils/data_reader/dataReader.o
