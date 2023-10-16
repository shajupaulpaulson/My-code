// License : No Information
//
//
//
// Author: Shajupaul Paulson
#include "inc/RandomGen.h"

namespace Random {
  namespace RandomGen{

//Constructor to create for RandomGen with an Intial String patternt to create
//random Pattern
//String instead of button code as button code can be in double digits
    randomGen::randomGen(std::string value):ButtonPattern(value){}

//CreateRandome pattern
//Uses random_device create the best random combination
//compare to other random generator
    std::string randomGen::createRandomPattern(){
      auto len=0;
      std::string ransequence="";
      while(len <3){
        std::random_device generator;
        std::uniform_int_distribution<int> distribution(0,2);
        int pos = distribution(generator);
        ransequence+=ButtonPattern.at(pos);
        len++;
      }
      return ransequence;
    }
  }//namespace RandomGen
}//namespace Random
