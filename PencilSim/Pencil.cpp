#include "Pencil.h"
#include <ctype.h>
#include <math.h>

Pencil::Pencil()
{
    durability = 1000;
    default_durability = durability;
    length_cm = 20;
    sharpen_length_reduction = 1.0;
    lower_case_durability_cost=1.0;
    upper_case_durability_cost=2.0;
    eraser_life = 200;
}

Pencil::Pencil(double durability, double length_cm)
{
    this->durability = durability;
    default_durability = durability;
    this->length_cm = length_cm;
    sharpen_length_reduction = 1.0;
    lower_case_durability_cost=1.0;
    upper_case_durability_cost=2.0;
    eraser_life = 200;
}

Pencil::Pencil(double durability, double length_cm, double eraser_life)
{
    this->durability = durability;
    default_durability = durability;
    this->length_cm = length_cm;
    sharpen_length_reduction = 1.0;
    lower_case_durability_cost=1.0;
    upper_case_durability_cost=2.0;
    this->eraser_life = eraser_life;
    
}

Pencil::~Pencil()
{
}

void Pencil::sharpen()
{
    if(get_remaining_sharpens())
    {
        length_cm -= sharpen_length_reduction;
        durability = default_durability;
    }
}

int Pencil::get_remaining_sharpens()
{
    return int(floor(length_cm / sharpen_length_reduction));
}

void Pencil::write(std::string letters, Paper &p)
{
    //reduce durability for each letter
    //if durability is too low, replace the letter with a string
    for(unsigned int i = 0; i<letters.length(); i++)
    {
        char l = letters.at(i);
        if((isupper(l)&&durability<upper_case_durability_cost) || (islower(l)&&durability<lower_case_durability_cost))
            letters.replace(i,1,1,' ');
            
        updateDurability(l);
    }
    p.write(letters);
}

void Pencil::updateDurability(char c)
{
    //only reduce durability for upper and lower case characters
    if(isupper(c)) 
        durability -= upper_case_durability_cost;
    
    if(islower(c)) 
        durability -= lower_case_durability_cost;
    
    if(durability<=0) 
        durability = 0;
}

void Pencil::erase(std::string letters, Paper &p)
{
    //Finds the last position in the matching text
    int start = p.read().rfind(letters)-1;
    unsigned int end = start + letters.length();
    for(unsigned int i=0;i<letters.length();i++)
    {
        if(!isspace(p.read().at(end-i)) && eraser_life>0)
        {
            p.clear_at(end-i,1);
            eraser_life -= 1;
        }
    }
    
}

void Pencil::edit(unsigned int start_position, std::string letters, Paper &p)
{
    for(unsigned int i = 0; i<letters.length(); i++)
    {
        char l = letters.at(i);
        if((isupper(l)&&durability<upper_case_durability_cost) || (islower(l)&&durability<lower_case_durability_cost))
            letters.replace(i,1,1,' ');
            
        updateDurability(l);
    }
    p.write_at(start_position,letters);
    
}