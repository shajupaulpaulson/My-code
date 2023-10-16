// License : No Information
//
//
//
// Author: Shajupaul Paulson
#ifndef GAME_KEYINPUT_KEYINPUTWORKER_H
#define GAME_KEYINPUT_KEYINPUTWORKER_H

#include <mqueue.h>
#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>

#include <iostream>
#include <string>
#include <thread>

#define PMODE 0655

namespace keyInput{
  namespace keyInputWorker{
    //Class keyInput which is a worker thread
    //created to read from the device input the keyInput
    //Use the mapping code provide from Game class and pass it on msgqueue
    class KeyInputWorker{
    public:
      KeyInputWorker (std::string devicename, int bCodeA, int bCodeB, int bCodeC);
      ~KeyInputWorker();
      void WorkerThreadStart();
      void intialize();

    private:
      void threadStop();
      void KeyInputWorkerThread();

      int device;
      int codeA, codeB, codeC;
      bool  continuethread;
      mqd_t msg;
      std::thread t;

    };

  }//namespace keyInputWorker

}//namespace keyInput
#endif
