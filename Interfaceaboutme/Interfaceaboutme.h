#pragma once
#include "..\Underinterfacebase\Underinterfacebase.h"
class Interfaceaboutme : public Underinterfacebase {
public:
	void display();
	Interfaceaboutme() : Underinterfacebase() 
	{;}
}; 