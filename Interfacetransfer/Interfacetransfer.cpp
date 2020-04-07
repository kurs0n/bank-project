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
	bool money = false;
	for (int i = 0; i < another_accounts.size(); i++)
	{
		if (Number_bill == another_accounts[i].another_bill)
		{
			if (stoi(cash_to_transact) <= stoi(acc.cash))
			{
				mysql_query(mysql, make_transactionminus());
				mysql_query(mysql, make_transactionplus());
				mysql_query(mysql, make_date());
				std::cout << "Transaction success" << std::endl;
				money = true;
				break;
			}
			else { std::cout << "You don't have enough money" << std::endl;
			money = true;
			break;
			}
		}
	}
	if (money == false)
	{
		std::cout << "Sorry but we haven't got this number of bill in our database" << std::endl;
	}
}
void Interfacetransfer::get_informations_about_customers()
{
	mysql_query(mysql, make_query_of_bills());
	std::vector<std::string> records_bills(0);
	std::vector<std::string> records_names(0);
	MYSQL_RES *idquery = mysql_store_result(mysql);
	MYSQL_ROW record;
	while ((record = mysql_fetch_row(idquery)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(idquery); i++)
		{
			another_accounts.push_back(temp_account());
			records_bills.push_back(record[i]);
		}
	}
	mysql_query(mysql, make_query_of_name_customers());
	idquery = mysql_store_result(mysql);
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
const char* Interfacetransfer::make_query_of_bills()
{
	char temp[150];
	strcpy_s(temp, sizeof temp, "SELECT Numer_rachunku FROM bank.accounts_v WHERE login != ");//adding chars using strcpy_s() function
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, acc.Username.c_str());
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, " ORDER BY id");
	static std::string temp1;
	temp1 = temp;
	const char *temp3 = temp1.c_str();
	return temp3;
}
const char* Interfacetransfer::make_query_of_name_customers()
{
	char temp[150];
	strcpy_s(temp, sizeof temp, "SELECT imie FROM bank.accounts_v WHERE login != ");//adding chars using strcpy_s() function
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, acc.Username.c_str());
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, " ORDER BY id");
	static std::string temp1;
	temp1 = temp;
	const char  *temp3 = temp1.c_str();
	return temp3;
}
const char* Interfacetransfer::make_transactionplus()
{
	char temp[150];
	static std::string name;
	strcpy_s(temp, sizeof temp, "UPDATE accounts_v SET stan = stan + ");
	strcat_s(temp, sizeof temp, cash_to_transact.c_str());
	strcat_s(temp, sizeof temp, " WHERE Numer_rachunku = ");
	strcat_s(temp, sizeof temp, Number_bill.c_str());
	strcat_s(temp, sizeof temp, " AND ");
	strcat_s(temp, sizeof temp, " imie = ");
	for (int i = 0; i < another_accounts.size(); i++)
	{
		if (Number_bill == another_accounts[i].another_bill)
		{
			name = another_accounts[i].name;
			break;
		}
	}
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, name.c_str());
	strcat_s(temp, sizeof temp, "'");
	static std::string temp1;
	temp1 = temp;
	const char *temp3 = temp1.c_str();
	return temp3;
}
const char* Interfacetransfer::make_transactionminus()
{
	char temp[150];
	strcpy_s(temp, sizeof temp, "UPDATE accounts_v SET stan = stan - ");
	strcat_s(temp, sizeof temp, cash_to_transact.c_str());
	strcat_s(temp, sizeof temp, " WHERE Numer_rachunku = ");
	strcat_s(temp, sizeof temp, acc.bill.c_str());
	strcat_s(temp, sizeof temp, " AND ");
	strcat_s(temp, sizeof temp, "imie = ");
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, acc.Name.c_str());
	strcat_s(temp, sizeof temp, "'");
	static std::string temp1;
	temp1 = temp;
	const char *temp3 = temp1.c_str();
	return temp3;
}
const char* Interfacetransfer::make_date()
{
	SYSTEMTIME st;//time 
	GetSystemTime(&st);
	static std::string day;
	static std::string month;
	static std::string year;
	day = std::to_string(st.wDay);
	month = std::to_string(st.wMonth);
	year = std::to_string(st.wYear);
	char temp[150];
	strcpy_s(temp, sizeof temp, "INSERT dates(konto_id,data) VALUES (");
	strcat_s(temp, sizeof temp, acc.account_id.c_str());
	strcat_s(temp, sizeof temp, ",");
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, year.c_str());
	strcat_s(temp, sizeof temp, ".");
	strcat_s(temp, sizeof temp, month.c_str());
	strcat_s(temp, sizeof temp, ".");
	strcat_s(temp, sizeof temp, day.c_str());
	strcat_s(temp, sizeof temp, "'");
	strcat_s(temp, sizeof temp, ")");
	static std::string temp1;
	temp1 = temp;
	const char *temp3 = temp1.c_str();
	return temp3;
}