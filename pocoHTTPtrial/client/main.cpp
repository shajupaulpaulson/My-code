#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPMessage.h"
#include "Poco/Net/WebSocket.h"
#include "Poco/Net/HTTPClientSession.h"
#include <iostream>
#include <Poco/StreamCopier.h>

using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::Net::WebSocket;
using namespace Poco;
//namespace net = Poco::Net;
using namespace std;
int main(int args,char **argv)
{
	bool Forceexit = false;
	while(!Forceexit){
		unsigned int userReq=0;
		do{
			cout <<"Enter your Server Request as [1, 2 or 3]	\n1. GET (reterieve Database entry) \n2. PUT(Add a Database entry \n3. POST (Try to run some commands)\n4. Exit\n"	;
	    cin  >> userReq;
		} while (userReq >4 || userReq ==0);
		if (userReq == 4){
			Forceexit=true	;	
			continue;
		}
		string requestHTTP;
		string keyDB;
		string values;
		string clientreq;
		switch (userReq){
			case 1:
				requestHTTP=HTTPRequest::HTTP_GET;
				cout << "Please enter DB key" <<endl;	
				cin >> keyDB;
				clientreq = keyDB;
			break;

			case 3:
				requestHTTP=HTTPRequest::HTTP_POST;
				cout << "Please enter your command " << endl;
				cin >> clientreq;
			break;

			case 2:
				requestHTTP=HTTPRequest::HTTP_PUT;
				cout << "Please enter DB key" <<endl;	
				cin >> keyDB;			
				cout << "Please enter key value" <<endl;	
				cin >> values;
				clientreq=keyDB + "<>" + values;
			break;

			default:
				
			break;		
		}

	try {
	
		HTTPClientSession cs("127.0.0.1", 8081);    
    	HTTPRequest request(requestHTTP, clientreq,HTTPMessage::HTTP_1_1);
    	//request.set("origin", "http://www.google.com");
		cs.sendRequest(request);
    	HTTPResponse response;




        //char const *testStr="Hello echo websocket!";
        //char receiveBuff[256];


        //std::cout << "Received bytes " << rlen << std::endl;
        std::cout << response.getStatus() << " " << response.getReason() << endl;

        //m_psock->close();
    	// print response
	    istream &is = cs.receiveResponse(response);
    	StreamCopier::copyStream(is, cout);

    	} catch (std::exception &e) {
			Forceexit=true;
        	std::cout << "Exception " << e.what();
    	}
	}

}

