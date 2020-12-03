#include "FileManipulator.h"
#include <stdio.h>
#include "utilties.h"
#include <iostream>
#include <fstream> 
#include <algorithm>
#include <cctype>
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

//int FileManipulator::deleteFile(vector<string> listArgs) {
//
//	char choice;
//	
//	listArgs.erase(listArgs.begin());
//	
//	for(auto fileName :listArgs){
//		
//		std::string deleteFileName = fileName + ".pofm";
//		
//		ifstream f(deleteFileName);
//		
//		if(f.good()) {
//			
//			std::cout<<"Are you sure you want to delete it (y/n)";
//			std::cin>>choice;
//			
//			if(choice == "y") {
//				if(!remove(deleteFileName))
//					std::cout<<"Successfully deleted "<<deleteFileName<<"\n";
//				else
//					std::cout<<"Unable to Delete "<<deleteFileName<<"\n";
//			}
//			else if(choice == "n")
//				std::cout<<deleteFileName<< " not deleted\n";
//			else
//				std::cout<<"Exiting program\n";
//				
//	}
//		
//	
//
//	return 0;
//}
//
//int FileManipulator::renameFile(vector<string> listArgs) {
//
//	cout << "rename a file....." << endl;
//	
//
//
//	return 0;
//}


/// <summary>
/// Copy file from a source location to a target location
///  Both copies exist
/// </summary>
/// <param name="from">Source Location</param>
/// <param name="to">Target Location</param>
/// <returns></returns>
int FileManipulator::copyFile(vector<string> listArgs)
{
	listArgs.erase(listArgs.begin());
	string to = listArgs.back();
	string from = listArgs.front();
	ifstream fi;
	ofstream fo;
	char c;
	//try to access original source file to copy
	//fi.open(from);
	//if (!fi)
	//{
	//	cout << "Cannot open source file";
	//	return 0;
	//}

	////try to open the target file to paste in.
	//fo.open(to);
	//if (!fo)
	//{
	//	cout << "Cannot open target file";
	//	return 0;
	//}


	//while (fi.eof() == 0)
	//{
	//	fi >> c;
	//	fo << c;
	//}
	//cout << "Copying file successful";
	//fi.close();
	//fo.close();
	//return 0;

	//access sourcefile
	fi.open(from, fstream::in | fstream::binary);

	if (fi.is_open())
	{
		//copy to target location
		fo.open(to, fstream::out);

		while (fi.read(&c, 1)) {
			fo.write(&c, 1);
		}

		//close both files
		fo.close();
		fi.close();
		std::cout << "Successfully copied file...";
	}
	else {
		std::cout << "Source File error..";
	}
}

/// <summary>
/// Move file from source location to a target location
/// Only one copy of file exists
/// </summary>
/// <param name="from"></param>
/// <param name="to"></param>
/// <returns></returns>
int FileManipulator::moveFile(vector<string> listArgs)
{
	//not using streams
	listArgs.erase(listArgs.begin());
	string to = listArgs.back();
	string from = listArgs.front();
	const char* f = from.c_str();
	const char* t = to.c_str();

	//instead use rename function to move directory
	int process = rename(f, t);
	if (process = 0)
		std::cout << "File successfully moved";
	else
		std::cout << "Error moving file";

	return process;
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
