#include "Signalreceiver.h"
bool SignalReceiver::StopAllstuff=false;
SignalReceiver::SignalReceiver() {
}

SignalReceiver::~SignalReceiver(){

}

void SignalReceiver::ReceivedSigAbrt(int signal)
{
	cout << "Received Abort from Server with signal value : " << signal <<endl;
} 

void SignalReceiver::ReceivedSigFPE(int signal)
{
	cout << "Received Abort from Server with signal value : " << signal <<endl;
}

void SignalReceiver::ReceivedSigILL(int signal)
{
	cout << "Received Abort from Server with signal value : " << signal <<endl;
}
void SignalReceiver::ReceivedSigINT(int signal)
{
	cout << "Received Abort from Server with signal value : " << signal <<endl;
}	
void SignalReceiver::ReceivedSigSEGV(int signal)
{
	cout << "Received Abort from Server with signal value : " << signal <<endl;
}
void SignalReceiver::ReceivedSigTERM(int signal)
{
	cout << "Received Abort from Server with signal value : " << signal <<endl;
}

void SignalReceiver::ReceivedSigSTP(int signal){
	cout << " Received STP from Server and ending cleanly prgram with signal value : " << signal <<endl;
	SignalReceiver::StopAllstuff=true;
}

void SignalReceiver::SetSignalHandler(){

	if (signal (SIGABRT, SignalReceiver::ReceivedSigAbrt)== SIG_ERR)
	{
		cout << "Error setting up Abort" << endl;
	}

	if (signal (SIGFPE, SignalReceiver::ReceivedSigFPE)== SIG_ERR)
	{
		cout << "Error setting up Fpe" << endl;
	}
	if (signal (SIGILL, SignalReceiver::ReceivedSigILL)== SIG_ERR)
	{
		cout << "Error setting up Ill" << endl;
	}
	if (signal (SIGINT, SignalReceiver::ReceivedSigINT)== SIG_ERR)
	{
		cout << "Error setting up Int" << endl;
	}
	if (signal (SIGSEGV, SignalReceiver::ReceivedSigSEGV)== SIG_ERR)
	{
		cout << "Error setting up Segv" << endl;
	}
	if (signal (SIGTERM, SignalReceiver::ReceivedSigTERM)== SIG_ERR)
	{
		cout << "Error setting up Term" << endl;
	}
	if (signal (SIGTSTP, SignalReceiver::ReceivedSigSTP)== SIG_ERR)
	{
		cout << "Error setting up STP" << endl;
	}
}




