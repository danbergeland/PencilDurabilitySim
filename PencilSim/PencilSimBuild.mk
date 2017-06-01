#make file for Pencil Sim tests
OutputFile := ./Debug/PencilSim
CC = g++ -Wall -c
OFILES = PaperTest.o PencilTest.o Paper.o Pencil.o
INC = -I./Catch/include/

all: $(OutputFile) 

$(OutputFile) :  $(OFILES)
	$(CC) $(OFILES) -o $(OutputFile) $(INC)

PaperTest.o: PaperTest.cpp Paper.h Paper.cpp
	$(CC) PaperTest.cpp $(INC)

PencilTest.o: PencilTest.cpp Pencil.h Pencil.cpp
	$(CC) PencilTest.cpp $(INC)

Paper.o: Paper.h Paper.cpp
	$(CC) Paper.cpp

Pencil.o: Pencil.h Pencil.cpp
	$(CC) Pencil.cpp

Catch.o: 
    


clean:
	\rm ./Debug/*.o *~ $(OutputFile)
