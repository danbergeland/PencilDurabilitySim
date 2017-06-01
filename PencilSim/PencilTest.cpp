//Main test runner defined in PaperTest
#include "catch.hpp"
#include "Pencil.h"
#include <string>

TEST_CASE("Pencil writes","[pencil]")
{
    //Test basic write function
    Pencil pe;
    Paper p;
    pe.write("abc",p);
    REQUIRE(p.read()=="abc");
    

}

TEST_CASE("Pencil writes Requirement","[pencil]")
{
      /*
     * Text written by the pencil should always be appended to existing text on the paper. 
     * Thus, given a piece of paper with the text "She sells sea shells", 
     * when a pencil is instructed to write " down by the sea shore" on the paper, 
     * the paper will then contain the entire string.
     */
    Pencil pe;
    Paper p2;
    pe.write("Sally sells sea shells",p2);
    pe.write(" down by the sea shore.",p2);
    REQUIRE(p2.read()=="Sally sells sea shells down by the sea shore.");
}

TEST_CASE("Point Degradation Reqs test","[pencil]")
{
    /*
     * Hence when a pencil with a point durability of four is instructed 
     * to write the string "text", the paper will contain the entire string. 
     */
    Pencil pe(4, 20);
    Paper p;
    pe.write("text",p);
    REQUIRE(p.read()=="text");
}

TEST_CASE("Point Degradation Reqs test2","[pencil]")
{
    /*
     * if a pencil with point durability of four is instructed 
     * to write the string "Text", the paper will only show "Tex "
     */
    Pencil pe(4, 20);
    Paper p;
    pe.write("Text",p);
    REQUIRE(p.read()=="Tex ");
}

TEST_CASE("Sharpen Restores durability", "[pencil]")
{
    Pencil pe(4, 20);
    Paper p;
    pe.write("texts",p);
    //make pencil dull
    REQUIRE(p.read()=="text ");
    //restore durability and continue writing
    pe.sharpen();
    pe.write("texts",p);
    REQUIRE(p.read()=="text text ");
}

TEST_CASE("Sharpen reduces length, and stops restoring durability", "[pencil]")
{
    //durability 4, length 2.5
    Pencil pe(4,2.5);
    Paper p;
    pe.sharpen();
    pe.sharpen();
    //length should now be .5
    //make dull, show spaces
    pe.write("texts",p);
    REQUIRE(p.read()=="text ");
    //this should not restore durability because pencil too short
    pe.sharpen();
    pe.write("texts",p);
    REQUIRE(p.read()=="text      ");
}

TEST_CASE("Eraser removes last instance of text", "[pencil]")
{
    Pencil pe;
    Paper p;
    pe.write("texts",p);
    pe.erase("xt",p);
    REQUIRE(p.read()=="te  s");

}

TEST_CASE("Eraser removes last instance, Req", "[pencil]")
{
        
    /*
     * Given a piece of the paper containing the string:
"How much wood would a woodchuck chuck if a woodchuck could chuck wood?"
when the string "chuck" is erased, the paper should read:
"How much wood would a woodchuck chuck if a woodchuck could       wood?"
     */
     Paper p;
     Pencil pe;
     pe.write("How much wood would a woodchuck chuck if a woodchuck could chuck wood?",p);
     pe.erase("chuck",p);
     REQUIRE(p.read()=="How much wood would a woodchuck chuck if a woodchuck could       wood?");
     
}

TEST_CASE("Pencil Eraser Decays","[pencil]")
{
    Paper p;
    //Added overload for eraser
    Pencil pe(10,10,1);
    
    pe.write("abc",p);
    pe.erase("abc",p);
    //eraser removes from the end, and stops erasing when it's out of life
    REQUIRE(p.read()=="ab ");
}

TEST_CASE("Pencil Eraser, Req Buffalo Bill","[pencil]")
{
    Paper p;
    Pencil pe(500,10,3);
    
    /*
     * Thus if a pencil's eraser has remaining durability of three, 
     * and it is instructed to erase the word "Bill" from "Buffalo Bill", 
     * then the text remaining on the paper is "Buffalo B   ".
     */
    
    pe.write("Buffalo Bill",p);
    pe.erase("Bill",p);
    //eraser removes from the end, and stops erasing when it's out of life
    REQUIRE(p.read()=="Buffalo B   ");
}

TEST_CASE("Edit text at position","[pencil]")
{
    Paper p;
    Pencil pe;
    
    /*
     * if the paper contains the text 
     * "An       a day keeps the doctor away", a pencil can can be instructed 
     * to write the word "onion" in the white space gap, 
     * so the text reads "An onion a day keeps the doctor away".
     */
    
    pe.write("An apple a day",p);
    pe.erase("apple",p);
    REQUIRE(p.read()=="An       a day");
    pe.edit(3,"onion",p);
    REQUIRE(p.read()=="An onion a day");
}

TEST_CASE("Edit text at position with obscured letters","[pencil]")
{
    Paper p;
    Pencil pe;
    
    /*
     * Existing text on the page cannot 'shift' to make room for new text. 
     * If the new text is longer than the allocated whitespace and thus 
     * would collide with other existing non-whitespace characters on the page, 
     * these character collisions should be represented by the "@" character. 
     * For example, writing "artichoke" in the middle of 
     * "An       a day keeps the doctor away" 
     * would result in "An artich@k@ay keeps the doctor away".
     */
    
    pe.write("An apple a day keeps the doctor away",p);
    pe.erase("apple",p);
    pe.edit(3,"artichoke",p);
    REQUIRE(p.read()=="An artich@k@ay keeps the doctor away");
}