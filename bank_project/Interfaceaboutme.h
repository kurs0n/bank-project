#pragma once
#include "Underinterfacebase.h"
class Interfaceaboutme : public Underinterfacebase {
public : 
	void display(); 
	Interfaceaboutme();
	Interfaceaboutme &operator=(Account &s);
}; 