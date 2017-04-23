#define ASIO_DISABLE_THREADS
#include <cxxhttp/httpd.h>
using namespace cxxhttp;

template <class transport>
static bool hello(typename net::http::server<transport>::session &session, std::smatch &) {
  session.reply(200, "Hello World!");
  return true;
}

namespace tcp {
  static httpd::servlet<transport::tcp> hello("/", ::hello<transport::tcp>);
}

namespace unix {
  static httpd::servlet<transport::unix> hello("/", ::hello<transport::unix>);
}

int main(int argc, char *argv[]) { return cxxhttp::main(argc, argv); }
