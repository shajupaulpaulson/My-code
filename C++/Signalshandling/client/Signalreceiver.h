
#include <iostream>
#include <signal.h>
#include <errno.h>

using namespace std;

class SignalReceiver{
public:
SignalReceiver();
~SignalReceiver();


void SetSignalHandler();

static void ReceivedSigAbrt(int signal);
static void ReceivedSigFPE(int signal);
static void ReceivedSigILL(int signal);
static void ReceivedSigINT(int signal);
static void ReceivedSigSEGV(int signal);
static void ReceivedSigTERM(int signal);
static void ReceivedSigSTP(int signal);

inline static bool getStopInfo (){return StopAllstuff;};
private:
static bool StopAllstuff;

};

