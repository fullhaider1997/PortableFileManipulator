
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>
#include "FileManipulator.h"
#include "utilities.h"
using namespace std;


int main()
{
   
	
	while (1)
	{

		string command;
		std::vector<std::string> listArgs;
		

		std::getline(std::cin, command);

		//Only process strings that actually have something and not empty strings
		if (command.size() > 0) {
			listArgs = Utility::convertStringToVectorString(command);
		}else{

			continue;
		}
		


		
		if (listArgs.at(COMMAND) == "create") {
			
			 FileManipulator::createFile(listArgs);
			 

		}else if (listArgs.at(COMMAND) == "rename") {

			FileManipulator::renameFile(listArgs);
			
		}else if (listArgs.at(COMMAND) == "delete") {

			FileManipulator::deleteFile(listArgs);
			
		}else if (listArgs.at(COMMAND) == "append") {
             
			FileManipulator::appendTextEndFile(listArgs,command);

		}
		else if (listArgs.at(COMMAND) == "quit") {

			std::cout << "Bye !";
			break;
		}
		
		 
		else {

			std::cout << "unrecognized input!" << std::endl;
		}
		
		
		







	}




}

