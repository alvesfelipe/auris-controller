CXX=g++
INC_MIDIMELODY=-I include/
INC_PSTREAMS=-I ../lib/pstreams-0.8.1
PATH_SRC=src/

all: midimelody.bin

midimelody.bin:
	$(CXX) $(INC_MIDIMELODY) $(INC_PSTREAMS) $(PATH_SRC)*.cpp -o midimelody.out

test:
	./midimelody.out
