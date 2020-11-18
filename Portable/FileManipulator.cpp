#include "FileManipulator.h"
#include "utilties.h"
#include <iostream>
#include <fstream> 
using namespace std;

 int FileManipulator::createFile(vector<string> listArgs)
{

	 //Erase first argument because its the command and args are only needed.
	 listArgs.erase(listArgs.begin() );


	 for (auto fileName : listArgs) {

		 //Append the extension .pofm to end of filename
		 std::string newFileName = fileName + ".pofm";

		 //create an object stream
		 ifstream f(newFileName);

		 //Check if this file name already exist in the current directory
		 if (f.good()) {

			 std::cout << "This file name already exist";

		 }else{

			 //If doesn't exist create the file

			 std::ofstream outfile(newFileName);

			 outfile.close();


		 }
	 }
	
	 








	return 0;
}

int FileManipulator::deleteFile(vector<string> listArgs) {

	cout << "delete a file....." << endl;
	

	return 0;
}

int FileManipulator::renameFile(vector<string> listArgs) {

	cout << "rename a file....." << endl;
	


	return 0;
}
