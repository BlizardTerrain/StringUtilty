#include "String.h"

#include <cctype>
#include <cstring> // for strlen & strcpy_s
#include <iostream>

using namespace std;

String::String()
{
	m_string = nullptr;
	m_length = 0;
}

String::String(const char* _str)
{
	m_length = strlen(_str);
	m_string = new char[m_length + 1];
	strcpy_s(m_string, m_length + 1, _str);
}

String::String(const String& _other)
{
	m_length = _other.m_length;
	m_string = new char[m_length + 1];
	strcpy_s(m_string, m_length + 1, _other.m_string);
}

String::~String()
{
	delete[] m_string;
}

//
//
//

// Returns an integer representing the count of characters up to the null termination character
size_t String::Length() const
{
	return strlen(m_string);
}

// Returns a char representing the character at the location. If index is less than 0 or greater than length, return '\0'
char& String::CharacterAt(size_t _index)
{
	if (_index < 0 || _index >= this->Length())
	{
		static char nullChar = '\0';
		return nullChar;
	}
	else
	{
		return m_string[_index];
	}
}

// Returns true if str contains the same characters.
bool String::EqualTo(const String& _other) const
{
	return strcmp(m_string, _other.m_string) == 0;
}

// Adds str to the end of the string
String& String::Append(const String& _str)
{
	size_t newLenth = m_length + _str.Length();
	char* temp = new char[newLenth + 1];
	strcpy_s(temp, newLenth + 1, m_string);
	strcat_s(temp, newLenth + 1, _str.m_string);
	delete[] m_string;
	m_string = temp;
	m_length = newLenth;
	return *this;
}

// Adds str to the beginning of the string
String& String::Prepend(const String& _str)
{
	size_t newLenth = m_length + _str.Length();
	char* temp = new char[newLenth + 1];
	strcpy_s(temp, newLenth + 1, _str.m_string);
	strcat_s(temp, newLenth + 1, m_string);
	delete[] m_string;
	m_string = temp;
	m_length = newLenth;
	return *this;
}

// Return the const char * that is useable with std::cout. eg: std::cout << str.cstr() << std::endl;
const char* String::CStr() const
{
	return m_string;
}

// Convert all characters to lowercase
String& String::ToLower()
{
	for (size_t i = 0; i < m_length; ++i)
	{
		m_string[i] = tolower(m_string[i]);
	}
	return *this;
}

// Convert all characters to uppercase
String& String::ToUpper()
{
	for (size_t i = 0; i < m_length; ++i)
	{
		m_string[i] = toupper(m_string[i]);
	}
	return *this;
}

// Returns the location of the findString. If not found, return -1
size_t String::Find(const String& _str)
{
	const char* found = strstr(m_string, _str.m_string);
	if (found != nullptr)
	{
		return found - m_string;
	}
	return -1;
}

// Returns the location of the strToFind. Beginning the search from startIndex. If not found, return -1
size_t String::Find(size_t _startIndex, const String& _str)
{
	if (_startIndex >= m_length)
		return -1;

	const char* found = strstr(m_string + _startIndex, _str.m_string);
	if (found != nullptr)
	{
		return found - m_string;
	}
	return -1;
}

// Replaces all occurrences of findString with replaceString
String& String::Replace(const String& _find, const String& _replace)
{
	size_t pos = Find(_find);
	while (pos != -1)
	{
		// replace at pos
		for (size_t i = pos; i < pos + _find.m_length; ++i)
		{
			m_string[i] = _replace.m_string[i - pos];
		}
		// continue searching from the end of the replacement
		pos = Find(pos + _replace.m_length, _find);
	}
	return *this;
}

// Wait for input in the console window and store the result
String& String::ReadFromConsole()
{
	char buffer[1024];
	cin.getline(buffer, 1024);
	delete[] m_string;
	m_length = strlen(buffer);
	m_string = new char[m_length + 1];
	strcpy_s(m_string, m_length + 1, buffer);
	return *this;
}

// Write the string to the console window.
String& String::WriteToConsole()
{
	cout << m_string;
	return *this;
}

// Returns true if lhs == rhs.
bool String::operator==(const String& _other)
{
	return strcmp(m_string, _other.m_string) == 0;
}

// Returns the character located at position n.
char& String::operator[](size_t _index)
{
	if (_index >= m_length)
	{
		static char nullChar = '\0';
		return nullChar;
	}
	return m_string[_index];
}

const char& String::operator[](size_t _index) const
{
	if (_index >= m_length)
	{
		static char nullChar = '\0';
		return nullChar;
	}
	return m_string[_index];
}

// Replaces the characters in lhs with the characters in rhs.
String& String::operator=(const String& _other)
{
	if (this != &_other)
	{
		delete[] m_string;
		m_length = _other.m_length;
		m_string = new char[m_length + 1];
		strcpy_s(m_string, m_length + 1, _other.m_string);
	}
	return *this;
}

// Returns true if this string comes before rhs in the alphabet.
bool String::operator!=(const String& _other)
{
	return strcmp(m_string, _other.m_string), 0;
}