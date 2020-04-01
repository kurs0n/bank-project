#include "Menu.h"
void Menu::display_menu()
{
	get_name_surname();
	std::cout << "Welcome " << actual_acc.Name << std::endl;
}
const char *Menu::make_query_name()
{
    char temp[150];
	strcpy_s(temp, sizeof temp, "SELECT imie FROM bank.dane_konto AS dn INNER JOIN bank.accounts acc ON dn.id_konta=acc.id WHERE login = ");//adding chars using strcpy_s() function
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, actual_acc.Username.c_str());
	strcat_s(temp, sizeof temp, "'");
	static std::string temp1 = temp;// this is must static because 
	const char *temp3 = temp1.c_str();// this after function end is deleting a string 
	return temp3;
}
void Menu::get_name_surname()
{
	mysql_query(mysql,make_query_name());
	MYSQL_RES *idquery = mysql_store_result(mysql);
	MYSQL_ROW record = mysql_fetch_row(idquery);
	actual_acc.Name = record[0];
}