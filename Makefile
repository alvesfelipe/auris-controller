CXX=g++
INC_AURIS_CONT=-I include/
INC_AURIS_CORE=-I ../auris-core/auris-stream/include/ -I ../auris-core/midi-melody-generator/include/
PATH_SRC=src/*.cpp
SRC_CORE=../auris-core/auris-stream/src/*.cpp ../auris-core/midi-melody-generator/src/*.cpp
LDFLAGS=-lboost_system -lboost_filesystem -std=c++11 -lwiringPi
INC_PSTREAMS=-I ../auris-core/lib/pstreams-0.8.1

all: auris_controller.bin

auris_controller.bin:
	@$(CXX) $(INC_AURIS_CONT) $(INC_AURIS_CORE) $(INC_PSTREAMS) $(PATH_SRC) $(SRC_CORE) -o auris_controller.out $(LDFLAGS)

run:
	@./auris_controller.out