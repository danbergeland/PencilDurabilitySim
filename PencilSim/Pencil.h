#ifndef PENCIL_H
#define PENCIL_H
#include <string>
#include "Paper.h"

class Pencil
{
public:
    Pencil();
    Pencil(double durability_, double length_cm_);
    Pencil(double durability_, double length_cm_, double eraser_life_);
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
     * Start writing into a blank space at 'start_position'
     */
     void edit(unsigned int start_position, std::string letters, Paper &p);
     
private:
    double length_cm_;
    double durability_;
    
    double eraser_life_;
    
    double default_durability_;
    double sharpen_length_reduction_;
    
    double lower_case_durability_cost_;
    double upper_case_durability_cost_;
    
    /*
     * Removes durability based on case of the character
     */
    void updateDurability(char c);
    
    /*
    * Returns how many more times it can be sharpened
    */
    
    int get_remaining_sharpens();
};

#endif // PENCIL_H
