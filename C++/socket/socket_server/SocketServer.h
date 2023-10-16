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
class SocketServer {

public:
SocketServer();

inline void setPortno(int Port) { portno=Port;};
inline void setIP(string IP) { ip=IP;};

void createSocket ();
void bindSocket();
void listenSocket();
void acceptSocket();
void sendCommand(string &com);
string readCommand();

private:
 int sockfd, valread, portno, clientSocket;
 struct sockaddr_in address; 
 string ip;

};
