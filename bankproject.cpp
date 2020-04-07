#include "Systembank\Systembank.h"
#include <conio.h>
#include <mysql.h>
Systembank* bank;
int main()
{
	while (true)
	{
		bank = new Systembank();
		bank->connect_with_database();
		bank->system();
		mysql_close(&bank->mysql);
		delete bank;
	}
}

