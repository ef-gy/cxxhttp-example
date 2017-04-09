#define ASIO_DISABLE_THREADS
#include <cxxhttp/httpd.h>
using namespace cxxhttp;

template <class transport>
static bool hello(typename net::http::server<transport>::session &session, std::smatch &) {
  session.reply(200, "Hello World!");
  return true;
}

namespace tcp {
  using asio::ip::tcp;
  static httpd::servlet<tcp> hello("/", ::hello<tcp>);
}

namespace unix {
  using asio::local::stream_protocol;
  static httpd::servlet<stream_protocol> hello("/", ::hello<stream_protocol>);
}

int main(int argc, char *argv[]) { return io::main(argc, argv); }
