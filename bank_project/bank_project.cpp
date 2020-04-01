#include "System_bank.h"
#include <conio.h>
int main()
{
	System_bank bank;
	bank.connect_with_database();
	bank.system();
	_getch();
    return 0;
}

