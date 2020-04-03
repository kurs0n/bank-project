#include "Menu.h"
void Menu::display()
{
	int option=0;
	get_data();
	std::cout << "Welcome " << actual_acc.Name << std::endl;
	std::cout << "Choose option: " << std::endl;
	std::cout << "1. About me" << std::endl;
	std::cout << "Your choose: ";
	std::cin >> option;
	go_to_interface(option);
}
const char *Menu::make_query_name()
{
    char temp[150];//this will be better 
	strcpy_s(temp, sizeof temp, "SELECT imie FROM bank.dane_konto AS dn INNER JOIN bank.accounts acc ON dn.id_konta=acc.id WHERE login = ");//adding chars using strcpy_s() function
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, actual_acc.Username.c_str());
	strcat_s(temp, sizeof temp, "'");
	static std::string temp1 = temp;// this is must static because 
	const char *temp3 = temp1.c_str();// this after function end is deleting a string 
	return temp3;
}
const char *Menu::make_query_surname()
{
	char temp[150];
	strcpy_s(temp, sizeof temp, "SELECT nazwisko FROM bank.dane_konto AS dn INNER JOIN bank.accounts acc ON dn.id_konta=acc.id WHERE login = ");//adding chars using strcpy_s() function
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, actual_acc.Username.c_str());
	strcat_s(temp, sizeof temp, "'");
	static std::string temp1 = temp;// this is must static because 
	const char *temp3 = temp1.c_str();// this after function end is deleting a string 
	return temp3;
}
const char *Menu::make_query_cash()
{
	char temp[150];//this will be better 
	strcpy_s(temp, sizeof temp, "SELECT stan FROM bank.accounts_v WHERE login =");//adding chars using strcpy_s() function
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, actual_acc.Username.c_str());
	strcat_s(temp, sizeof temp, "'");
	static std::string temp1 = temp;// this is must static because 
	const char *temp3 = temp1.c_str();// this after function end is deleting a string 
	return temp3;
}
const char *Menu::make_query_date()
{
	char temp[150];//this will be better 
	strcpy_s(temp, sizeof temp, "SELECT data from bank.dates as dt INNER JOIN bank.accounts_v AS kon ON dt.konto_id = kon.id_konta WHERE kon.login =");//adding chars using strcpy_s() function
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, actual_acc.Username.c_str());
	strcat_s(temp, sizeof temp, "'");
	static std::string temp1 = temp;// this is must static because 
	const char *temp3 = temp1.c_str();// this after function end is deleting a string 
	return temp3;
}
void Menu::get_data()
{
	mysql_query(mysql, make_query_name());
	MYSQL_RES *idquery = mysql_store_result(mysql);
	MYSQL_ROW record = mysql_fetch_row(idquery);
	actual_acc.Name = record[0];
	/*****************************************/
	mysql_query(mysql, make_query_surname());
	idquery = mysql_store_result(mysql);
	record = mysql_fetch_row(idquery);
	actual_acc.Surname = record[0];
	/*****************************************/
	mysql_query(mysql, make_query_cash());
	idquery = mysql_store_result(mysql);
	record = mysql_fetch_row(idquery);
	actual_acc.cash = record[0];//conversion to double
	/****************************************/
	mysql_query(mysql, make_query_date());
	idquery = mysql_store_result(mysql);
	while ((record = mysql_fetch_row(idquery)) != NULL)
	{
		for (int i=0; i<mysql_num_fields(idquery);i++ )
		{
			actual_acc.date.push_back(record[i]);
		}
	}
}
void Menu::go_to_interface(int op)
{
	switch (op)
	{
	  case 1:
	  {
		init_underinterfaces();
		transfer_data(about_me);
		about_me->display();
		delete about_me;
		break;
	  }
	 /* case 2:
	  {
		  /// int the future possible new function ;P 
		break;
	  }
	  case 3:
	  {
		  //
		break;
	  }*/// int the future possible new function ;P 
	  default:
	  {
		  std::cout << "Wrong choose!" << std::endl;
		  break;
	  }
	}
}
void Menu::transfer_data(Underinterfacebase* underinterface)
{
	underinterface->acc = actual_acc;// error
}
void Menu::init_underinterfaces()
{
	about_me = new Interfaceaboutme();
}