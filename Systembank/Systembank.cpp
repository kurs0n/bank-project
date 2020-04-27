#include "Systembank.h"
#include <cstdlib> 
Systembank::Systembank()
{
	mysql_init(&Databasecontroller::mysql);
	adress = std::getenv("DB_ADRESS");
	login = std::getenv("LOGIN");
	password = std::getenv("PASSWORD");
	database = std::getenv("DATABASE");
}
Systembank::~Systembank()
{
	mysql_close(&Databasecontroller::mysql);
}
void Systembank::connect_with_database()
{
	log_int = new Logininterface();
	//log_int->mysql = &Databasecontroller::mysql;
	mysql_real_connect(&Databasecontroller::mysql, adress, login, password, database, 0, NULL, 0);
	mysql_select_db(&Databasecontroller::mysql, "bank");
}
void Systembank::system()
{
	log_int->display_interface();
	menu.actual_acc = log_int->return_actual_acc();//transfer to menu.acc actual acc in systembank
	menu.display();
	delete log_int;
	mysql_close(&Databasecontroller::mysql);
}