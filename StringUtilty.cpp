#include <iostream>
#include "String.h"

using namespace std;

int main()
{

	// CStr Function
	String emptyString;
	cout << "CStr: " << emptyString.CStr() << '\n';

	//
	String greeting("Hello, World!");
	greeting.WriteToConsole();
	cout << '\n';
	//

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
	size_t position = greeting.Find(String("World"));
	if (position != (size_t)-1)
	{
		cout << "Find Function: Found at " << position << '\n';
	}
	else
	{
		cout << "Find Function: Not found" << '\n';
	}

	// Replace Function
	String replace(greeting);
	replace.Replace(String("Hello"), String("Bye"));
	cout << "Replace Function: " << replace.CStr() << '\n';

	// ReadFromConsole Function
	cout << "Enter a string: ";
    String inputString;
    inputString.ReadFromConsole();
    cout << "ReadFromConsole Function: " << inputString.CStr() << '\n';

	// WriteToConsole Function
	cout << "WriteToConsole Function: ";
    inputString.WriteToConsole();
    cout << '\n';

	return 0;

	/*
    // Operator == Function
    if (greeting == String("Hello, World!"))
    {
        cout << "Operator == Function: True" << '\n';
    }
    else
    {
        cout << "Operator == Function: False" << '\n';
    }

    // Operator [] Function
    cout << "Operator [] Function: Character at position 4 is " << greeting[4] << '\n';

    // Operator = Function
    String assignment;
    assignment = greeting;
    cout << "Operator = Function: " << assignment.CStr() << '\n';

    // Operator != Function
    if (greeting != String("Hello, Universe!"))
    {
        cout << "Operator != Function: True" << '\n';
    }
    else
    {
        cout << "Operator != Function: False" << '\n';
    }
	*/

}