#pragma once
#include <mysql.h>
#include "..\Logininterface\Logininterface.h"
#include "..\Databasecontroller\Databasecontroller.h"
#include "..\Menu\Menu.h"
#include <iostream>
/// <summary>
/// System which Supports Menu and Underinterfaces.
/// </summary>
class Systembank
{
	/// <summary>
	/// Initializes a new instance of the <see cref="Systembank"/> class.
	/// </summary>
public:	Systembank();

		/// <summary>
		/// Finalizes an instance of the <see cref="Systembank"/> class.
		/// </summary>
		~Systembank();

		/// <summary>
		/// Connects with database.
		/// </summary>
		void connect_with_database();

		/// <summary>
		/// Supports Interfaces and Menu.
		/// </summary>
		void system();
private:

	/// <summary>
	/// Login interface.
	/// </summary>
	Logininterface* log_int;

	/// <summary>
	/// The menu.
	/// </summary>
	Menu menu;

	/// <summary>
	/// The database information.
	/// </summary>
	char *adress, *login, *password, *database;
};