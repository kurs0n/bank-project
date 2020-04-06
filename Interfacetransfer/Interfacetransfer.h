#pragma once
#include "..\Underinterfacebase\Underinterfacebase.h"
#include <Windows.h>
#include <WinBase.h>
class Interfacetransfer : public Underinterfacebase {
public:
	MYSQL *mysql;
	void display();// displaying this interface
	void do_transfer(); // do transfer cash 
	Interfacetransfer() : Underinterfacebase()
	{
		;
	}
	struct temp_account {//small struct only for this function because if you want to make query only with number_of_bill, that strange things are happening
		std::string another_bill;
		std::string name;
		temp_account()
		{
			another_bill = "";
			name = "";
		}
	};
private:
	void get_informations_about_customers(); // get informations about other customers without account which already logged into the system 
	const char* make_query_of_bills();
	const char* make_query_of_name_customers();
	const char* make_transactionminus();
	const char* make_transactionplus();
	const char* make_date();
	std::string Number_bill;//number which are user type 
	std::string cash_to_transact;//cash which are user want to give ;P 
	std::vector<temp_account> another_accounts;// accounts which are in database without account already logged into system 
};