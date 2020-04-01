#pragma once
#include <mysql.h>
#include "Login_interface.h"
#include "Menu.h"
#include <iostream>
class System_bank
{
public:
	void connect_with_database(); 
	void system();
	System_bank(); 
	~System_bank();
private:
	MYSQL mysql;
	Login_interface log_int;
	Menu menu;
	char* adress,*login,*password,*database;
};