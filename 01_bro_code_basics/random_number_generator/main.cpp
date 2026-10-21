#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int num = (rand() % 100) + 1; //? Random number between 1 to 100

	return 0;
}