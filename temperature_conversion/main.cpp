#include<iostream>
using namespace std;

int main(){
	double temp;
	char unit;

	cout << "******* Temperature Conversion *******" << endl;
	cout << "F = Farenheit" << endl;
	cout << "C = Celsius" << endl << endl;
	cout << "What unit would you like to convert to: ";
	cin >> unit;

	if(unit == 'F' || unit == 'f')
	{
		cout << "Enter the temperature in Celsius: ";
		cin >> temp;
		temp = (temp * 9.0/5.0) + 32;
		cout << "Temperature in Fahrenheit: " << temp << endl;
	}
	else if(unit == 'C' || unit == 'c')
	{
		cout << "Enter the temperature in Fahrenheit: ";
		cin >> temp;
		temp = (temp - 32) * 5.0/9.0;
		cout << "Temperature in Celsius: " << temp << endl;
	}
	else
	{
		cout << "Invalid unit" << endl;
	}

	cout << endl << "**************************************";

	return 0;
}