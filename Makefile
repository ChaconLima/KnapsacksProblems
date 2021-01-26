SRC_DIR=src/
CPP_FILES=${SRC_DIR}*.cpp
INCLUDE_MYSQL = /usr/include/mysql/
INCLUDE = include
INCLUDE_STRUCT= include/struct
INCLUDE_CLASS =	include/class


BINARY=bin/engine_0_1.exe

all: modelo

run:run_modelo

modelo:
	g++ -std=c++17 -pthread ${CPP_FILES} -I${INCLUDE} -I${INCLUDE_STRUCT} -I${INCLUDE_CLASS} -I${INCLUDE_MYSQL} -o ${BINARY} -lpthread -lm -lmysqlclient -ljsoncpp

run_modelo: modelo
	modelo
clean: 
	rm ${SRC_DIR}*.o