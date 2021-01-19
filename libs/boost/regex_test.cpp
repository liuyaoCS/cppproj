#include <boost/regex.hpp>
#include <iostream>
#include <string>

//g++ -I/opt/boost_1.73.0/include -o regex_test regex_test.cpp -L/opt/boost_1.73.0/lib -lboost_regex
//export LD_LIBRARY_PATH=/opt/boost_1.73.0/lib
int main()
{
    std::string line;
    boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );

    while (std::cin)
    {
        std::getline(std::cin, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat))
            std::cout << matches[2] << std::endl;
    }
}