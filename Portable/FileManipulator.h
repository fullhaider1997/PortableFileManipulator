#pragma once
#include "vector"
#include "string"


constexpr auto COMMAND = 0 ;

using namespace std;
class FileManipulator {


public:
	static int createFile(vector<string> listArgs);
	static int deleteFile(vector<string> listArgs);
	static int renameFile(vector<string> listArgs);
	static int appendTextEndFile(vector<string> listArgs);
	static int InsertTextByPosition(vector<string> listArgs);
	static int removeAllTextFile(vector<string> listArgs);





};
