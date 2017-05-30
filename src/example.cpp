#define ASIO_DISABLE_THREADS
#include <cxxhttp/httpd.h>
using namespace cxxhttp;

static void hello(http::sessionData &session, std::smatch &) {
  session.reply(200, "Hello World!");
}

static http::servlet servlet("/", ::hello);

int main(int argc, char *argv[]) { return cxxhttp::main(argc, argv); }
