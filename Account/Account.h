#pragma once
#include <string>
#include <iostream>
#include <vector>
/// <summary>
/// Account struct which represent account in database.
/// </summary>
struct Account {

	/// <summary>
	/// The username.
	/// </summary>
	std::string Username;

	/// <summary>
	/// The password.
	/// </summary>
	std::string Password;

	/// <summary>
	/// The name.
	/// </summary>
	std::string Name;

	/// <summary>
	/// The surname.
	/// </summary>
	std::string Surname;

	/// <summary>
	/// Store history of transaction.
	/// </summary>
	std::vector <std::string> date;

	/// <summary>
	/// The cash.
	/// </summary>
	std::string cash;

	/// <summary>
	/// Unique bill to make transaction with this account. 
	/// </summary>
	std::string bill;

	/// <summary>
	/// This is unique id which is needed to specify exactly account.
	/// </summary>
	std::string account_id;

	/// <summary>
	/// Stores how many dates is in date.
	/// </summary>
	int how_many_dates;

	Account();

	/// <summary>
	/// Operator=s the specified acc.
	/// </summary>
	/// <param name="acc">The acc.</param>
	/// <returns> Accounts in case of multiple equations. </returns>
	Account &operator=(const Account &acc);

	/// <summary>
	/// Resets this instance to NULL.
	/// </summary>
	void reset();
    //std::ostream& operator<<(std::ostream& os, Account &acc); 
};