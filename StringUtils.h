#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_

#include <iostream>
#include <string>
using std::cout;
using std::cerr;
using std::endl;
using std::string;


class StringUtils
{
public:
	StringUtils();
	bool check_matricula(string matricula);
	void print_error_message(const char *message);
	~StringUtils();
};
#endif