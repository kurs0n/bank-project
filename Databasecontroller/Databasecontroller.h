#pragma once
#include "..\Account\Account.h"
#include <mysql.h>
#include <iostream>
/// <summary>
/// Simple controller on Database.
/// </summary>
/// <remarks>
/// <para> Makes queries.</para>
/// <para> Init mysql. </para>
/// </remarks>
class Databasecontroller {
public:
	/// <summary>
	/// MYSQL object which is initialazing in System_bank.
	/// </summary>
    static MYSQL mysql;

	/// <summary>
	/// Function which make query.
	/// </summary>
	/// <param name="quer">String which is taking from other modules.</param>
	/// <returns>Return const char* because mysql_query needs const char*.</returns>
	static const char *query(std::string quer);


	/// <summary>
	/// quote because in string "'" this is not working.
	/// </summary>
	static std::string quote;

	
	/*/// <summary>
	/// Gets the accounts from db 
	/// </summary>
	static void get_accounts();

	/// <summary>
	/// Stores accounts which acutal in database 
	/// </summary>
	static std::vector <Account> acc;*/// soon 
};