#include "System_bank.h"

System_bank::System_bank()
{
	mysql_init(&mysql);
	adress = "127.0.0.1";
	login = "root";
	password = "1234";
	database = "bank";
}
System_bank::~System_bank()
{
	mysql_close(&mysql);
}
void System_bank::connect_with_database()
{
	log_int.mysql = &mysql;
	menu.mysql = &mysql;
	mysql_real_connect(&mysql, adress, login, password, database, 0, NULL, 0);
	mysql_select_db(&mysql, "bank");
}
void System_bank::system()
{
	log_int.display_interface();
	menu.actual_acc = log_int.actual_acc;
	menu.display_menu();
	mysql_close(&mysql);
}