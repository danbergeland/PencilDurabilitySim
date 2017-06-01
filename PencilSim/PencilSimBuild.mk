#make file for Pencil Sim tests
OutputFile := ./Debug/PencilSim
CC = g++ -Wall
INC = -I./Catch/include/
BUILDDIR = ./Debug/
OFILES = PaperTest.o PencilTest.o Paper.o Pencil.o

all: directory $(OutputFile) 

directory : 
	mkdir -p $(BUILDDIR)

$(OutputFile) : $(OFILES)
	$(CC) $(OFILES) -o $(OutputFile) $(INC)

PaperTest.o: PaperTest.cpp Paper.h Paper.cpp
	$(CC) -c PaperTest.cpp $(INC)

PencilTest.o: PencilTest.cpp Pencil.h Pencil.cpp
	$(CC) -c PencilTest.cpp $(INC)

Paper.o: Paper.h Paper.cpp
	$(CC) -c Paper.cpp

Pencil.o: Pencil.h Pencil.cpp
	$(CC) -c Pencil.cpp

clean:
	\rm ./Debug/*.o *~ $(OutputFile)
