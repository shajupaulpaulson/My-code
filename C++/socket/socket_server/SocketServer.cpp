#include "SocketServer.h"

SocketServer::SocketServer(){

}


void SocketServer::createSocket(){

   if ( ( sockfd = socket(AF_INET, SOCK_STREAM, 0) )  == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
    // Forcefully attaching socket to the port 8080 
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    }       
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = inet_addr(ip.c_str()); 
    address.sin_port = htons( portno ); 
}


void SocketServer::bindSocket(){
    if (bind(sockfd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

}

void SocketServer::listenSocket(){
    if (listen(sockfd, 3) < 0) 
    { 
       
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
}

void SocketServer::acceptSocket(){
    int len = sizeof(address);
    if ((clientSocket = accept(sockfd, (struct sockaddr *)&address,  
                       (socklen_t*)&(len)))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
}

string SocketServer::readCommand(){
 char buffer[4028]={0};
 valread = read( sockfd , buffer, 4028);
cout <<" valread  = " << valread <<endl; 	
 string temp(buffer);
 cout << "\n Received input" << temp <<endl;
 return temp;

}

void SocketServer::sendCommand(string &com){
  cout << com << "  " << strlen(com.c_str()) << endl;
  send(sockfd , com.c_str() , strlen(com.c_str()) , 0 );
}
