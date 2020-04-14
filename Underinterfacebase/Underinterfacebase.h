#pragma once
#include "..\Account\Account.h"
#include <mysql.h>

/// <summary>
/// Underinterfacebase which is abstract and virtual. 
/// </summary>
///<remarks>
///<para>Class <seealso cref = "Interfaceaboutme"/> inherit.</para>
///<para>Class <seealso cref = "Interfacetransfer"/> inherit.</para>
///</remarks>
class Underinterfacebase {
public:

	/// <summary>
	/// Displays this interface.
	/// </summary>
	virtual void display() = 0;

	/// <summary>
	/// Account which is logged into the system.
	/// </summary>
	Account acc;

	/// <summary>
	/// Initializes a new instance of the <see cref="Underinterfacebase"/> class.
	/// </summary>
	Underinterfacebase();
};