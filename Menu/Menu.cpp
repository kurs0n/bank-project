#include "Menu.h"
#undef max
void Menu::display()
{
	int option=0;
	system("cls");
	set_data();
	std::cout << "Welcome " << actual_acc.Name << std::endl;
	while (log == false )
	{
		set_data();//refreshing data 
		std::cout << "Choose option: " << std::endl;
		std::cout << "1. About me" << std::endl;
		std::cout << "2. Transaction" << std::endl;
		std::cout << "3. Log acc" << std::endl;
		std::cout << "4. Exit" << std::endl;
		std::cout << "Your choose: ";
		std::cin >> option;
		if (std::cin.fail())
		{
			std::cout << "Wrong choose!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Press any key to try again" << std::endl;
			_getch();
			system("cls");
		}
		else {
			go_to_interface(option);
		}
	}
}
const char *Menu::make_query_name()
{
    char temp[150];//this will be better 
	strcpy_s(temp, sizeof temp, "SELECT imie FROM bank.dane_konto AS dn INNER JOIN bank.accounts acc ON dn.id_konta=acc.id WHERE login = ");//adding chars using strcpy_s() function
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, actual_acc.Username.c_str());
	strcat_s(temp, sizeof temp, "'");
	static std::string temp1;//if you try to initialize there this temp1 will be only first variable which you initialize this is strange...
	temp1 = temp;// sooooo you must do this and everything will be fine 
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
	static std::string temp1;
	temp1 = temp;
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
	static std::string temp1;
	temp1 = temp;
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
	static std::string temp1;
	temp1 = temp;
	const char *temp3 = temp1.c_str();// this after function end is deleting a string 
	return temp3;
}
const char *Menu::make_query_bill()
{
	char temp[150];//this will be better	
	strcpy_s(temp, sizeof temp, "SELECT Numer_rachunku FROM bank.accounts_v WHERE login = ");
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, actual_acc.Username.c_str());
	strcat_s(temp, sizeof temp, "'");
	static std::string temp1;
	temp1 = temp;
	const char *temp3 = temp1.c_str();
	return temp3;
}
const char *Menu::make_query_accountid()
{
	char temp[150];
	strcpy_s(temp, sizeof temp, "SELECT id_konta FROM bank.accounts_v WHERE login = ");
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, actual_acc.Username.c_str());
	strcat_s(temp, sizeof temp, "'");
	static std::string temp1; 
	temp1 = temp;
	const char *temp3 = temp1.c_str();
	return temp3;
}
void Menu::set_data()
{

	mysql_query(mysql, make_query_name());//making queries
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
	actual_acc.cash = record[0];
	/****************************************/
	actual_acc.date.clear();// refreshing 
	mysql_query(mysql, make_query_date());
	idquery = mysql_store_result(mysql);
	while ((record = mysql_fetch_row(idquery)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idquery); i++)
		{
				actual_acc.date.push_back(record[i]);//setting dates from database
		}
	}
	/******************************************/
	mysql_query(mysql, make_query_bill());
	idquery = mysql_store_result(mysql);
	record = mysql_fetch_row(idquery);
	actual_acc.bill = record[0];
	/******************************************/
	mysql_query(mysql, make_query_accountid());
	idquery = mysql_store_result(mysql);
	record = mysql_fetch_row(idquery);
	actual_acc.account_id = record[0];
}
void Menu::go_to_interface(int op)
{
	switch (op)
	{
	  case 1:
	  {
		init_aboutmeinterface();
		transfer_data(about_me);
		about_me->display();
		delete about_me;
		std::cout << "Press any key to back..." << std::endl;
		must_click();
		break;
	  }
	 case 2:
	  {
		 system("cls");
		 init_transferinterface();
		 transfer_data(transfer);
		 transfer->display();
		 transfer->do_transfer();
		 delete transfer;
		 std::cout << "Press any key to back to the menu..." << std::endl;
		 must_click();
		break;
	  }
	  case 3:
	  {
		relog();
		std::cout << "Press any key to back to the Login interface" << std::endl;
		must_click();
		break;
	  }
	  case 4:
	  {
		  mysql_close(mysql);
		  std::cout << "Goodbye :)" << std::endl;
		  _getch();
		  exit(0);
	  }
	  default:
	  {
		  std::cout << "Wrong choose!" << std::endl;
		  std::cin.clear();
		  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		  std::cout << "Press any key to try again" << std::endl;
		  must_click();
		  break;
	  }
	}
}
void Menu::transfer_data(Underinterfacebase* underinterface)
{
	underinterface->acc = actual_acc;//transfer account from interface
}
void Menu::init_aboutmeinterface()
{
	about_me = new Interfaceaboutme();
}
void Menu::init_transferinterface()
{
	transfer = new Interfacetransfer();
	transfer->mysql = this->mysql;// seting mysql to transfer interface class 
}
void Menu::must_click()
{
	_getch();
	system("cls");
}
void Menu::relog()
{
	actual_acc.reset();
	log = true;
}