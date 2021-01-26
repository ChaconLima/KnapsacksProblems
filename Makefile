SRC_DIR=src/
CPP_FILES=${SRC_DIR}*.cpp
INCLUDE_MYSQL = /usr/include/mysql/
INCLUDE = include


BINARY=bin/engine_0_1.exe

all: modelo

run:run_modelo

modelo:
	g++ -std=c++17 -pthread ${CPP_FILES} -I${INCLUDE} -o ${BINARY} -lpthread -lm -lmysqlclient

run_modelo: modelo
	modelo
clean: 
	rm ${SRC_DIR}*.o