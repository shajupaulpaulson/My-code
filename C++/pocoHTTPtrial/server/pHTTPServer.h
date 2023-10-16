#include <Poco/Net/HTTPServerRequest.h>

class pHTTPServer : public HTTPServerRequest
{
	pHTTPServer();

	virtual const SocketAddress & clientAddress() const;

	virtual HTTPServerResponse & response() const;

	virtual bool secure() const;

	virtual const SocketAddress & serverAddress() const;

	virtual const HTTPServerParams & serverParams() const;

	virtual std::istream & stream() ;

};
