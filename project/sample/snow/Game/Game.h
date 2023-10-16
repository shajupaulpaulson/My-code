// License : No Information
//
//
//
// Author: Shajupaul Paulson
#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <string>
#include <iostream>
#include <map>

#include "inc/RandomGen.h"
#include "inc/KeyInputWorker.h"
#include "inc/GuessUserInputMessagereceive.h"
#include "inc/GuessUserInputAlgorthim.h"

namespace game{
//Class Game which is called by the main function
//It starts the game by creating required objects and worker thread
//And controls the game
  class Game{
  public:
    explicit Game(std::string gameDevice, int butAvalue, int butBvalue, int butCvalue);
    ~Game();
    void gameStart();
    void getSequence();
    void gamePlay();

  private:
    std::string gameSequence;
    Random::RandomGen::randomGen m_randomGen;
    keyInput::keyInputWorker::KeyInputWorker m_keyInput;
    GuessUserInput::guessuserinputmessagereceive::GuessUserInputMessagereceive m_guessuserInput;
    GuessUserInput::guessuserinputalgorthim::GuessUserInputAlgorthim* m_guessuserInputAlgo;
  };

}


#endif
