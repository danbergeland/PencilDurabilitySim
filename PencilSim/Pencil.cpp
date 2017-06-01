#include "Pencil.h"
#include <ctype.h>
#include <math.h>

Pencil::Pencil()
{
    durability_ = 1000;
    default_durability_ = durability_;
    length_cm_ = 20;
    sharpen_length_reduction_ = 1.0;
    lower_case_durability_cost_=1.0;
    upper_case_durability_cost_=2.0;
    eraser_life_ = 200;
}

Pencil::Pencil(double durability, double length_cm)
{
    durability_ = durability;
    default_durability_ = durability_;
    length_cm_ = length_cm;
    sharpen_length_reduction_ = 1.0;
    lower_case_durability_cost_=1.0;
    upper_case_durability_cost_=2.0;
    eraser_life_ = 200;
}

Pencil::Pencil(double durability, double length_cm, double eraser_life)
{
    durability_ = durability_;
    default_durability_ = durability_;
    length_cm_ = length_cm;
    sharpen_length_reduction_ = 1.0;
    lower_case_durability_cost_=1.0;
    upper_case_durability_cost_=2.0;
    eraser_life_ = eraser_life;
    
}

Pencil::~Pencil()
{
}

void Pencil::sharpen()
{
    if(get_remaining_sharpens())
    {
        length_cm_ -= sharpen_length_reduction_;
        durability_ = default_durability_;
    }
}

int Pencil::get_remaining_sharpens()
{
    return int(floor(length_cm_ / sharpen_length_reduction_));
}

void Pencil::write(std::string letters, Paper &p)
{
    //reduce durability for each letter
    //if durability is too low, replace the letter with a string
    for(unsigned int i = 0; i<letters.length(); i++)
    {
        char l = letters.at(i);
        if((isupper(l)&&durability_<upper_case_durability_cost_) || (islower(l)&&durability_<lower_case_durability_cost_))
            letters.replace(i,1,1,' ');
            
        updateDurability(l);
    }
    p.write(letters);
}

void Pencil::updateDurability(char c)
{
    //only reduce durability for upper and lower case characters
    if(isupper(c)) 
        durability_ -= upper_case_durability_cost_;
    
    if(islower(c)) 
        durability_ -= lower_case_durability_cost_;
    
    if(durability_<=0) 
        durability_ = 0;
}

void Pencil::erase(std::string letters, Paper &p)
{
    //Finds the last position in the matching text
    int start = p.read().rfind(letters)-1;
    unsigned int end = start + letters.length();
    for(unsigned int i=0;i<letters.length();i++)
    {
        if(!isspace(p.read().at(end-i)) && eraser_life_>0)
        {
            p.clear_at(end-i,1);
            eraser_life_ -= 1;
        }
    }
    
}

void Pencil::edit(unsigned int start_position, std::string letters, Paper &p)
{
    for(unsigned int i = 0; i<letters.length(); i++)
    {
        char l = letters.at(i);
        if((isupper(l)&&durability_<upper_case_durability_cost_) || (islower(l)&&durability_<lower_case_durability_cost_))
            letters.replace(i,1,1,' ');
            
        updateDurability(l);
    }
    p.write_at(start_position,letters);
    
}