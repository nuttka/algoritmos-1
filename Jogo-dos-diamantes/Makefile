CC=g++
CFLAGS=-std=c++14 -Wall

BUILD_DIR=./build
SRC_DIR=./src
INCLUDE_DIR=./include

EXEC=./tp2
TARGET=tp2
TESTS_TARGET=pulo_tests
TMPOUT=tp2.testresult

$(EXEC): ${BUILD_DIR}/${TARGET}

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/Board.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Player.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/Player.o: ${INCLUDE_DIR}/Player/Player.hpp ${SRC_DIR}/Player/Player.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Player/ -c ${SRC_DIR}/Player/Player.cpp -o ${BUILD_DIR}/Player.o

${BUILD_DIR}/Board.o: ${INCLUDE_DIR}/Board/Board.hpp ${SRC_DIR}/Board/Board.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Board/ -c ${SRC_DIR}/Board/Board.cpp -o ${BUILD_DIR}/Board.o

${BUILD_DIR}/Game.o: ${INCLUDE_DIR}/Game/Game.hpp ${SRC_DIR}/Game/Game.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Game/ -c ${SRC_DIR}/Game/Game.cpp -o ${BUILD_DIR}/Game.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Board/Board.hpp ${INCLUDE_DIR}/Game/Game.hpp ${INCLUDE_DIR}/Player/Player.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Board/ -c ${INCLUDE_DIR}/Game/ -c ${INCLUDE_DIR}/Player/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

test: $(EXEC)
	@bash run_tests.sh ${BUILD_DIR}/$(EXEC) $(TMPOUT)


clean:
	rm -f ${BUILD_DIR}/*