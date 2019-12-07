// License : No Information
//
//
//
// Author: Shajupaul Paulson
#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

#include <string>

//Please update the device used for the game
const std::string device =  "/dev/input/event4";

//Please add the button code for the buttons plannned for the game
// Use evtest and the device name to find the same.
//

const int buttonAValue = 2;
const int buttonBValue = 3;
const int buttonCValue = 4;

#endif
