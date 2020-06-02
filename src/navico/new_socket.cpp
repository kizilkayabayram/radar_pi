#include "boost/asio.hpp"
using namespace boost::asio;

int new_socket()
{
    io_service io_service;
    ip::udp::socket socket(io_service);
    ip::udp::endpoint remote_endpoint;

    socket.open(ip::udp::v4());

    remote_endpoint = ip::udp::endpoint(ip::address::from_string("127.0.0.1"), 9000);

    boost::system::error_code err;

    socket.send_to(buffer("Jane Doe", 8), remote_endpoint, 0, err);
    
    socket.close();

    return 0;
}