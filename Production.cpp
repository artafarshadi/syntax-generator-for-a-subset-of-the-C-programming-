# syntax-generator-for-a-subset-of-the-C-programming-
syntax generator for a subset of the C++ programming 
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

// Master class
class Production
{
public:
	// since we do not know the size we make a string vector
	vector<string> LeftHandSide;
	string HeadString;
public:
	Production()
	{
		HeadString = "";
	}
	
	void Program()
	{
		//
		HeadString += "int main() \n{\n" + GetStatment();
	}
	string GetStatment()
	{
		//
		int MAX_SIZE = 5, Counter = 0, RandomResult;
		string Result = "";

		// 
		while (!LeftHandSide.empty())
		{
			RandomResult = rand() % 100 + 1;

			if (RandomResult <= 15 && Counter < MAX_SIZE)
			{
				Counter++;
				LeftHandSide.back() += randomStat();
				LeftHandSide.push_back("");
			}
			else
			{
				LeftHandSide.back() += randomStat();
			}
			Result += LeftHandSide.back();
			LeftHandSide.pop_back();
		}
		
		return Result;
	}
	string randomStat()
	{
		
		string value;
		int RandomIf = rand() % 100 + 1;

		
		if (RandomIf <= 10)
			value += Getcmpd_stat();
		if (RandomIf > 10 && RandomIf <= 20)
			value += Getif_stat();
		if (RandomIf > 20 && RandomIf <= 30)
			value += Getiter_Stat();
		if (RandomIf > 30 && RandomIf <= 65)
			value += GetAssgn_statement();
		if (RandomIf > 65 && RandomIf < 100)
			value += GetDecl_Statement();

		
		return value;
	}
	string Getcmpd_stat()
	{
		string value;
		
		value += GetStatment();

		
		return value;
	}
	string Getif_stat()
	{
		
		string VALUE;

		
		int RandomNumber = rand() % 100 + 1;

		if (RandomNumber < 10)
			VALUE += "if(" + getExp() + ")" + GetStatment();
		else if (RandomNumber > 10 && RandomNumber <= 25)
			VALUE += "if(" + getExp() + ")" + Getcmpd_stat();
		else if (RandomNumber > 25 && RandomNumber <= 40)
			VALUE += "if(" + getExp() + ")\n" + GetStatment() + " else\n  " + GetStatment();
		else if (RandomNumber > 40 && RandomNumber <= 65)
			VALUE += "if(" + getExp() + ")\n" + Getcmpd_stat() + " else\n  " + GetStatment();
		else if (RandomNumber < 65 && RandomNumber <= 80)
			VALUE += "if(" + getExp() + ")\n" + GetStatment() + " else\n " + Getcmpd_stat();
		else
			VALUE += "if(" + getExp() + ")\n" + getExp() + "else\n " + Getcmpd_stat();

		return VALUE;
	}
	string Getiter_Stat()
	{
		string value;
		int random = rand() % 100 + 1;

		if (random <= 70)
			value += "while(" + getExp() + ")\n" + GetStatment();
		else
			value += "while(" + getExp() + ")\n" + Getcmpd_stat();

		return value;
	}
	string GetAssgn_statement()
	{
		// Define our local string.
		string value;
		// Then start adding the syntactical things to it.
		value += GetChar();
		value += string(" = ");
		value += getExp() + ";";
		return value;
	}
	string GetDecl_Statement()
	{
		string number, value;
		int random = rand() % 2;

		// if statements.
		if (random == 0)
		{
			value += getType();
			value += getDigits();
		}
		else
		{
			value += getType();
			value += GetAssgn_statement();
		}

		return value;
	}
	string getExp()
	{
		string value;
		int counter = 0, MAX_LIMIT = 5, RandomExp = rand() % 100 + 1;

		if (RandomExp <= 40 && counter < MAX_LIMIT)
		{
			value += getExp();
			value += GetOperations();
			value += getExp();
			counter++;
		}
		else if (RandomExp > 40 && RandomExp <= 70)
			value += getchar_seq();
		else
			value += getDigits();

		return value;
	}
	string getchar_seq()
	{
		int Num = 5;
		string value;

		// Add to the value a character.
		value = GetChar();

		for (int i = 0; i < Num; i++)
		{
			if ((rand() % 2) == 1)
			{
				value += GetChar();
			}
			else
			{
				value += getDigits();
			}
		}

		return value;
	}
	string GetChar()


	{   // I am not sure if this is a right way to do, but i wanted to minimize my code so i got help from STACKOVERFLOW website
		string LettersChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

		int RandomLetters = rand() % 50;
		string Results = "";
		Results += LettersChar[RandomLetters];
		return Results;
	}
	string getType()
	{
		string value;

		int RandomType = rand() % 2;

		if (RandomType == 1)
			value = " int ";
		else
			value = " double ";

		return value;
	}
	string GetOperations()
	{
		int RandomOperations = rand() % 4;
		string value;

		if (RandomOperations == 0)
			value = " + ";
		else if (RandomOperations == 1)
			value = " - ";
		else if (RandomOperations == 2)
			value = " * ";
		else
			value = " / ";

		return value;
	}
	string getDigits()
	{
		string value;

		// Do a random number from 0 - 9.
		value = static_cast<char>((rand() % 9) + '0');
		//		value = static_cast<char>((rand() % 9) + 48); 48 is 0 


		return value;
	}
	string getdigit_seq()
	{
		int length = rand() % 10;
		length++;
		string ValueDigits;

		for (int i = 0; i < length; i++)
			ValueDigits += getDigits();

		return ValueDigits;
	}
	string Return()
	{
		return "\nreturn 0;\n}";
	}
	void PrintVector()
	{
		for (int i = 0; i < LeftHandSide.size(); i++)
			cout << LeftHandSide[i] << "\n";
	}
	string HeaddString()
	{
		return HeadString;
	}
};

// Define the main function.
int main()
{
	Production RandomCode;
	// Generate a random number.
	int counter = 0;
	// Declare a file name.
	fstream myFile;
	myFile.open("InPut.txt", ios::out);

	srand(time(NULL));

	system("cls");
	RandomCode.Program();
	cout << RandomCode.HeaddString() << endl;
	myFile << RandomCode.HeaddString();

	// Now go through this a few times.
	while (counter < 7)
	{
		int x = rand() % 7 + 1;
		counter++;
		if (x == 1)
		{
			cout << RandomCode.Getif_stat() << endl;
			myFile << RandomCode.Getif_stat() << endl;
		}
		if (x == 2)
		{
			cout << RandomCode.Getiter_Stat() << endl;
			myFile << RandomCode.Getiter_Stat() << endl;
		}
		if (x == 3)
		{
			cout << RandomCode.GetAssgn_statement() << endl;
			myFile << RandomCode.GetAssgn_statement() << endl;
		}
		if (x == 4)
		{
			cout << RandomCode.GetDecl_Statement() << endl;
			myFile << RandomCode.GetDecl_Statement() << endl;
		}
		if (x == 5)
		{
			cout << RandomCode.getType();
			cout << RandomCode.GetAssgn_statement() << endl;
		}
	}
	cout << RandomCode.Return();
	myFile << RandomCode.Return();


	cout << "\n\nPress any key to continue...";
	cin.get();

	myFile.close();

	return 0;
}
