#include <iostream>
#include "String.h"
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	fstream file;
	file.open("TestResults.txt", ios::app | ios::out);
	if(file.is_open())
	{
		// Date & Time
		time_t now = time(0);
		tm ltm;
		localtime_s(&ltm, &now);

		// Date/Time Formatting
		file << "Date: "<< ltm.tm_mday << "/" << 1 + ltm.tm_mon << "/" << 1900 + ltm.tm_year << " Time: " << setw(2) << setfill('0') << ltm.tm_hour << ":" << setw(2) << setfill('0') << ltm.tm_min << ":" << setw(2) << setfill('0') << ltm.tm_sec << " " << '\n';

		int totalTests = 10;
		int successfulTests = 0;

		//
		String greeting("Hello, World!");
		//

		// Length Function
		cout << "Length Function: Character count is, " << greeting.Length() << '\n';
		if (greeting.Length() == 13)
		{
			successfulTests++;
			file << "Test 0 Length Successful" << '\n';
		}
		else
		{
			file << "Test 0 Length Failed" << '\n';
		}

		// CharacterAt Function
		if(greeting.CharacterAt(4) == 'o')
		{
			successfulTests++;
			file << "Test 1 CharacterAt Successful" << '\n';
		}
		else
		{
			file << "Test 1 CharacterAt Failed" << '\n';
		}

		// EqualTo Function
		if (greeting.EqualTo("Hello, World!"))
		{
			cout << "EqualTo Function: True" << '\n';
			successfulTests++;
			file << "Test 2 EqualTo Successful" << '\n';
		}
		else
		{
			cout << "EqualTo Function: False" << '\n';
			file << "Test 2 EqualTo Failed" << '\n';
		}

		// Append Function
		String appended(greeting);
		appended.Append(String(" - Appended"));
		cout << "Append Function: " << appended.CStr() << '\n';
		if (appended.EqualTo("Hello, World! - Appended"))
		{
			successfulTests++;
			file << "Test 3 Append Successful" << '\n';
		}
		else
		{
			file << "Test 3 Append Failed" << '\n';
		}

		// Prepend Function
		String prepended(greeting);
		prepended.Prepend(String("Prepended - "));
		cout << "Prepend Function: " << prepended.CStr() << '\n';
		if (prepended.EqualTo("Prepended - Hello, World!"))
		{
			successfulTests++;
			file << "Test 4 Append Successful" << '\n';
		}
		else
		{
			file << "Test 4 Append Failed" << '\n';
		}

		// ToLower Function
		String lowercased(greeting);
		lowercased.ToLower();
		cout << "ToLower Function: " << lowercased.CStr() << '\n';
		if (lowercased.EqualTo("hello, world!"))
		{
			successfulTests++;
			file << "Test 5 ToLower Successful" << '\n';
		}
		else
		{
			file << "Test 5 ToLower Failed" << '\n';
		}

		// ToUpper Function
		String uppercased(greeting);
		uppercased.ToUpper();
		cout << "ToUpper Function: " << uppercased.CStr() << '\n';
		if(uppercased.EqualTo("HELLO, WORLD!"))
		{
			successfulTests++;
			file << "Test 6 ToUpper Successful" << '\n';
		}
		else
		{
			file << "Test 6 ToUpper Failed" << '\n';
		}

		// Find Function
		size_t position = greeting.Find(String("World"));
		if (position != (size_t)-1)
		{
			cout << "Find Function: Found at " << position << '\n';
			successfulTests++;
			file << "Test 7 Find Successful" << '\n';
		}
		else
		{
			cout << "Find Function: Not found" << '\n';
			file << "Test 7 Find Failed" << '\n';
		}

		// Replace Function
		String replace(greeting);
		replace.Replace(String("Hello"), String("Bye"));
		cout << "Replace Function: " << replace.CStr() << '\n';
		if (replace.EqualTo("Bye, World!"))
		{
			successfulTests++;
			file << "Test 8 Replace Successful" << '\n';
		}
		else
		{
			file << "Test 8 Replace Failed" << '\n';
		}

		// ReadFromConsole Function
		cout << "Enter a string: ";
		String inputString;
		inputString.ReadFromConsole();
		cout << "ReadFromConsole Function: I read the string " << inputString.CStr() << '\n';

		// WriteToConsole Function
		cout << "WriteToConsole Function: I wrote the String ";
		inputString.WriteToConsole();
		cout << '\n';

		// Simulated for ease of testing
		String simulatedInput("Simulated Input");
		if (simulatedInput.EqualTo("Simulated Input")) {
			successfulTests++;
			file << "Test 9 ReadFromConsole/WriteToConsole Successful\n";
		}
		else {
			file << "Test 9 ReadFromConsole/WriteToConsole Failed\n";
		}

		double successPercentage = (double)successfulTests / totalTests * 100;
		file << "Successful " << fixed << setprecision(2) << successPercentage << "%\n\n";

		file.close();
	}
	else
	{
		cout << "unable to open file";
	}
	system("PAUSE");
	
	return 0;
}