#include "SocketClient.h"


#define PORT 8080
const string IP_defined = "127.0.0.1";
int main(){

  SocketClient m_socketClient;
  m_socketClient.setPortno(PORT);
  m_socketClient.setIP(IP_defined);
  m_socketClient.createSocket();
  cout << "Created Socket" <<endl;
  sleep (10);
  int notsuccess = 0;
  do{
   notsuccess= m_socketClient.connectSocket();
   if (notsuccess != 0){
	string exit_criteria;
	cout << "Connection failed press X to exit";
        cin >> exit_criteria;
        if ( exit_criteria == "X" )
	   exit(10);
     }
  cout << "Connected Socket" <<endl;
  sleep (10);
  } while (notsuccess == -1);
  
  bool zeit = false;
  do {
	string command;
	cout << "Enter Command of X for exit" <<endl;
	getline(cin, command);
 	if (command == "X"){
	  cout << "closing connection " << endl;

	  exit(20);
	}
	m_socketClient.sendCommand(command);
	string output = m_socketClient.readCommand();	
 	cout << "\n\
*****************************\n\
	output\n\
*****************************\n\
"<<"\n" << output << "\n\
*****************************\n"
	<<endl;
  }while (zeit == false);


}

