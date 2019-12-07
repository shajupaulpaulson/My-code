// License : No Information
//
//
//
// Author: Shajupaul Paulson

#include "inc/GuessUserInputMessagereceive.h"
#include "inc/GuessUserInputAlgorthim.h"

namespace GuessUserInput{
  namespace guessuserinputmessagereceive{

//Constructor to receive the Inpt message from the keyboard interrupt thread
    GuessUserInputMessagereceive::GuessUserInputMessagereceive(){
      struct mq_attr attr;
      attr.mq_maxmsg = 10;
      attr.mq_msgsize = 20;
      msg = mq_open("/KeyInput",O_RDONLY|O_CREAT, PMODE, &attr);
      if(msg == -1) {
        perror("Child mq_open failure");
        exit(0);
      }
    }

//Destructor for the same class
    GuessUserInputMessagereceive::~GuessUserInputMessagereceive(){
      mq_close(msg);
      mq_unlink("/KeyInput");
    }

//Reads input from message queue send from the keyInput thread
//Converts to integer and send to the Input algorthim
    void GuessUserInputMessagereceive::inputFromMsgQueue()
    {
      bool stop=false;
      GuessUserInput::guessuserinputalgorthim::GuessUserInputAlgorthim* m_guessuserInputAlgo =
                GuessUserInput::guessuserinputalgorthim::GuessUserInputAlgorthim::getInstance();
      while(!stop){
        char buf[100];
        int status;
        status = mq_receive(msg, buf, 100, 0);
        if (status == -1) {
          perror("mq_receive failure\n");
        }
        std::stringstream str(buf);
        int x;
        str >> x;
        stop = m_guessuserInputAlgo->checkKeycombination(x);

      }
    }
  }//namespace guessuserinputmessagereceive
}//namespace GuessUserInput
