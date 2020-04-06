#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "..\Account\Account.h"
class Logininterface
{
public:
	void display_interface();
	Logininterface();
	Account return_actual_acc();
	MYSQL* mysql;
private:
	Account check_login_and_password();
	std::string username_from_log;
	std::string password_from_log;
	std::vector <Account> accounts;
	Account actual_acc;
	int how_many_acc = 0;
	void get_accounts_from_db();
};

