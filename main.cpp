#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#pragma warning( disable : 4996) // chtob ne rugalsa na freopen;
#pragma warning( disable : 6031) // chtob ne podcherkival freopen;

//10) Сформировать новую строку, заменив в исходной строке все
//вхождения одного заданного символа на другой заданный символ.

char* functionC(char* destination, int size, const char* source, char symbolReplace, char symbolPaste);
using std::string;
string functionString(string& source, char symbolReplace, char symbolPaste);
int getValue();

int main()
{
	{	//C-type 

	freopen("input.txt", "r", stdin);
	int size;
	size = getValue();
	size++;
	char symbolReplace;
	char symbolPaste;
	char* destination = new char[size];
	char* source = new char[size];
	getc(stdin);
	gets_s(source, size);
	symbolReplace = getValue();
	symbolPaste = getValue();
	destination = functionC(destination, size, source, symbolReplace, symbolPaste);
	fclose(stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 0; i < size - 1; i++)
	{
		std::cout << destination[i];
	}
	fclose(stdout);
}
	
	{	//String

		string sourceStr;
		string answer;
		char symbolReplaceStr;
		char symbolPasteStr;
		freopen("inputString.txt", "r", stdin);
		std::getline(std::cin, sourceStr);
		symbolReplace = getValue();
		symbolPaste = getValue();
		answer = functionString(sourceStr, symbolReplaceStr, symbolPasteStr);
		fclose(stdin);
		freopen("outputString.txt", "w", stdout);
		std::cout << answer << '\n';
		fclose(stdout);
	}
}

int getValue()
{
	int a;
	std::cin >> a;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Oops, that input is invalid.  Please try again.\n";
	}
	else
	{
		std::cin.ignore(32767, '\n');
		return a;
	}
}

string functionString(string& source, char symbolReplace, char symbolPaste)
{
	string answer;
	for (int i = 0; i < source.size(); i++)
	{
		if (source[i] == symbolReplace)
		{
			answer += symbolPaste;
		}
		else
		{
			answer += source[i];
		}
	}

	return answer;
}

char* functionC(char* destination, int size, const char* source, char symbolReplace, char symbolPaste)
{
	for (int i = 0; i < size; i++)
	{
		if (source[i] == symbolReplace)
		{
			destination[i] = symbolPaste;
		}
		else
		{
			destination[i] = source[i];
		}
	}
	return destination;
}
