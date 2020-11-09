#pragma once
#include "vector"
#include "string"


constexpr auto COMMAND = 0 ;
class FileManipulator {


public:
	static int createFile(vector<string> listArgs);
	static int deleteFile(vector<string> listArgs);
	static int renameFile(vector<string> listArgs);





};
