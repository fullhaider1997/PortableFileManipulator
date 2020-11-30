#include "FileManipulator.h"
#include "utilities.h"
#include <iostream>
#include <fstream> 
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <string>
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)
#include <stdio.h>
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

	 char choice;
	 // Erasing the command from the input string
	 listArgs.erase(listArgs.begin());
	
	 // for loop to delete files files
	 for (auto fileName : listArgs) {
	
		 // each file requested to be deleted is input into string deleteFileName
		 std::string deleteFileName = fileName + ".pofm";
		
		 ifstream f(deleteFileName);

		 // Checking the file exists.
		 if (f.good()) {
			
			 // Recheck if the user wants to delete the file
			 std::cout << "Are you sure you want to delete "<<deleteFileName<<" (y/n)";
			 std::cin >> choice;
			
			 // If yes, the file is deleted.
			 if (choice == 'y') {
				 if (!std::remove("deleteFileName"))
					 std::cout << "Successfully deleted " << deleteFileName << "\n";
				 else
					 std::cout << "Unable to Delete " << deleteFileName << "\n";
			 }
			 // If no, the file is not deleted.
			 else if (choice == 'n')
				 std::cout << deleteFileName << " not deleted\n";
			 
			 // Any other option, the program exits.
			 else
				 std::cout << "Exiting program\n";

		 }
		 else {
			 // If unable to locate the file
			 cout<<"File to be deleted cannot be located\n";
		 }



		 
	 }
	 return 0;
 }


int FileManipulator::renameFile(vector<string> listArgs) {

	cout << "rename a file....." << endl;
	// Variable for oldFileName
	string oldFileName;
	// Variable for newFileName
	string newFileName;


	return 0;
}

int FileManipulator::appendTextEndFile(vector<string> listArgs, string command) {

	
	 std::string newFileName;
	 std::string text;
	 std::string stringVersion;
	 std::size_t posFirstSingleQuotation = 0;
	 std::size_t posSecondSingleQuotation = 0;
	 

	//Erase the first arg because its just the command
	//listArgs.erase(listArgs.begin());

	 command.erase(command.begin(), command.begin() + 6);
	/*
	std::cout << "List of args..." << std::endl;

	for (auto arg : listArgs) {
		std::cout << arg << std::endl;
	}
	*/

    //concatenate all args into a string
	//for (auto arg : listArgs) {
		//stringVersion += arg;
		
	//}
	       stringVersion = command;
	     
	     //Find the first single quotation mark
		 posFirstSingleQuotation = stringVersion.find("'");

		 // if you found the first single quotation mark
		if (posFirstSingleQuotation != std::string::npos) {


		

			//Erase the first single quotation mark
			stringVersion.erase(stringVersion.begin() + posFirstSingleQuotation);

			//find the second quotation mark
			posSecondSingleQuotation = stringVersion.find("'");

			//Erase the second quotation mark
			stringVersion.erase(stringVersion.begin() + posSecondSingleQuotation);
			
		}
		  //Retrieve the text between the first quotation mark and second quotation mark and store in variable text;
		 text = stringVersion.substr(posFirstSingleQuotation, posSecondSingleQuotation);


		// Erase the text the user trying to append
		// The leftover in stringVersion is the file name
		stringVersion.erase(posFirstSingleQuotation, posSecondSingleQuotation);
		
		
		

		// Attach file extension
		 newFileName = stringVersion + ".pofm";

		 //If there is any extra space in the name remove it.
		 newFileName.erase(std::remove(newFileName.begin(), newFileName.end(), ' '), newFileName.end());
		 



		 ifstream file(newFileName);

		 if (file.good() == false) {

			 std::cout << "Something wrong with the file or it doesn't exist" << std::endl;
			 

			 file.close();

			 return 0;

		 } else {


			 //create an output stream and open the stream in append mode
			 ofstream file(newFileName, ios::app);

			 //if file does exist than append text than close the output stream

			 file << text;

			 file.close();

		 }
		
	

	return 0;
}


int  FileManipulator::InsertTextByPosition(vector<string> listArgs) {
	// insert filename position_number text;


	   std::string fileName;
	   int SpecifiedPostion;
	   int countChars = 0;
	   std::string tempData;
	   std::string line;
	   std::string data;
       listArgs.erase(listArgs.begin());

	 

	   fileName = listArgs.at(0);
	   SpecifiedPostion = std::stoi(listArgs.at(1));
	   data = listArgs.at(2);

	   //check for all args if they are valid or not
	   std::string newFileName = fileName + ".pofm";
	   

	   //create an object stream
	   ifstream file(newFileName);

	   //Check if this file exist
	   if (file.good() == false) {

		   std::cout << "This file doesn't exist !";

	   }
	   
	   //Check if the position is valid or not
	   if (SpecifiedPostion < 0) {
		   std::cout << "Pos shouldn't be negative !" << std::endl;
	   }

	   FILE* fptr;
	   const char* a = newFileName.c_str();
	   const char* h = "w";
	    fptr = std::fopen(a,h);
		if (fptr == NULL) {
			std::cout << "fptr is null" << std::endl;
		}
		const char* const d = data.c_str();

	



	return 0;
}

int FileManipulator::removeAllTextFile(vector<string> listArgs) {

	std::cout << "Remove the text in the file....." << std::endl;

	//Erase the command
	listArgs.erase(listArgs.begin());
	

	for (auto fileName : listArgs) {


		//check for all args if they are valid or not
		std::string newFileName = fileName + ".pofm";


		//create an object input stream
		ifstream ifile(newFileName);
		

		//Check if this file exist
		if (file.good() == false) {

			std::cout << "This file doesn't exist !";

		}

		//close the object input file stream
		file.close();

		ofstream ofile(newFileName);
		
		// we open the file for writing and use the trunc option to discard all the data in the file
		ofile.open(newFileName, std::ofstream::out | std::ofstream::trunc);
		//close the file output stream
		ofile.close();



	}

	return 0;
}
