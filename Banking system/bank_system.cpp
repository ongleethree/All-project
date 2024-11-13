#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;


void showbalance(float balance);
float deposit(float balance);
float withdraw(float balance);

int choose = 0;
float balance = 0;

int main()
{
	while (choose != 4)
	{
		cout << "******************************" << "\r\n";

		cout << "Enter your choice " << "\r\n";

		cout << "******************************" << "\r\n";

		cout << "1. show Balance" << "\r\n";
		cout << "2.Deposit money" << "\r\n";
		cout << "3.Withdraw money" << "\r\n";
		cout << "4.EXIT" << "\r\n";

		cout << "your choice is = " << endl;
		cin >> choose;

		switch (choose)
		{
		case 1:
			showbalance(balance);
			break;
		case 2:
			balance += deposit(balance);
			showbalance(balance);
			break;
		case 3:
			balance -= withdraw(balance);
			showbalance(balance);
			break;
		case 4:
			cout << "Thank for using" << "\r\n";
			break;

		default:
			cout << "Your choose not match with system" << endl;

		}
	}
	return 0;

}

void showbalance(float balance)
{
	cout << "your current balance is = " << balance << "\r\n";
}


float deposit(float balance)
{
	float number = 0;
	cout << "Enter deposit number you wnat to = " << endl;
	number = choose;
	cin >> number;
	if (number > 0)
	{
		return number;
	}
	else
	{
		cout << "not valid amount" << "\r\n";
		return 0;
	}


}

float withdraw(float balance)
{
	float amount = 0;
	cout << "Enter withdraw number you wnat to = " << endl;
	amount = choose;
	cin >> amount;
	return amount;
}