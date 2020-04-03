#pragma once
#include "..\Account\Account.h"
#include <mysql.h>
class Underinterfacebase{
public:
	virtual void display() =0 ;
	Account acc;
};