//
// timer.cpp
// ~~~~~~~~~
// 
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

//g++ -I/opt/boost_1.73.0/include -o timer timer.cpp -lpthread

void test(){
  boost::asio::io_context io;

  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
  t.wait();

  std::cout << "Hello, world!" << std::endl;
}

void print(const boost::system::error_code& /*e*/)
{
  std::cout << "Hello, world!" << std::endl;
}

void test_asyn(){
  boost::asio::io_context io;

  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
  t.async_wait(&print);

  io.run();
}
int main()
{
//   test();
test_asyn();
  return 0;
}