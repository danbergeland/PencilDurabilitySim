# PencilDurabilitySim

Simulates using a pencil on paper.

## Requirements:

https://github.com/PillarTechnology/kata-pencil-durability


## Instructions:

Clone the repository.  To run the tests (already compiled), use "cd debug && ./PencilSim".  
Remember to chmod PencilSim such that it's allowed to run as an executable.

Catch also provides some command line arguments.  To see the list of tests use the -l flag "./PencilSim -l".  
It also has a -t tag flag that shows how many test cases for the different tags.  This project has tags for pencil and paper.

To compile and build:  

Open a terminal for the root directory of the repository. 
I provided a shell script that contains the necessary make command "./build.sh"
Run build.sh, or make -f Makefile

## Dependencies:

I built this in Ubuntu 16.04

g++ compiler 5.4.0

Catch (included in the repository) https://github.com/philsquared/Catch

make 4.1

## Summary:

I chose to use C++, with the low overhead Catch test framework (included in the repository).  
While I'm familiar with the concept of unit testing and TDD, it's not something I've done regularly on prior work; the choice of Catch was somewhat arbitrary since I don't have a preferred framework.

This project used test driven development (TDD) to develop classes to represent a pencil writing on paper.  
The pencil has some realistic parameters, such as length, durability and eraser life, which are depleted as the pencil is used for writing or erasing on the paper.

For this development process, I determined the paper object was a good place to start; after all, what good is a pencil with nothing to write on?
I built test cases for the paper that went from simple (write to the page, read what's on the page), to more complex.
After the paper functionality was finished, I begin making tests for the pencil.  

For the sake of modularity, I put the Pencil tests and Paper tests in separate files, and named them PencilTest and PaperTest.

For developing the pencil features, I started with the simplest features of writing to the paper and erasing. 
I then added durability and going dull, then sharpening, then running out of length, and finally, eraser life and partial word deletion and editing.

