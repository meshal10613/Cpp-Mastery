#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	int random_num = (rand() % 5) + 1;

	switch (random_num)
	{
	case 1:
		cout << "1. You win a PS5";
		break;
	case 2:
		cout << "2. You win GTA VI";
		break;
	case 3:
		cout << "3. You win a Grapics Card";
		break;
	case 4:
		cout << "4. You win 1000Tk";
		break;
	case 5:
		cout << "5. You win a Xbox Series X";
		break;
	}

	return 0;
}