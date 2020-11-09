
#include <iostream>
#include <vector>
#include <string>
int main()
{
   
	std::string command;
	std::string commandCpy;
	while (1)
	{

		std::cin >> command;
		commandCpy = command;
		std::string firstWord = command.substr(0, command.find(" "));
		
		if (firstWord == "create") {

			std::cout << "You used create file command: " << commandCpy <<std::endl;

		}





	}




}

