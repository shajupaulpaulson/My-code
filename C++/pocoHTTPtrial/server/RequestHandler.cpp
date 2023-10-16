#include "RequestHandler.h"

int RequestHandler::count = 0;

HTTPResponse::HTTPStatus RequestHandler::processHTTPHead(HTTPServerRequest &req, string responseData){
	HTTPResponse::HTTPStatus status = HTTPResponse::HTTP_BAD_REQUEST;

	return status;
}

HTTPResponse::HTTPStatus RequestHandler::processHTTPGet(HTTPServerRequest &req, string responseData){
	HTTPResponse::HTTPStatus status = HTTPResponse::HTTP_BAD_REQUEST;

	return status;
}

HTTPResponse::HTTPStatus RequestHandler::processHTTPDelete(HTTPServerRequest &req, string responseData){
	HTTPResponse::HTTPStatus status = HTTPResponse::HTTP_BAD_REQUEST;

	return status;
}

HTTPResponse::HTTPStatus  RequestHandler::processHTTPPut(HTTPServerRequest &req, string responseData){
	HTTPResponse::HTTPStatus status = HTTPResponse::HTTP_BAD_REQUEST;

	return status;
}

HTTPResponse::HTTPStatus RequestHandler::processHTTPPost(HTTPServerRequest &req, string responseData){
	HTTPResponse::HTTPStatus status = HTTPResponse::HTTP_BAD_REQUEST;

	return status;
}

void RequestHandler::handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp)
{
	HTTPResponse::HTTPStatus status = HTTPResponse::HTTP_INTERNAL_SERVER_ERROR;
	string responseData;
	if(req.getMethod() == req.HTTP_HEAD){
		cout << "HTTP_HEAD Method" <<endl;
		status=processHTTPHead(req, responseData);

	}
    else if(req.getMethod() == req.HTTP_GET){
		cout << "HTTP_GET Method" <<endl;
		status=processHTTPGet(req, responseData);

	}
    else if(req.getMethod() == req.HTTP_DELETE){
		cout << "HTTP_DELETE Method" <<endl;
		status=processHTTPDelete(req, responseData);

	}
    else if(req.getMethod() == req.HTTP_PUT){
		cout << "HTTP_PUT Method" <<endl;
		status=processHTTPPut(req, responseData);

	}
    else if(req.getMethod() == req.HTTP_POST){
		cout << "HTTP_POST Method" <<endl;
		status=processHTTPPost(req, responseData);

	}
	else{
		status = HTTPResponse::HTTP_NOT_ACCEPTABLE;
		cout << "Unknown Method" <<endl;
	}

    resp.setStatus(status);
    resp.setContentType("text/html");

    ostream& out = resp.send();
    out << "<h1>Hello world!</h1>"
        << "<p>Count: "  << ++count         << "</p>"
        << "<p>Host: "   << req.getHost()   << "</p>"
        << "<p>Method: " << req.getMethod() << "</p> \n"
        << "Status "   << status   << "\n";
    out.flush();

    cout << endl
         << "Response sent for count=" << count
         << " and URI=" << req.getURI() 
		 << "<p>Host: "   << req.getHost()   << "</p>"
         << "<p>Method: " << req.getMethod() << "</p>"
         << "<p>Method: " << status << "</p>"
		<< endl;
}
