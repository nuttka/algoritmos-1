CC=g++
CFLAGS=-std=c++14 -Wall

BUILD_DIR=./build
SRC_DIR=./src
INCLUDE_DIR=./include

EXEC=./tp2
TARGET=tp2
TESTS_TARGET=diamante_tests
TMPOUT=tp2.testresult

$(EXEC): ${BUILD_DIR}/${TARGET}

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/main.o: ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

test: $(EXEC)
	@bash run_tests.sh ${BUILD_DIR}/$(EXEC) $(TMPOUT)


clean:
	rm -f ${BUILD_DIR}/*