#include "Interfaceaboutme.h"
void Interfaceaboutme::display()
{
	std::cout << "Name: " << acc.Name << std::endl;
	std::cout << "Surname: " << acc.Surname << std::endl;
	std::cout << "Cash: " << acc.cash << std::endl;
	std::cout << "History of transfers: " << std::endl;
	for (int i = 0; i < acc.date.size(); i++)
	{
		std::cout << acc.date[i] << std::endl;
	}
}
Interfaceaboutme::Interfaceaboutme()
{
	acc.cash = "";
	for (int i = 0; i = acc.date.size(); i++)
	{
		acc.date[i] = "";
	}
	acc.Name = "";
	acc.Password = "";
	acc.Surname = "";
	acc.Username = "";
}
Interfaceaboutme &Interfaceaboutme::operator=(Account &s)
{
	acc.Name = s.Name;
	acc.Surname = s.Surname;
	acc.Username = s.Username;
	acc.Password = s.Password;
	acc.cash = s.cash;
	for (int i = 0; i = s.date.size(); i++)
	{
		acc.date.push_back(s.date[i]);
	}
}