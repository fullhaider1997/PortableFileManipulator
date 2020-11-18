
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>
#include "FileManipulator.h"
#include "utilties.h"
using namespace std;


int main()
{
   
	
	while (1)
	{
		string command;
		std::vector<std::string> listArgs;
		
		std::getline(std::cin, command);

	    listArgs = Utility::convertStringToVectorString(command);
		


		
		if (listArgs.at(COMMAND) == "create") {
			
			 FileManipulator::createFile(listArgs);
			 

		}
		else if (listArgs.at(COMMAND) == "rename") {

			FileManipulator::renameFile(listArgs);
			
		}
		else if (listArgs.at(COMMAND) == "delete") {

			FileManipulator::deleteFile(listArgs);
			
		}
		else {

			std::cout << "Unrecognize input !" << std::endl;
		}
		
		
		







	}




}

