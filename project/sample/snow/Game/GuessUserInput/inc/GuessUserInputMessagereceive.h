// License : No Information
//
//
//
// Author: Shajupaul Paulson
#ifndef GAME_GUESSUSERINPUT_GUESSUSERINPUTMESSAGERECEIVE_H
#define GAME_GUESSUSERINPUT_GUESSUSERINPUTMESSAGERECEIVE_H

#include <mqueue.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#include <thread>
#include <iostream>
#include <sstream>
#include <string>

#define PMODE 0655

namespace GuessUserInput{
  namespace guessuserinputmessagereceive{
  //Class to receive the User Input
  //Only handles the message queue
  class GuessUserInputMessagereceive{
  public:
    GuessUserInputMessagereceive();
    ~GuessUserInputMessagereceive();

    void inputFromMsgQueue();

  private:
    mqd_t msg;

  };

  }

}

#endif
