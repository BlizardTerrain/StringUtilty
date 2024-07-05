#include <iostream>
#include "String.h"

int main()
{
	String greeting("Hello, World!");
	greeting.WriteToConsole();
	std::cout << std::endl;

	return 0;
}