#pragma once
#include "vector"
#include "string"

constexpr auto COMMAND = 0 ;
class FileManipulator {


public:
	static int createFile(std::vector<std::string> listArgs);
	static int deleteFile(std::vector<std::string> listArgs);
	static int renameFile(std::vector<std::string> listArgs);





};