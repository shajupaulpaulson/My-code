#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Util/ServerApplication.h>
#include <iostream>
#include <string>
#include <vector>

using namespace Poco::Net;
using namespace Poco::Util;
using namespace std;

class RequestHandler : public HTTPRequestHandler
{
public:
  virtual void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp);
  
  HTTPResponse::HTTPStatus processHTTPHead(HTTPServerRequest &req, string responseData);
  HTTPResponse::HTTPStatus processHTTPGet(HTTPServerRequest &req, string responseData);
  HTTPResponse::HTTPStatus  processHTTPDelete(HTTPServerRequest &req, string responseData);
  HTTPResponse::HTTPStatus processHTTPPut(HTTPServerRequest &req, string responseData);
  HTTPResponse::HTTPStatus processHTTPPost(HTTPServerRequest &req, string responseData);

private:
  static int count;
};


