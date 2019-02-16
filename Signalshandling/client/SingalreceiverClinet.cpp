#include <iostream>
#include <mqueue.h>
#include <thread>
#include "Signalreceiver.h"
#include <sys/types.h>
#include <unistd.h>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <sys/ipc.h> 
#include <sys/msg.h> 
typedef struct mymsg {
  long mtype;
  int temp_pid;
 }mymsg;

static int s_pid=-1;
static int t_pid = -1;
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
			ServerLost = true;

		}
		sleep(1); //Sleep 1 sec for next alive check
	}
}
void Messaging(){
	key_t key,key2; 
	int msgid,msgid2; 
	mymsg msg,buff;  
	// ftok for client queue 
	key = ftok("Client", 20); 
	msgid = msgget(key, 0666 | IPC_CREAT); 

	//ftok for server queue
	key2 = ftok("Server", 20); 
	msgid2 = msgget(key2, 0666 | IPC_CREAT); 
	while (!SignalReceiver::getStopInfo()){
	   if(ServerLost){
		cout << " About to receive" << endl;
		msgrcv(msgid2, &buff, sizeof(mymsg), 1, 0);

		s_pid = buff.temp_pid;	
		cout <<" Received " << s_pid <<endl;
		msg.temp_pid=t_pid;

		msg.mtype = 1;
		msgsnd(msgid, &msg, sizeof(msg), 0);
		cout <<" Send " <<endl;
		ServerLost = false;
		
	  }
   	  sleep (1);
	}
	msgctl(msgid, IPC_RMID, NULL);
	msgctl(msgid2, IPC_RMID, NULL);
}
int main() {

SignalReceiver m_signalReceiver;
m_signalReceiver.SetSignalHandler();
t_pid = getpid ();



boost::interprocess::interprocess_mutex mut;
//mut.lock();
thread t1(serverAlive);
thread t2(Messaging);
	while (!SignalReceiver::getStopInfo()){
		if (s_pid != -1){

		}
		else{
			//set a condition wait for server to come up
			//mut.lock();
			// msgsnd to send message 


		}

	}



t1.join();
t2.join();

return 0;

}	
