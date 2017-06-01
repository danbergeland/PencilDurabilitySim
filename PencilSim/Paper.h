#ifndef PAPER_H
#define PAPER_H

#include <string>

class Paper
{

public:
    Paper();
    ~Paper();
    /*
     * Add letters to the paper at the end of existing text
     */ 
    void write(std::string letters);
    
    /*
     * Get the current text on the paper
     */
    std::string read();
    
    /*
     * Erase letters by changing them into spaces
     * index is the start point in 
     */
     void clear_at(unsigned int index,unsigned int clear_length);
     /*
      * Write letters into a blank space, and obscure colliding characters with "@"
      * index is the start point, letters will be inserted
      */
     void write_at(unsigned int index, std::string letters);
     
     
private:
    //text on the paper
    std::string text;
    //add_letter inserts letters into spaces and obscures existing characters.
    void add_letter(int index, char letter);
};

#endif // PAPER_H
