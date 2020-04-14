#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "..\Account\Account.h"
#include "..\Databasecontroller\Databasecontroller.h"
/// <summary>
/// Supports login and communicate with menu.
/// </summary>
class Logininterface
{
public:

	/// <summary>
	/// Displays the interface.
	/// </summary>
	void display_interface();

	/// <summary>
	/// Initializes a new instance of the <see cref="Logininterface"/> class.
	/// </summary>
	Logininterface();

	/// <summary>
	/// Returns the actual acc.
	/// </summary>
	Account return_actual_acc();
private:

	/// <summary>
	/// Checks the login and password.
	/// </summary>
	/// <returns></returns>
	Account check_login_and_password();

	/// <summary>
	/// The username from logging interface.
	/// </summary>
	std::string username_from_log;

	/// <summary>
	/// The password from logging interface.
	/// </summary>
	std::string password_from_log;
	
	/// <summary>
	/// The accounts which in database.
	/// </summary>
	std::vector <Account> accounts;

	/// <summary>
	/// The actual account which in logged into the system.
	/// </summary>
	Account actual_acc;

	/// <summary>
	/// The how many accounts.
	/// </summary>
	int how_many_acc = 0;

	/// <summary>
	/// Gets the accounts from database.
	/// </summary>
	void get_accounts_from_db();
};

