INCLUDE=include/
SRC_DIR=src/
BUILD=build/

INCLUDE_STRUCT= struct/
INCLUDE_MYSQL = /usr/include/mysql/
CPP_FILES=main.cpp
LDLIBS = -lmysqlclient -ljsoncpp -lm

COMPILATION_FILE_O = ${BUILD}libGreedyHeuristic.o
COMPILATION_FILE_A = ${BUILD}libGreedyHeuristic.a
COMPILATION_FILE_SO = ${BUILD}libGreedyHeuristic.so


all: build_object builder_static builder_dynamic clean

build_object:

	gcc -fPIC -c -I${INCLUDE_STRUCT} -I${INCLUDE} -I${INCLUDE_MYSQL} ${CPP_FILES} -o ${COMPILATION_FILE_O} ${LDLIBS}

builder_static:
	
	ar rcs ${COMPILATION_FILE_A} ${COMPILATION_FILE_O} 
	nm -s --defined-only ${COMPILATION_FILE_A}

builder_dynamic:

	gcc -shared -o ${COMPILATION_FILE_SO} ${COMPILATION_FILE_O} ${LDLIBS}

clean:
	rm ${BUILD}*.o