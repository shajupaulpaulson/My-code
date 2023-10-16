#include "SocketClient.h"

SocketClient::SocketClient(){
 memset(&address, '0', sizeof(address));
}


void SocketClient::createSocket(){

if ( ( sockfd = socket(AF_INET, SOCK_STREAM, 0) )  == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 

    address.sin_family = AF_INET; 
    //address.sin_addr.s_addr = inet_addr(ip.c_str()); 
    address.sin_port = htons( portno ); 
}

int SocketClient::connectSocket(){
    if(inet_pton(AF_INET, ip.c_str(), &address.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    }

    if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) 
    { 
        cout<< "\nConnection Failed \n"; 
        return -1; 
    } 
    return 0;
}

void SocketClient::sendCommand(string com){
    cout << com << "  " << strlen(com.c_str()) << endl;
  send(sockfd , com.c_str() , strlen(com.c_str()) , 0 );
}

string SocketClient::readCommand(){
 char buffer[4028]={0};
 valread = read( sockfd , buffer, 4028); 
 string temp(buffer);
 cout << "\n Received output " << temp <<endl;	
 return temp;

}
