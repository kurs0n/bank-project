#pragma once
#include <mysql.h>
#include "..\Account\Account.h"
#include "..\Interfaceaboutme\Interfaceaboutme.h"
class Menu {

public:
	MYSQL* mysql;
	Account actual_acc;
	Interfaceaboutme* about_me;
	void display();
	void go_to_interface(int op);
private:
	const char* make_query_name();
	const char* make_query_surname();
	const char* make_query_cash();
	const char* make_query_date();
	void get_data();
	void init_underinterfaces();
	void transfer_data(Underinterfacebase* underinterface);
};