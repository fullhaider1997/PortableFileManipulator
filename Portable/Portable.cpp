
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>
int main()
{
   
	std::string command;
	std::string arg;
	std::string delimiter = " ";
	std::vector<std::string> listargs;
	size_t pos = 0;
	while (1)
	{

		std::cin >> command;
		
		std::stringstream ss(command);
		std::istream_iterator<std::string> begin(ss);
		std::istream_iterator<std::string> end;
		std::vector<std::string> vstrings(begin, end);
		std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
		
		
		if (vstrings.at(0) == "creat") {
			std::cout << "create command" << std::endl;
		}




	}




}

