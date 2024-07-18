#include <iostream>
#include "String.h"

using namespace std;

int main()
{
	String greeting("Hello, World!");
	greeting.WriteToConsole();
	cout << '\n';


	// Length Function
	cout << "Length Function: Character count is, " << greeting.Length() << '\n';

	// CharacterAt Function
	cout << "CharacterAt Function: Your character is, " << greeting.CharacterAt(4) << '\n';

	// EqualTo Function
	if (greeting.EqualTo("Hello, World!"))
	{
		cout << "EqualTo Function: True" << '\n';
	}
	else
	{
		cout << "EqualTo Function: False" << '\n';
	}

	// Append Function
	String appended(greeting);
	appended.Append(String(" - Appended"));
	cout << "Append Function: " << appended.CStr() << '\n';

	// Prepend Function
	String prepended(greeting);
	prepended.Prepend(String("Prepended - "));
	cout << "Prepend Function: " << prepended.CStr() << '\n';

	// ToLower Function
	String lowercased(greeting);
	lowercased.ToLower();
	cout << "ToLower Function: " << lowercased.CStr() << '\n';

	// ToUpper Function
	String uppercased(greeting);
	uppercased.ToUpper();
	cout << "ToUpper Function: " << uppercased.CStr() << '\n';

	// Find Function


	// Replace Function

	// ReadFromConsole Function

	// WriteToConsole Function


		return 0;



}