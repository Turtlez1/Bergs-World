// Console App.cpp : Definles the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
label:
	string input, answer, yn, log, key = "5";
	ofstream outputFile;
	int count = 0, length;
	bool encrypt = true;
	cout << "Key #? \n";
	getline(cin, key);
	int key2 = std::stoi(key);
label2:
	cout << "Encrypt or decrypt? \n";
	getline(cin, answer);
	if (answer == "encrypt") 
	{
		encrypt = true;
		outputFile.open("C:\\Users\\kuhlja\\Desktop\\Stuff\\encryptedtext.txt", std::ios_base::app);
	}
	if (answer == "decrypt")
	{
		encrypt = false;
		outputFile.open("C:\\Users\\kuhlja\\Desktop\\Stuff\\decryptedtext.txt", std::ios_base::app);
	}
	cout << "Enter your phrase: \n";
	getline(cin, input);
	length = (int)input.length();
	for (count = 0; count < length; count++) 
	{
		if (encrypt == true) 
		{
			if (isalpha(input[count]))
			{
				input[count] = tolower(input[count]);
				for (int i = 0; i < key2; i++)
				{
					if (input[count] == 'z') 
						input[count] = 'a';
					else
						input[count]++; 
				}
			}
		}
		if (encrypt == false) 
		{
			if (isalpha(input[count]))
			{
				input[count] = tolower(input[count]);
				for (int i = 0; i < key2; i++)
				{
					if (input[count] == 'a')
						input[count] = 'z';
					else
						input[count]--;
				}
			}
		}
	} 
	cout << "Results: " << input << "\n" << "Would you like to log this text? \n";
	getline(cin, log);
	if (log == "yes" || log == "y") 
	{
		outputFile << "Key number: " << key << endl;
		outputFile << input << endl;
		outputFile << "----------------------------------------------------------------------------------------------- \n" << endl;
		outputFile.close();
		cout << "Log completed." << endl;
	}
	if (log == "no" || log == "n")
	{
		outputFile.close();
	}
	cout << "Decrypt/Encrypt something else? \n";
	getline(cin, yn);
	if (yn == "yes" || yn == "y")
	{
		goto label;
	}
	if (yn == "no" || yn == "n")
	{
		return 0;
	}
}