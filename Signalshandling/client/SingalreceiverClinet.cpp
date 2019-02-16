#include <iostream>
#include <mqueue.h>
#include <thread>
#include "Signalreceiver.h"
#include <sys/types.h>
#include <unistd.h>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <sys/ipc.h> 
#include <sys/msg.h> 

static int s_pid=-1;
static bool ServerLost = true;
void serverAlive(){
	while (!SignalReceiver::getStopInfo()){

		if (0 == kill(s_pid, 0))
		{
	    		// Process exists.
		}
		else {
			//Server Process lost Ser s_pid to -1 and 
			s_pid = -1;

		}
		sleep(1); //Sleep 1 sec for next alive check
	}
}

int main() {

SignalReceiver m_signalReceiver;
m_signalReceiver.SetSignalHandler();
int t_pid = getpid ();
key_t key,key2; 
int msgid,msgid2; 
  
// ftok for client queue 
key = ftok("Client", 20); 
msgid = msgget(key, 0666 | IPC_CREAT); 

//ftok for server queue
key2 = ftok("Server", 20); 
msgid2 = msgget(key2, 0666 | IPC_CREAT); 


boost::interprocess::interprocess_mutex mut;
mut.lock();
thread t1(serverAlive);
	while (!SignalReceiver::getStopInfo()){
		if (s_pid != -1){

		}
		else{
			//set a condition wait for server to come up
			mut.lock();
			// msgsnd to send message 
			msgsnd(msgid, &t_pid, sizeof(t_pid), 0);
			int ls_pid;
			msgrcv(msgid, &ls_pid, sizeof(ls_pid), 1, 0);
			s_pid = ls_pid;
		}
	}



t1.join();


return 0;

}	
