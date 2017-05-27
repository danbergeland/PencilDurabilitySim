#ifndef PAPER_H
#define PAPER_H

#include <string>

class Paper
{
private:
    std::string text;
public:
    Paper();
    ~Paper();
    /*
     * Add letters to the paper at the end of existing text
     */ 
    int write(std::string letters);
    
    /*
     * Get the current text on the paper
     */
    std::string read();
    
    /*
     * Erase letters by changing them into spaces
     * index is the start point in 
     */
     void clear_at(int index,int clear_length);
     /*
      * Write letters into a blank space, and obscure colliding characters with "@"
      * index is the start point, letters will be inserted
      */
     void write_at(int index, std::string letters);
};

#endif // PAPER_H