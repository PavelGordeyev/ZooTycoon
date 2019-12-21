CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

OBJS = main.o Menu.o Animal.o Penguin.o Tiger.o Turtle.o Zoo.o checkInput.o

SRCS = main.cpp Menu.cpp Animal.cpp Penguin.cpp Tiger.cpp Turtle.cpp Zoo.cpp checkInput.cpp 

HEADERS = 

project2: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o project2

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	-rm ${OBJS} project2