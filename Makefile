CC=g++ -g -Wall -std=c++17

SOURCES = main.cpp
OBJS=${SOURCES: .cpp = .o}

target: ${OBJS}
	${CC} -o $@ $^


# Generic rules for compiling a source file to an object file
%.o: %.cpp
	${CC} -c $<
%.o: %.cc
	${CC} -c $<


clean: 
	rm target
	rm -rf *.o
