#include "Paper.h"

Paper::Paper()
{
    //Init with a blank paper
    text = "";
}

Paper::~Paper()
{
}

void Paper::write(std::string letters)
{
    text.append(letters);
}

std::string Paper::read()
{
    return text;
}

void Paper::clear_at(unsigned int index,unsigned int clear_length)
{
    //check in range, positive number, and won't add length
    if (index + clear_length <= text.length() && index >= 0)
    {
        text.replace(index,clear_length,clear_length,' ');
    }
}

void Paper::write_at(unsigned int index, std::string letters)
{
    //check range
    if(index+letters.length() <= text.length() && index>=0)
    {
        //step through each letter in the index
        for(unsigned int i=0;i<letters.length();i++)
        {
            add_letter(index+i, letters.at(i));
        }
    }
}

void Paper::add_letter(int index, char letter)
{
  if(text.at(index)==' ')
  {
      text.replace(index,1,1,letter);
  }
  else
  {
      text.replace(index,1,1,'@');
  }
  
}