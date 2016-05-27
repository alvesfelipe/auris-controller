CXX=g++
INC_AURIS=-I include/
PATH_SRC=src/
LDFLAGS=-lboost_system -lboost_filesystem
INC_PSTREAMS=-I ../lib/pstreams-0.8.1

all: miditonotes.bin

miditonotes.bin:
	$(CXX) $(INC_AURIS) $(INC_MIDIFILE) $(INC_PSTREAMS) $(PATH_SRC)*.cpp -o miditonotes.out \
	$(LDFLAGS)

test:
	./miditonotes.out