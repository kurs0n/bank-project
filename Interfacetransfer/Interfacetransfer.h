#pragma once
#include "..\Underinterfacebase\Underinterfacebase.h"
#include "..\Databasecontroller\Databasecontroller.h"
/// <summary>
/// Makes transfers.
/// </summary>
///<remarks>
///<para>Haves informations about cash.</para>
///<para>Makes dates and give it to account.</para>
///</remarks>
/// <seealso cref="Underinterfacebase" />
class Interfacetransfer : public Underinterfacebase {
public:

	/// <summary>
	/// Displays this interface.
	/// </summary>
	void display();

	/// <summary>
	/// Does the transfer.
	/// </summary>
	void do_transfer();

/// <summary>
/// Initializes a new instance of the <see cref="Interfacetransfer"/> class.
/// </summary>
	Interfacetransfer() : Underinterfacebase()
	{
		;
	}
	/// <summary>
	/// Temporary account.
	/// </summary>
	struct temp_account {//small struct only for this function because if you want to make query only with number_of_bill, that strange things are happening.
		std::string another_bill;
		std::string name;
		temp_account()
		{
			another_bill = "";
			name = "";
		}
	};
private:

	/// <summary>
	/// Gets the informations about customers.
	/// </summary>
	void get_informations_about_customers();

	/// <summary>
	/// Gets the name.
	/// </summary>
	/// <returns>Name.</returns>
	std::string get_name();

	/// <summary>
	/// Gets the date.
	/// </summary>
	/// <returns>Date.</returns>
	std::string get_date();

	/// <summary>
	/// The number bill.
	/// </summary>
	std::string Number_bill;

/// <summary>
/// The cash to transact which user want to give.
/// </summary>
	std::string cash_to_transact;

/// <summary>
/// Another accounts which are in database without account already logged into system.
/// </summary>
	std::vector<temp_account> another_accounts;
};