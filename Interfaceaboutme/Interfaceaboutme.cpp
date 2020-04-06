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
