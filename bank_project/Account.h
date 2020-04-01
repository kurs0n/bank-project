#pragma once
#include <string>
#include <iostream>
struct Account {
	std::string Username;
	std::string Password;
	std::string Name;
	std::string Surname;
	Account();
    //std::ostream& operator<<(std::ostream& os, Account &acc);
};