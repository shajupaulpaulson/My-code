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

    try {
		HTTPClientSession cs("127.0.0.1", 8081);    
    	HTTPRequest request(HTTPRequest::HTTP_GET, "/?encoding=text",HTTPMessage::HTTP_1_1);
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
        std::cout << "Exception " << e.what();
    }

}

