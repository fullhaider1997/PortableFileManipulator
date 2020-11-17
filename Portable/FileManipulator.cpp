#include "FileManipulator.h"
#include <iostream>

using namespace std;

 int FileManipulator::createFile(vector<string> listArgs)
{
	 /*	This function creates a new file on user request.
	 *	
	 *	Programming methodology
	 *	1. Accept file name from user.
	 *	2. Check if the filename already exits.
	 *	3. If the file does not exist
	 *		3.a Create file
	 * 	4. Else if file does exist
	 *		4.a Request if the user wants to enter a new filename.
	 *			4.a.a If yes, begin step 1.
	 *			4.a.b If no, request for the exit from program.
	 *				4.a.b.a If yes, exit.
	 *				4.a.b.b If no, go back to main menu.
	 *	Return
	 */
	 

	 cout << "Creating a file....." << std::endl;
	 
	 


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
