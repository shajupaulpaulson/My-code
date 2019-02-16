#include <iostream>
#include <mqueue.h>
#include <thread>
#include  <sys/types.h>
#include  <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <sys/ipc.h> 
#include <sys/msg.h> 

using namespace std;
typedef struct mymsg {
  long mtype;
  int temp_pid;
 }mymsg;

int main (){
int t_pid = getpid ();
key_t key,key2; 
int msgid,msgid2; 
mymsg msg,buff;  
// ftok for client queue 
key = ftok("Client", 20); 
msgid = msgget(key, 0666 | IPC_CREAT); 

//ftok for server queue
key2 = ftok("Server", 20); 
msgid2 = msgget(key2, 0666 | IPC_CREAT); 
boost::interprocess::interprocess_mutex mut;
//mut.unlock();
int c_pid=-1;
msg.mtype=1;
msg.temp_pid=t_pid;
msgsnd(msgid2, &msg, sizeof(mymsg), 0);
cout <<" Send " <<endl;

msgrcv(msgid, &buff, sizeof(mymsg), 1, 0);
c_pid=buff.temp_pid;
cout <<" Received " << c_pid <<endl;

cout << "Provide the signal you want to send or exit" << endl;
bool exitloop=false;
int input;
while (!exitloop){
cout << "Signal list: \n1.SIGABRT \n2.SIGFPE \n3.SIGILL \n4.SIGINT \n5.SIGSEGV \n6.SIGTERM \
	\n7.SIGTSTP --> Exits the client \n \n Please enter a number or 0 to exit... \n";

cin >> input;
switch (input) {

case 0:
	exitloop=true;
break;

case 1:
	kill (c_pid,SIGABRT);	
break;

case 2:
	kill (c_pid,SIGFPE);
break;

case 3:
	kill (c_pid,SIGILL);
break;

case 4:
	kill (c_pid,SIGINT);
break;

case 5:
	kill (c_pid,SIGSEGV);
break;

case 6:
	kill (c_pid,SIGTERM);
break;

case 7:
	kill (c_pid,SIGTSTP);
	cout << "Exiting server as there is no use of server now" << endl;
	exitloop=true;
break;

default :
 cout << "Number out of bound" <<endl;
}
}

return 0;
}
