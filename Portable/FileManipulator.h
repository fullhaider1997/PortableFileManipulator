#pragma once
#include "vector"
#include "string"


constexpr auto COMMAND = 0 ;

using namespace std;
class FileManipulator {


public:
	static void createFile(vector<string> listArgs);
	static void deleteFile(vector<string> listArgs);
	static void renameFile(vector<string> listArgs);
	static void copyFile(string from, string to);
	static int moveFile(string from, string to);
	static int appendTextEndFile(vector<string> listArgs,string name);
	static int InsertTextByPosition(vector<string> listArgs, string command);
	static void removeAllTextFile(vector<string> listArgs);
	


};
