
#include "RequestHandler.h"
#include "RequestHandlerFactory.h"

using namespace Poco::Net;
using namespace Poco::Util;
using namespace std;





class ServerApp : public ServerApplication
{
protected:
  int main(const vector<string> &)
  {
    HTTPServer httpServer(new RequestHandlerFactory, ServerSocket(8081), new HTTPServerParams);

    httpServer.start();
    cout << endl << "Server started" << endl;

    waitForTerminationRequest();  // wait for CTRL-C or kill

    cout << endl << "Shutting down..." << endl;
    httpServer.stop();

    return Application::EXIT_OK;
  }
};

int main(int argc, char** argv)
{
  ServerApp app;
  return app.run(argc, argv);
}
