#include "StringUtils.h"


StringUtils::StringUtils() 
{

}


bool StringUtils::check_matricula(string matricula)
{
	/**
	  * We'll assume that the Vehicle registration plate
	  * will follow a standard format of nn-nn-ll
	  * where n is a number and l is a letter
	*/
	if(matricula.size() != 8)
		return false;

	unsigned pos, oldpos;

	pos = matricula.find(0x2D);

	//Found it?
	if(pos != string::npos)
	{
		string tmp;

		tmp = matricula.substr(0, pos);
		for(size_t i = 0; i < tmp.size(); i++)
			if(!isdigit(tmp[i]))
				return false;

		oldpos = pos;
		pos = matricula.find(0x2D, pos + 1);

		if(pos != string::npos)
		{
			tmp = matricula.substr(oldpos + 1, pos - oldpos - 1);
			for(size_t i = 0; i < tmp.size(); i++)
				if(!isdigit(tmp[i]))
					return false;

			tmp = matricula.substr(pos + 1, matricula.size() - pos);
			for(size_t i = 0; i < tmp.size(); i++)
				if(!isalpha(tmp[i]))
					return false;

			return true;
		}

		return false;
	}

	return false;
}


void StringUtils::print_error_message(const char *message)
{
	if(sizeof(message) / sizeof(message[0]) > 0)
		cerr << message << endl;
	else
		cerr << "[!] Debug: Provided empty message! Error!" << endl;
}


StringUtils::~StringUtils()
{

}