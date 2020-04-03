#pragma once
#include <mysql.h>
#include "..\Logininterface\Logininterface.h"
#include "..\Menu\Menu.h"
#include <iostream>
class Systembank
{
public:	Systembank();
	~Systembank();
	void connect_with_database(); 
	void system();
private:
	MYSQL mysql;
	Logininterface* log_int;
	Menu menu;
	char* adress,*login,*password,*database;
};