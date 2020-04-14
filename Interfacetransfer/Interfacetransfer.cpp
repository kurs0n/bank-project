#include "Interfacetransfer.h"
void Interfacetransfer::display()
{
	std::cout << "Welcome " << acc.Name << std::endl;
	std::cout << "Who would you like to make a transaction with ? " << std::endl;
	std::cout << "Type Number: "; std::cin >> Number_bill;
	std::cout << "Type cash to transact: "; std::cin >> cash_to_transact;
	get_informations_about_customers();
}
void Interfacetransfer::do_transfer()
{
	bool money = false;// var which checking if you have enough money to transact in account already loggeed into the system.
	for (int i = 0; i < another_accounts.size(); i++)
	{
		if (Number_bill == another_accounts[i].another_bill)// checks if the number of bill is correct with this accounts which is in database.
		{
			mysql_query(&Databasecontroller::mysql, Databasecontroller::query("UPDATE accounts_v SET stan = stan - "
				+ cash_to_transact +  " WHERE Numer_rachunku = "+ acc.bill + " AND imie = " + Databasecontroller::quote + acc.Name + Databasecontroller::quote));
			mysql_query(&Databasecontroller::mysql, Databasecontroller::query("UPDATE accounts_v SET stan = stan + "
				+ cash_to_transact + " WHERE Numer_rachunku = "+ Number_bill + " AND imie = " + Databasecontroller::quote + get_name() + Databasecontroller::quote));
			mysql_query(&Databasecontroller::mysql, Databasecontroller::query("INSERT dates(konto_id,data) VALUES (" + acc.account_id + "," + Databasecontroller::quote
				+ get_date()+Databasecontroller::quote+")"));
				std::cout << "Transaction success" << std::endl;
				money = true;
				break;
		}
		else { std::cout << "You don't have enough money" << std::endl;
		money = true;// this is tricky.
		break;
		}
	}
	if (money == false)
	{
		std::cout << "Sorry but we haven't got this number of bill in our database" << std::endl;
	}
}

void Interfacetransfer::get_informations_about_customers()
{
	mysql_query(&Databasecontroller::mysql, Databasecontroller::query("SELECT Numer_rachunku FROM bank.accounts_v WHERE login != "
		+ Databasecontroller::quote + acc.Username + Databasecontroller::quote + "ORDER BY id"));
	std::vector<std::string> records_bills(0);
	std::vector<std::string> records_names(0);
	MYSQL_RES *idquery = mysql_store_result(&Databasecontroller::mysql);
	MYSQL_ROW record;
	while ((record = mysql_fetch_row(idquery)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idquery); i++)
		{
			another_accounts.push_back(temp_account());
			records_bills.push_back(record[i]);
		}
	}
	mysql_query(&Databasecontroller::mysql, Databasecontroller::query("SELECT imie FROM bank.accounts_v WHERE login != "
		+ Databasecontroller::quote + acc.Username + Databasecontroller::quote + "ORDER BY id"));
	idquery = mysql_store_result(&Databasecontroller::mysql);
	while ((record = mysql_fetch_row(idquery)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idquery); i++)
		{
			records_names.push_back(record[i]);
		}
	}
	for (int i = 0; i < another_accounts.size(); i++)
	{
		another_accounts[i].another_bill = records_bills[i];
		another_accounts[i].name = records_names[i];
	}
}
std::string Interfacetransfer::get_name()
{
		for (int i = 0; i < another_accounts.size(); i++)
		{
			if (Number_bill == another_accounts[i].another_bill)
			{
				return another_accounts[i].name;
			}
	    }
}
std::string Interfacetransfer::get_date()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	std::string day;
	std::string month;
	std::string year;
	day = std::to_string(st.wDay);
	month = std::to_string(st.wMonth);
	year = std::to_string(st.wYear);
	std::string temp = year + "." + month + "." + day;
	return temp;
}