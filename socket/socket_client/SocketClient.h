#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <cstring>
#include <netinet/in.h> 
#include <stdlib.h> 
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;
class SocketClient {

public:
SocketClient();

inline void setPortno(int Port) { portno=Port;};
inline void setIP(string IP) { ip=IP;};

void createSocket ();
int connectSocket();
void sendCommand(string com);
string readCommand();

private:
 int sockfd, valread, portno ;
 struct sockaddr_in address; 
 string ip;

};
