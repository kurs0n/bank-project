#pragma once
#include "..\Underinterfacebase\Underinterfacebase.h"
/// <summary>
/// Have informations about logged account and display it.
/// </summary>
/// <seealso cref="Underinterfacebase" />
class Interfaceaboutme : public Underinterfacebase {
public:

	/// <summary>
	/// Displays this interface.
	/// </summary>
	void display();

	/// <summary>
	/// Initializes a new instance of the <see cref="Underinterfacebase"/> class.
	/// </summary>
	Interfaceaboutme() : Underinterfacebase()
	{;}
}; 