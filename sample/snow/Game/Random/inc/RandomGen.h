// License : No Information
//
//
//
// Author: Shajupaul Paulson
#ifndef GAME_RANDOM_RANDOMGEN_H
#define GAME_RANDOM_RANDOMGEN_H

#include <random>
#include <string>
#include <iostream>

namespace Random{
  namespace RandomGen{
    //Class for random generation of pattern
    //To be initated every time they want to create the game
    //It generates a random combination which user can then use.
    class randomGen{
    public:
      randomGen(std::string value);
      /*randomGen * getInstance(void){
        if(m_randomGen == NUL){
          m_randomGen = new (randomGen);
        }
        return m_randomGen;
      }*/

      std::string createRandomPattern();

    private:
      std::string ButtonPattern;
      //randomGen * m_randomGen;
    };

  }//namespace RandomGen

}//namespace Random


#endif
