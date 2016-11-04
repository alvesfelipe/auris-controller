CXX=g++
INC_AURIS_CONT=-I include/
INC_AURIS_CORE=-I ../auris-core/auris-stream/include/ -I ../auris-core/midi-melody-generator/include/
PATH_SRC=src/*.cpp
SRC_CORE=../auris-core/auris-stream/src/*.cpp ../auris-core/midi-melody-generator/src/*.cpp
LDFLAGS=-lboost_system -lboost_filesystem -std=c++11 -lpython2.7
INC_PSTREAMS=-I ../auris-core/lib/pstreams-0.8.1

AURIS_AUX:=$(subst music_for_deaf/,,$(dir $(CURDIR)))
export AURIS_HOME_PATH?=$(AURIS_AUX)music_for_deaf/
export AURIS_FILES?=$(AURIS_AUX)music_for_deaf_files

all: auris_controller.bin

auris_controller.bin:
	@$(CXX) $(INC_AURIS_CONT) $(INC_AURIS_CORE) $(INC_PSTREAMS) $(PATH_SRC) $(SRC_CORE) -o auris_controller.out $(LDFLAGS)

install:
	@sed "/AURIS_HOME_PATH/d" -i $(HOME)/.bashrc
	@echo "export AURIS_HOME_PATH='$(AURIS_HOME_PATH)'" >> $(HOME)/.bashrc
	@sed "/AURIS_FILES/d" -i $(HOME)/.bashrc
	@echo "export AURIS_FILES='$(AURIS_FILES)'" >> $(HOME)/.bashrc
	@sudo -s source $(HOME)/.bashrc #make the ambient variables available

run:
	@./auris_controller.out