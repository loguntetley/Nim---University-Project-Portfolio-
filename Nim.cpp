#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void TokenPrint(vector<int>& Rows, int &CurRow)
{
	//This prints the board based on the given input of the variables.
	for (int RowPosition = 0; RowPosition < CurRow; RowPosition++)
	{
		cout << "Row" << "[" << RowPosition << "]     ";
		cout << Rows[RowPosition] << " Tokens " << endl;
	}
}

void Board(vector<int>& Rows, int &CurRow, int Tokens)
{
	cout << "How many Rows do you want" << endl;
	cin >> CurRow;

	//To stop numbers that would make the gaem to long or crash.
	if (CurRow == 0)
	{
		cout << "Cannot have no rows, your board is set to 5 row" << endl;
		CurRow = 5;
	}

	if (CurRow > 100)
	{
		cout << "For safty no game boards are allowed to be over 100" << endl << "your board will be set to 5" << endl;
		CurRow = 5;
	}

	//This puts the tokens in each of the rows for the user wit the .push_back(Tokens).
	for (int RowPosition = 0; RowPosition < CurRow; RowPosition++)
	{

		cout << "How many tokens in this row?" << endl;
		int Tokens;
		cin >> Tokens;

		if (Tokens == 0)
		{
			cout << "You cannot have 0 tokens, this row will be set to 5" << endl;
			Tokens = 5;
		}

		if (Tokens > 100)
		{
			cout << "For safty no game boards are allowed to be over 100 Tokens" << endl << "this row will be set to 5" << endl;
			Tokens = 5;
		}

		Rows.push_back(Tokens);
	}
	//This prints the board.
	TokenPrint(Rows, CurRow);
}

void Move(vector<int>& Rows, int& CurRow)
{

	int RowSelect;
	int Minustokens = 0;
	cout << "What row do you want to take tokens from" << endl;
	char input;
	cin >> input;

	if (input >= 48 && input <= 57)
	{
		//We know that input is a number.
		RowSelect = input - 48;
	}
	else
	{
		cout << "Please refrane from inputting charects or symbols" << endl;
		Move(Rows, CurRow);
		return;
	}

	cin.clear();
	cin.ignore(1);


	//This checks that the row selected is within the current boards range so it doesnt break.
	while (true)
	{
		if (RowSelect < 0 || RowSelect > CurRow)
		{
			cout << "Must be a row that is active on the board" << endl;
			cin >> RowSelect;
			cin.clear();
			cin.ignore(1);
		}

		//Asks the amount of tokens the player want to remove.
		if (RowSelect >= 0 && RowSelect <= CurRow)
		{
			cout << "How many tokens do you want to take from row " << RowSelect << endl;
			cin >> Minustokens;
			break;
		}

	}

	//Removes the tokens from the current row.
	if (Minustokens >= 1 && Minustokens <= Rows[RowSelect])
	{
		Rows[RowSelect] -= Minustokens;
	}


	//This deletes the row when zero tokens are left in it.
	if (Rows[RowSelect] <= 0 && RowSelect >= 0 && RowSelect <= CurRow)
	{
		Rows.erase(Rows.begin() + RowSelect);
		CurRow = Rows.size();
		Rows.resize(CurRow);
	}
	//Reprints the updated board
	system("CLS");
	TokenPrint(Rows, CurRow);

}

void WinCondition(vector<int>& Rows)
{
	if (Rows.empty())
	{
		cout << "You've have won the game" << endl;
		exit(true);
	}
}



int main()
{
	int CurRow = 0;
	int Tokens = 0;
	vector<int> Rows;

	Board(Rows, CurRow, Tokens);

	while (true)
	{

		Move(Rows, CurRow);
		WinCondition(Rows);

	}

}