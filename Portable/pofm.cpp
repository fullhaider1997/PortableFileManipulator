
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>
#include "FileManipulator.h"
int main()
{
   
	std::string command;
	
	while (1)
	{

		std::cin >> command;
		
		std::stringstream ss(command);
		std::istream_iterator<std::string> begin(ss);
		std::istream_iterator<std::string> end;
		std::vector<std::string> listArgs(begin, end);
		std::copy(listArgs.begin(), listArgs.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
		
		
		if (listArgs.at(COMMAND) == "create") {
			
			 FileManipulator::createFile(listArgs);

		}
		else if (listArgs.at(COMMAND) == "rename") {

			FileManipulator::renameFile(listArgs);
		}
		else if (listArgs.at(COMMAND) == "delete") {

			FileManipulator::renameFile(listArgs);
		}









	}




}

