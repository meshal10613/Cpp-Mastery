#include <iostream>
using namespace std;

enum Day
{
	sunday = 0,
	monday = 1,
	tuesday = 2,
	wednesday = 3,
	thursday = 4,
	friday = 5,
	saturday = 6
};

int main()
{
	//? enum is a user-defined data type that consists of paired named-integer constants. Great if you have a set of potential options
	Day today = sunday;

	switch (today)
	{
	case 0:
		cout << "It's Sunday!\n";
		break;

	case 1:
		cout << "It's Monday!\n";
		break;

	case 2:
		cout << "It's Tuesday!\n";
		break;

	case 3:
		cout << "It's Wednesday!\n";
		break;

	case 4:
		cout << "It's Thursday!\n";
		break;

	case 5:
		cout << "It's Friday!\n";
		break;

	case 6:
		cout << "It's Saturday!\n";
		break;
	}

	return 0;
}