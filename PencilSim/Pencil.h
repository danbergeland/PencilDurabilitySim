#ifndef PENCIL_H
#define PENCIL_H
#include <string>
#include "Paper.h"

class Pencil
{
private:
    double length;
    double durability;
    
    double default_durability;
    double sharpen_length_reduction;
    
public:
    Pencil();
    ~Pencil();
    
    /*
     * Returns durability to original value, reduces length
     */
    void sharpen();
    
    void write(std::string letters, Paper p);

};

#endif // PENCIL_H
