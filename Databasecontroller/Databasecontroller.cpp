#include "Databasecontroller.h"

const char *Databasecontroller::query(std::string quer)
{
	static std::string temp; 
	temp = quer;
	const char *temp1 = temp.c_str(); // conversion to const char* from string 
	return temp1;
}
std::string Databasecontroller::quote = "'";
MYSQL Databasecontroller::mysql;
//std::vector <Account> Databasecontroller::acc;