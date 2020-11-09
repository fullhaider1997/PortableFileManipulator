
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>
#include "FileManipulator.h"

using namespace std;


int main()
{
   
	string command;
	
	while (1)
	{

		cin >> command;
		
		stringstream ss(command);
		istream_iterator<std::string> begin(ss);
		istream_iterator<std::string> end;
		vector<std::string> listArgs(begin, end);
		copy(listArgs.begin(), listArgs.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
		
		
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

