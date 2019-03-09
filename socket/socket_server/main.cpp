#include "SocketServer.h"


#define PORT 8080
const string IP_defined = "127.0.0.1";
int main(){

  SocketServer m_socketServer;
  m_socketServer.setPortno(PORT);
  m_socketServer.setIP(IP_defined);
  m_socketServer.createSocket();
  m_socketServer.bindSocket();
  m_socketServer.listenSocket();
  m_socketServer.acceptSocket();

/*  int notsuccess = 0;
  do{
   notsuccess= m_socketClient.connectSocket();
   if (notsuccess != 0){
	string exit_criteria;
	cout << "Connection failed press X to exit";
        cin >> exit_criteria;
        if ( exit_criteria == "X" )
	   exit(10);
     }
  } while (notsuccess == -1);
*/ 
  bool zeit = false;
  while (zeit == false) {
	string command = m_socketServer.readCommand();	
	/*if (command == "shutdown"){
	  //cleanup socket
          cout  <<"Command shutdown" <<endl;
	  zeit = true;
	}*/
	//if (zeit != true){
	  m_socketServer.sendCommand(command);
	//}
  }


}
