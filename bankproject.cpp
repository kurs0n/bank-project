#include "Systembank\Systembank.h"
#include <conio.h>
int main()
{
	Systembank bank;
	bank.connect_with_database();
	bank.system();
	_getch();
    return 0;
}

