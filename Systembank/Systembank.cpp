#include "Systembank.h"

Systembank::Systembank()
{
	mysql_init(&mysql);
	adress = "127.0.0.1";
	login = "root";
	password = "1234";
	database = "bank";
	log_int = new Logininterface();
}
Systembank::~Systembank()
{
	mysql_close(&mysql);
}
void Systembank::connect_with_database()
{
	log_int->mysql = &mysql;
	menu.mysql = &mysql;
	mysql_real_connect(&mysql, adress, login, password, database, 0, NULL, 0);
	mysql_select_db(&mysql, "bank");
}
void Systembank::system()
{
	log_int->display_interface();
	menu.actual_acc = log_int->return_actual_acc();//transfer to menu.acc actual acc in systembank
	delete log_int;
	menu.display(); 
	mysql_close(&mysql);
}