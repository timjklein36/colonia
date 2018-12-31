COMP=g++
OPT=-c -Wall --std=c++14
BIN=colonia
OUT=out
SRC=src
BOOST=/usr/include/boost
BOOST_OPTS=-DBOOST_LOG_DYN_LINK
HEAD=${SRC}/header
CPP=${SRC}/cpp
OBJ=object
INC=-I${HEAD} -I${BOOST}
LIBS=-L/usr/lib -lboost_log -lpthread -lsfml-window

CLASSES= SimulationRunner BasicSimulationRunner Simulation Colony Organism Insect Ant

# Replace all CLASSES with ${OBJ}/%.o (e.g. "object_directory/util.o")
_OBJS_= $(patsubst %, ${OBJ}/%.o, ${CLASSES}) ${OBJ}/main.o

${OUT}/${BIN}: ${_OBJS_} | ${OUT}/
	${COMP} ${_OBJS_} -o ${OUT}/${BIN} ${LIBS} ${BOOST_OPTS}

${OBJ}/main.o: main.cpp
	${COMP} ${OPT} ${INC} main.cpp -o $@ ${LIBS} ${BOOST_OPTS}

${OBJ}/%.o: ${CPP}/%.cpp | ${OBJ}/
	${COMP} ${OPT} ${INC} -o $@ $< ${LIBS} ${BOOST_OPTS}

.PHONY: clean
clean:
	rm -rf ${OBJ} ${HEAD}/*.gch ${OUT}

${OBJ}/:
	mkdir -p ${OBJ}

${OUT}/:
	mkdir -p ${OUT}

# Reference
# "$@" - the file name of the target
# "$<" - the name of the first prerequisite
# $(patsubst x, y, z) - see https://www.gnu.org/software/make/manual/make.html#Text-Functions