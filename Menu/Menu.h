#pragma once
#include <mysql.h>
#include <conio.h>
#include <stdlib.h>
#include <limits> 
#include "..\Account\Account.h"
#include "..\Interfaceaboutme\Interfaceaboutme.h"
#include "..\Interfacetransfer\Interfacetransfer.h"
class Menu {

public:
	MYSQL* mysql;
	Account actual_acc;// actual account which logged into a system 
	Interfaceaboutme* about_me;//interface about me
	Interfacetransfer* transfer;//interface transfer
	bool log = false;
	void display();//display actual menu and goes to interface options
private:
	const char* make_query_name();
	const char* make_query_surname();
	const char* make_query_cash();
	const char* make_query_date();
	const char* make_query_bill();
	const char* make_query_accountid();
	void set_data();// set data to actual account 
	void init_aboutmeinterface();//initialazing about me interface 
	void init_transferinterface();//initialazing transfer interface 
	void transfer_data(Underinterfacebase* underinterface);//transfer data from logging interface
	void relog();
	void must_click();
	void go_to_interface(int op);
};