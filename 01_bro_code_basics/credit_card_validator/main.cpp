#include <iostream>
#include <algorithm>
using namespace std;

/**
 *? Luhn Algorithm
 *
 **1.Double every second digit from right to left. If doubled number is 2 digits, split them.
 **2. Add all single digits from step 1.
 **3. Add all odd numbered digits from right to left.
 **4. Sum results from steps 2 & 3
 **5. If step 4 is divisble by 10, # is valid
 */

// Visa - 4242 4242 4242 4242 - 12/30 - 123
// Mastercard - 5555 5555 5555 4444 - 12/30 - 123
// American Express - 3782 822463 10005 - 12 / 30 - 1234

int getDigit(const int number);
int sumOdd(const string cardNumber);
int sumEven(const string cardNumber);

int main()
{
	//? Credit Card Validator
	string cardNumber;
	int result = 0;

	cout << "Enter your credit card number: ";
	getline(cin >> ws, cardNumber);
	cardNumber.erase(remove(cardNumber.begin(), cardNumber.end(), ' '), cardNumber.end()); //? remove space from a string

	result = sumEven(cardNumber) + sumOdd(cardNumber);

	if (result % 10 == 0)
	{
		cout << cardNumber << " is valid!" << endl;
	}
	else
	{
		cout << cardNumber << " is not valid!" << endl;
	}

	return 0;
}

int getDigit(const int number)
{
	return number % 10 + (number / 10 % 10);
}

int sumOdd(const string cardNumber)
{
	int sum = 0;

	for (int i = cardNumber.size() - 1; i >= 0; i -= 2)
	{
		sum += cardNumber[i] - '0';
	}

	return sum;
}

int sumEven(const string cardNumber)
{
	int sum = 0;

	for (int i = cardNumber.size() - 2; i >= 0; i -= 2)
	{
		sum += getDigit((cardNumber[i] - '0') * 2);
	}

	return sum;
}