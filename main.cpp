#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#pragma warning( disable : 4996) // chtob ne rugalsa na freopen;
#pragma warning( disable : 6031) // chtob ne podcherkival freopen;

//10) —формировать новую строку, заменив в исходной строке все 
//вхождени€ одного заданного символа на другой заданный символ.

using std::string;

char* functionC(char* destination, int size, const char* source, char symbolReplace,char symbolPaste)
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

int main()
{
	{	//C-type 

	freopen("input.txt", "r", stdin);
	int size;
	std::cin >> size;
	char symbolReplace;
	char symbolPaste;
	char* destination = new char[size];
	size++;
	char* source = new char[size];
	getc(stdin);
	gets_s(source, size);
	std::cin >> symbolReplace;
	std::cin >> symbolPaste;
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
		std::cin >> symbolReplaceStr;
		std::cin >> symbolPasteStr;
		answer = functionString(sourceStr, symbolReplaceStr, symbolPasteStr);
		fclose(stdin);
		freopen("outputString.txt", "w", stdout);
		std::cout << answer << '\n';
		fclose(stdout);
	}
}