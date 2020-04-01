#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
class Login_interface
{
public:
	void display_interface();
	Login_interface();
	MYSQL* mysql;
	Account actual_acc;//in the future protected 
private:
	Account check_login_and_password();
	std::string username_from_log;
	std::string password_from_log;
	std::vector <Account> accounts;
	int how_many_acc = 0;
	void get_accounts_from_db();
};

