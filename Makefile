COMP=g++
OPT=-c -Wall --std=c++11
BIN=colony
OUT=out
SRC=src
HEAD=${SRC}/header
CPP=${SRC}/cpp
OBJ=object
INC= -I${HEAD}

CLASSES= Util Colony Organism

# Replace all CLASSES with ${OBJ}/%.o (e.g. "object_directory/util.o")
_OBJS_= $(patsubst %, ${OBJ}/%.o, ${CLASSES}) ${OBJ}/main.o

${OUT}/${BIN}: ${_OBJS_} | ${OUT}/
	${COMP} ${_OBJS_} -o ${OUT}/${BIN}

${OBJ}/main.o: main.cpp
	${COMP} ${OPT} ${INC} main.cpp -o $@

${OBJ}/%.o: ${CPP}/%.cpp | ${OBJ}/
	${COMP} ${OPT} ${INC} -o $@ $<

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