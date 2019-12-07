// License : No Information
//
//
//
// Author: Shajupaul Paulson
#include "Game.h"

namespace game{
//Constructor which is where the button value and the randomGen string
//is passed
//starts the worker thread
//Initalize the algorthim egnine
  Game::Game(std::string gameDevice, int butAvalue, int butBvalue, int butCvalue):m_randomGen("ABC"),m_keyInput(gameDevice,butAvalue,butBvalue,butCvalue){
    std::map<int,char> characterMap={{butAvalue,'A'},{butBvalue,'B'},{butCvalue,'C'}};
    m_keyInput.intialize();
    m_guessuserInputAlgo=GuessUserInput::guessuserinputalgorthim::GuessUserInputAlgorthim::getInstance();
    m_guessuserInputAlgo->initallize(characterMap);
  }

//Destructor currently only one pointer that is removed
  Game::~Game(){
    delete(m_guessuserInputAlgo);
  }

//Starts the game. creates sequence and ask the user to play the gamePlay
//User is stuck in the game play untill sequence is correctly judged
//TODO Infinte loop will be removed if we a shutdown message
//or signal handling Message
  void Game::gameStart(){
    while(1){
      getSequence();
      gamePlay();
    }

  }

//Sequence generated and provides the same to Game algorthim
  void Game::getSequence()
  {
    gameSequence=m_randomGen.createRandomPattern();
    m_guessuserInputAlgo->updateSeqence(gameSequence);
    //std::cout << gameSequence<<std::endl;
  }

//Game play is intiated and now the function to read from message queue
//is started and as user input the infinte loop in GuessUserInputAlgorthim
//ensures that the game is played till the user pattern judge is successful
  void Game::gamePlay(){
      m_guessuserInput.inputFromMsgQueue();
  }
}//namespace game
