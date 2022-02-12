run.exe :	./src/main.o \
			./src/game.o \
			./src/utils/printController.o \
			./src/utils/models.o \
			./src/utils/logger/logger.o \
			./src/map.o \
			./src/room.o \
			./src/utils/data_reader/dataReader.o \
			./src/controllers/player.o
	g++ -o run.exe \
	./src/main.o \
	./src/game.o \
	./src/utils/printController.o \
	./src/utils/models.o \
	./src/utils/logger/logger.o \
	./src/utils/data_reader/dataReader.o \
	./src/map.o \
	./src/room.o \
	./src/controllers/player.o

main.o : 	./src/main.cpp \
			./src/game.h \
			./src/utils/models.h \
			./src/utils/logger/logger.h \
			./src/utils/data_reader/dataReader.h \
			./src/utils/printController.h \
			./src/map.h \
			./src/controllers/player.h
	g++ \
	-o ./src/main.o \
	-c ./src/main.cpp 
models.o : 	./src/utils/models.cpp \
			./src/utils/models.h \
			./src/utils/logger/logger.h \
			./src/utils/data_reader/dataReader.h
	g++ \
	-o ./src/utils/models.o \
	-c ./src/utils/models.cpp 
game.o : 	./src/game.cpp \
			./src/game.h \
			./src/utils/printController.h \
			./src/utils/models.h \
			./src/utils/logger/logger.h \
			./utils/data_reader/dataReader.h \
			./src/controllers/player.h
	g++ \
	-o ./src/game.o \
	-c ./src/game.cpp
printController.o : ./src/utils/printController.cpp \
					./src/utils/printController.h \
					./src/utils/logger/logger.h
	g++ \
	-o ./src/utils/printController.o \
	-c ./src/utils/printController.cpp 
dataReader.o : 	./src/utils/data_reader/dataReader.cpp \
				./src/utils/data_reader/dataReader.h \
				./src/utils/logger/logger.h \
				./src/utils/models.h \
				./src/map.h	\
				./src/room.h
	g++ \
	-o ./src/utils/data_reader/dataReader.o \
	-c ./src/utils/data_reader/dataReader.cpp
logger.o : ./src/utils/logger/logger.cpp ./src/utils/logger/logger.h
	g++ \
	-o ./src/utils/logger/logger.o \
	-c ./src/utils/logger/logger.cpp 
map.o : ./src/map.cpp ./src/map.h ./src/room.h
	g++ \
	-o ./src/map.o \
	-c ./src/map.cpp
room.o : ./src/room.cpp ./src/room.h ./src/utils/logger/logger.h
	g++ \
	-o ./src/room.o \
	-c ./src/room.cpp
player.o : ./src/controllers/player.cpp ./src/controllers/player.h
	g++ \
	-o ./src/controllers/player.o \
	-c ./src/controllers/player.cpp
clean : 
	rm \
	run.exe \
	./src/main.o \
	./src/game.o \
	./src/utils/printController.o \
	./src/utils/models.o \
	./src/utils/data_reader/dataReader.o \
	./src/utils/logger/logger.o \
	./logs/*.log \
	./src/map.o \
	./src/room.o \
	./src/controllers/player.o
cleanLogs :
	rm ./logs/*.log

cleanSave :
	rm ./data/players/*.qwq ./data/players/tot.lst ; touch ./data/players/tot.lst
	