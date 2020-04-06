#pragma once
#include <string>
#include <iostream>
#include <vector>
struct Account {
	std::string Username;
	std::string Password;
	std::string Name;
	std::string Surname;
	std::vector <std::string> date;
	std::string cash;
	std::string bill;
	std::string account_id;
	int how_many_dates;
	Account();
	Account &operator=(Account &acc);
    //std::ostream& operator<<(std::ostream& os, Account &acc); 
};