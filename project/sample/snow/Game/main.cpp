// License : No Information
//
//
//
// Author: Shajupaul Paulson
#include "Game.h"
#include "config.h"

#include <random>
#include <string>
#include <iostream>


using namespace game;

int main(){
  Game m_game(device, buttonAValue,buttonBValue,buttonCValue);
  m_game.gameStart();
}
