#include "Menu.h"
#undef max
void Menu::display()
{
	int option = 0;
	system("cls");
	set_data();
	std::cout << "Welcome " << actual_acc.Name << std::endl;
	while (log == false)
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
void Menu::set_data()
{

	mysql_query(&Databasecontroller::mysql, Databasecontroller::query("SELECT imie FROM bank.dane_konto AS dn INNER JOIN bank.accounts acc ON dn.id_konta=acc.id WHERE login = " 
		+ Databasecontroller::quote + actual_acc.Username + Databasecontroller::quote));
	MYSQL_RES *idquery = mysql_store_result(&Databasecontroller::mysql);
	MYSQL_ROW record = mysql_fetch_row(idquery);
	actual_acc.Name = record[0];
	/*****************************************/
	mysql_query(&Databasecontroller::mysql, Databasecontroller::query("SELECT nazwisko FROM bank.dane_konto AS dn INNER JOIN bank.accounts acc ON dn.id_konta=acc.id WHERE login = "
		+ Databasecontroller::quote + actual_acc.Username + Databasecontroller::quote));
	idquery = mysql_store_result(&Databasecontroller::mysql);
	record = mysql_fetch_row(idquery);
	actual_acc.Surname = record[0];
	/*****************************************/
	mysql_query(&Databasecontroller::mysql, Databasecontroller::query("SELECT stan FROM bank.accounts_v WHERE login = "
		+ Databasecontroller::quote + actual_acc.Username + Databasecontroller::quote));
	idquery = mysql_store_result(&Databasecontroller::mysql);
	record = mysql_fetch_row(idquery);
	actual_acc.cash = record[0];
	/****************************************/
	actual_acc.date.clear();// refreshing 
	mysql_query(&Databasecontroller::mysql, Databasecontroller::query("SELECT data from bank.dates as dt INNER JOIN bank.accounts_v AS kon ON dt.konto_id = kon.id_konta WHERE kon.login ="
		+ Databasecontroller::quote + actual_acc.Username + Databasecontroller::quote));
	idquery = mysql_store_result(&Databasecontroller::mysql);
	while ((record = mysql_fetch_row(idquery)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idquery); i++)
		{
			actual_acc.date.push_back(record[i]);//setting dates from database
		}
	}
	/******************************************/
	mysql_query(&Databasecontroller::mysql, Databasecontroller::query("SELECT Numer_rachunku FROM bank.accounts_v WHERE login = "
		+ Databasecontroller::quote + actual_acc.Username + Databasecontroller::quote));
	idquery = mysql_store_result(&Databasecontroller::mysql);
	record = mysql_fetch_row(idquery);
	actual_acc.bill = record[0];
	/******************************************/
	mysql_query(&Databasecontroller::mysql, Databasecontroller::query("SELECT id_konta FROM bank.accounts_v WHERE login = "
		+ Databasecontroller::quote + actual_acc.Username + Databasecontroller::quote));
	idquery = mysql_store_result(&Databasecontroller::mysql);
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
		mysql_close(&Databasecontroller::mysql);
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