#ifndef PENCIL_H
#define PENCIL_H
#include <string>
#include "Paper.h"

class Pencil
{
private:
    double length_cm;
    double durability;
    
    double eraser_life;
    
    double default_durability;
    double sharpen_length_reduction;
    
    double lower_case_durability_cost;
    double upper_case_durability_cost;
    
    /*
     * Removes durability based on case of the character
     */
    void updateDurability(char c);
    
    /*
    * Returns how many more times it can be sharpened
    */
    
    int get_remaining_sharpens();
    
public:
    Pencil();
    Pencil(double durability, double length_cm);
    Pencil(double durability, double length_cm, double eraser_life);
    ~Pencil();
    
    /*
     * Returns durability to original value, reduces length
     */
    void sharpen();
    

    /*
     * Writes letters to a paper object, reduces durability
     */
    void write(std::string letters, Paper &p);
    
    /*
     * Turns the last instance of "letters" into blank spaces
     */
    
    void erase(std::string letters, Paper &p);
    
    /*
     * 
     */
     void edit(unsigned int start_position, std::string letters, Paper &p);

};

#endif // PENCIL_H
