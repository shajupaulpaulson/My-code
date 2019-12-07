// License : No Information
//
//
//
// Author: Shajupaul Paulson

#include "inc/KeyInputWorker.h"

namespace keyInput {
  namespace keyInputWorker{

//Constructor for the KeyInput constructor
//It will assign the keyboard code or button code provide by the device
//Opens the device from where the user interrupt has to be taken
//Open a messagequeue
    KeyInputWorker::KeyInputWorker
      (std::string devicename, int bCodeA, int bCodeB, int bCodeC):
      codeA(bCodeA),codeB(bCodeB),codeC(bCodeC){
        continuethread=true;
        device = open(devicename.c_str(), O_RDONLY);
        struct mq_attr attr;
        attr.mq_maxmsg = 10;
        attr.mq_msgsize = 20;
        msg = mq_open("/KeyInput", O_WRONLY|O_CREAT, PMODE, &attr);
        if(msg == -1) {
          perror("Child mq_open failure");
          exit(0);
        }

    }

//Destructor for the KeyInput
    KeyInputWorker::~KeyInputWorker()
    {
      threadStop();

      //DeleteMessageQueue
      mq_close(msg);
    }

//Worker thread created to read the keyboardinput
//It is configured only to take keyboard press and not the release
//TODO:Proable issue with long keyboard press
    void KeyInputWorker::KeyInputWorkerThread()
    {
        struct input_event ev;
        while(continuethread)
        {
          //std::cout <<"InsideThread"<<std::endl;
            read(device,&ev, sizeof(ev));
            if(ev.value==1 ){
                  //  printf("Key: %i State: %i\n",ev.code,ev.value);
                    if(ev.code == codeA || ev.code == codeB || ev.code == codeC){
                      //send message
                      std::string str=std::to_string(ev.code);
                      //std::cout << ev.code << std::endl;
                      char const *p = str.c_str();
                      int status = mq_send(msg, p, str.size(), 0);
                      if (status == -1) {
                        perror("mq_send failure\n");
                      }
                    }
            }
        }
        return ;
    }

//Worker thread start
    void KeyInputWorker::WorkerThreadStart()
    {
      t=std::thread(&KeyInputWorker::KeyInputWorkerThread,this);
    }

//Call from parent to start the thread
    void KeyInputWorker::intialize()
    {
      WorkerThreadStart();
    }

//Could be used in future if we need a safe exist by
//configuring this thread to the Power or shutdown sequenc
    void KeyInputWorker::threadStop()
    {
      continuethread=false;
      t.join();
    }
  }//namespace keyInputWorker
}//namespace keyInput
