#pragma once 
#include "Systembank\Systembank.h"
#include "Databasecontroller\Databasecontroller.h"
#include <mysql.h>
Systembank* bank;
int main()
{
	while (true)
	{
		bank = new Systembank();
		bank->connect_with_database();
		bank->system();
		delete bank;
	}
}

