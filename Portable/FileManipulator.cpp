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
	 
	 if (fileExists(arg.input_file))
	{
		if (arg.force) {
			FILE* input = fopen(arg.input_file, "w");
			if (input == NULL) {
				printf("Error : File cannot be created\n");
				exit(1);
			}

			if (arg.verbose)
				printf("File successfully created\n");
			exit(1);
		}
		printf("File already exists. Do you want to overwrite the file? y/n\n");
		char answer = 0;
		scanf("%c", &answer);

		while (answer != 121 && answer != 110) {
			printf("Invalid Response. Try Again y/n\n");
			scanf("%c", &answer);
		}

		if (answer == 110)
			exit(1);
		if (answer == 121)
		{
			FILE* fptr = fopen(arg.input_file, "w");
			if (fptr == NULL) {
				printf("Cannot create the file\n");
				exit(1);
			}
			if (arg.verbose) {
				printf("File successfully created\n");
				exit(1);
			}
			else
				exit(1);
		}
	}
	else {
		FILE* input = fopen(arg.input_file, "w");

		if (input == NULL)
		{
			printf("Cannot create file\n");
			exit(1);
		}

		if (arg.verbose) {
			printf("File successfully created\n");
			exit(1);
		}
		else
			exit(1);
	}

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
