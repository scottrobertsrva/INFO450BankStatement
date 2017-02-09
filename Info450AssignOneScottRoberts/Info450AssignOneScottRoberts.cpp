// Info450AssignOneScottRoberts.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

struct Transaction {
	float amount = 0.0;
};

int main()
{
	// Lists to hold each type of transaction
	list<Transaction> withdrawals;
	list<Transaction> deposits;
	list<Transaction> checks;

	// Variables for totals, balance and user inputs
	float withdrawalTotal = 0.0;
	float depositTotal = 0.0;
	float checkTotal = 0.0;
	float balance = 0.0;
	char userInput = 'a';
	float amountIn = 0.0;
	char lineIn[21];
	
	/*
	 *  I can get away with using only one Transaction since a copy
	 *  is what actually gets pushed on the list...
	 */

	Transaction newTransaction;

	// Get the initial balance
	cout << "Please enter the account balance:" << endl;
	cin >> balance;

	// Ask for transactions
	cout << "Enter Transactions: "<< endl << endl;

	// Ask for new transactions until user enters 'q' or 'Q'
	while (userInput != 'q' && userInput != 'Q') {
		
		// Get the next transaction
		cout << "(W)ithdrawal, (D)eposit, (C)heck, (Q)uit" << endl;

		// Read in the first 'word' entered and use the first letter as input. 
		// Just in case user enters more than one character....
		cin >> lineIn;
		userInput = lineIn[0];
		
		// Break while loop if user enters 'q' or 'Q'
		if (userInput == 'q' || userInput == 'Q') {
			break;
		}

		/* For each type of transaction.....
		 *
		 * Check transaction type and ask for the amount.
		 * Set transaction amount.
		 * Push the transaction to the appropriate list.
		 * Update the running total for that type of transaction.
		 */

		if (userInput == 'W' || userInput == 'w') {
			cout << "Enter amount for withdrawal -->  ";
			cin >> amountIn;
			newTransaction.amount = amountIn;
			withdrawals.push_back(newTransaction);
			withdrawalTotal += amountIn;
		}
		else if (userInput == 'D' || userInput == 'd') {
			cout << "Enter amount for deposit -->  ";
			cin >> amountIn;
			newTransaction.amount = amountIn;
			deposits.push_back(newTransaction);
			depositTotal += amountIn;
		}
		else if (userInput == 'C' || userInput == 'c') {
			cout << "Enter amount for check -->  ";
			cin >> amountIn;
			newTransaction.amount = amountIn;
			checks.push_back(newTransaction);
			checkTotal += amountIn;
		}
		else {
			cout << "Invalid entry" << endl;
		}
	}

	// Set precision (used with 'fixed') to format floats to 2 decimal places
	cout.precision(2);
	
	// Display Header
	cout << "  Transaction Summary:" << endl;
	cout << "  --------------------" << endl << endl;

	// Display Initial Balance
	cout << "    Initial Balance: " << fixed << balance << endl << endl;

	// Loop through withdrawals list and display each transaction amount
	cout << "    *Withdrawals: " << endl;
	for (list<Transaction>::iterator it = withdrawals.begin(); it != withdrawals.end(); ++it) {
		cout << right << setw(34) << fixed << it->amount << endl;
	}

	// Display Withdrawals total
	cout << right << setw(34) << "----------" << endl;
	cout << "    Total Withdrawals: " << right << setw(11) << fixed << withdrawalTotal << endl << endl;
	
	// Loop through deposits list and display each transaction amount
	cout << "    *Deposits: " << endl;
	for (list<Transaction>::iterator it = deposits.begin(); it != deposits.end(); ++it) {
		cout << right << setw(34) << fixed  << it->amount << endl;
	}

	// Display Deposits total
	cout << right << setw(34) << "----------" << endl;
	cout << "    Total Deposits: " << right << setw(14) << fixed << depositTotal << endl << endl;
	
	// Loop through checks list and display each transaction amount
	cout << "    *Checks: " << endl;
	for (list<Transaction>::iterator it = checks.begin(); it != checks.end(); ++it) {
		cout << right << setw(34) << fixed << it->amount << endl;
	}

	// Display Checks total
	cout << right << setw(34) << "----------" << endl;
	cout << "    Total Checks: " << right << setw(16) << fixed << checkTotal << endl << endl;
	
	// Calculate ending balance
	balance -= checkTotal;
	balance -= withdrawalTotal;
	balance += depositTotal;

	// Display Final Balance
	cout << "    Final Balance: " << right << setw(15) << fixed << balance << endl << endl;
    return 0;
}

