#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include "Paper.h"


TEST_CASE("Read and write update text","[paper]")
{
    Paper p;
    p.write("abc");
    REQUIRE(p.read() == "abc");
}

TEST_CASE("Clear_at turns letters to spaces","[paper]")
{
    Paper p;
    p.write("space");
    //Intended functionality
    p.clear_at(0,5);
    REQUIRE(p.read().compare("     ")==0);
    //Writing resumes at end of white space
    p.write("after");
    REQUIRE(p.read().compare("     after")==0);


}

TEST_CASE("clear_at only works in existing range", "[paper]")
{
    Paper p;
    p.write("space");
    //Clear with negative index doesn't work
    unsigned int i = -1;
    p.clear_at(i,3);
    REQUIRE(p.read().compare("space")==0);
}


TEST_CASE("clear_at can't extend text","[paper]")
{
    Paper p;
    p.write("space");
    //Clear beyond text length doesn't work
    p.clear_at(0,20);
    REQUIRE(p.read().compare("space")==0);
}

TEST_CASE("Write_at overwrites spaces","[paper]")
{
    Paper p;
    p.write("     ");
    p.write_at(2,"St");
    p.write_at(0,"Po");
    REQUIRE(p.read() == "PoSt ");
    
    //write into erased space
    p.clear_at(0,3);
    p.write_at(0,"lis");
    REQUIRE(p.read() == "list ");
    


}

TEST_CASE("write_at can't write to negative index","[paper]")
{
    Paper p;
    p.write("list ");
      //Don't allow writing to negative index
    p.write_at(-1,"lis");
    REQUIRE(p.read() == "list ");
}

TEST_CASE("write_at can't extend existing text","[paper]")
{
      Paper p;
    p.write("list ");
        
    //Don't allow using "write_at" beyond existing text space
    p.write_at(0,"Listening");
    REQUIRE(p.read()=="list ");
}

TEST_CASE("write_at can't write to index beyond text space","[paper]")
{
   Paper p;
    p.write("list ");
    //Don't allow indexing beyond existing text
    p.write_at(30,"list");
    REQUIRE(p.read()=="list ");    
}

TEST_CASE("Write_at obscures letters","[paper]")
{
    Paper p;
    p.write(" BC   ");
    p.write_at(0,"Post");
    REQUIRE(p.read() == "P@@t  ");
    
    /*
     * For example, writing "artichoke" in the middle of 
     * "An       a day keeps the doctor away" would result in 
     * "An artich@k@ay keeps the doctor away".
     */
    
    Paper p2;
    p2.write("An       a day keeps the doctor away");
    p2.write_at(3,"artichoke");
    REQUIRE(p2.read() == "An artich@k@ay keeps the doctor away");
    
}
