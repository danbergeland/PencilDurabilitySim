#include "Paper.h"

Paper::Paper()
{
    //Init with a blank paper
    text_ = "";
}

Paper::~Paper()
{
}

void Paper::write(std::string letters)
{
    text_.append(letters);
}

std::string Paper::read()
{
    return text_;
}

void Paper::clear_at(unsigned int index,unsigned int clear_length)
{
    //check in range, positive number, and won't add length
    if (index + clear_length <= text_.length() && index >= 0)
    {
        text_.replace(index,clear_length,clear_length,' ');
    }
}

void Paper::write_at(unsigned int index, std::string letters)
{
    //check range
    if(index+letters.length() <= text_.length() && index>=0)
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
  if(text_.at(index)==' ')
  {
      text_.replace(index,1,1,letter);
  }
  else
  {
      text_.replace(index,1,1,'@');
  }
  
}