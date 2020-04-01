#pragma once
#include <mysql.h>
#include "Account.h"
class Menu {

public:
	MYSQL* mysql;
	Account actual_acc;
	void display_menu();
private:
	const char* make_query_name();
	void get_name_surname();
};