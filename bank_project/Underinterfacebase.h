#pragma once
#include "Account.h"
#include <mysql.h>
class Underinterfacebase{
public:
	virtual void display() =0 ;
	Account acc;
};