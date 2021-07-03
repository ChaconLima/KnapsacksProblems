INCLUDE=ProblemVariation/EntireBackpack/libraries/GreedyHeuristic/include
INCLUDE_STRUCT=ProblemVariation/EntireBackpack/libraries/GreedyHeuristic/struct
SRC_DIR=src/
CPP_FILES=${SRC_DIR}main.cpp

BINARY=bin/engine_0_1.exe

BUIDER = ProblemVariation/EntireBackpack/libraries/GreedyHeuristic

LIB_TWO_OPT = ${BUIDER}/build

all: modelo
	
modelo:

	
	g++ -std=c++17 -Wall ${CPP_FILES} -I${INCLUDE} -I${INCLUDE_STRUCT} -lstdc++ -L./${LIB_TWO_OPT} -lGreedyHeuristic -o ${BINARY} 

const:
	$(MAKE) -C ${BUIDER} all