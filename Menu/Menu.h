#pragma once
#include <mysql.h>
#include <conio.h>
#include <stdlib.h>
#include <limits> 
#include <Windows.h>
#include "..\Account\Account.h"
#include "..\Interfaceaboutme\Interfaceaboutme.h"
#include "..\Interfacetransfer\Interfacetransfer.h"
#include "..\Databasecontroller\Databasecontroller.h"
/// <summary>
/// Menu interface.
/// </summary>
///<remarks>
///<para> Makes menu interface and communicate with underinterfaces.</para>
///</remarks>
class Menu {

public:

	/// <summary>
	/// The actual account which is logged into the system.
	/// </summary>
	Account actual_acc;

	/// <summary>
	/// The about me underinterface.
	/// </summary>
	Interfaceaboutme* about_me;

	/// <summary>
	/// The transfer underinterface.
	/// </summary>
	Interfacetransfer* transfer;

	/// <summary>
	/// this is variable which checks when customer want to relog.
	/// </summary>
	bool log = false;

	/// <summary>
	/// Displays this interface.
	/// </summary>
	void display();

private:

	/// <summary>
	/// Sets the data from database into account.
	/// </summary>
	void set_data();

	/// <summary>
	/// Initializes the aboutmeinterface.
	/// </summary>
	void init_aboutmeinterface();

	/// <summary>
	/// Initializes the transferinterface.
	/// </summary>
	void init_transferinterface();

	/// <summary>
	/// Transfers the data from logging interface.
	/// </summary>
	/// <param name="underinterface">The underinterface.</param>
	void transfer_data(Underinterfacebase* underinterface);

	/// <summary>
	/// Relogs actual account which is logged into system.
	/// </summary>
	void relog();

	/// <summary>
	/// Musts the click to go further.
	/// </summary>
	void must_click();

	/// <summary>
	/// Goes to interface.
	/// </summary>
	/// <param name="op">op is choose option.</param>
	void go_to_interface(int op);

};