#include <iostream>
using namespace std;

int main()
{
	//? foreach look is a loop that eases traversal over an iterable data set
	char grades[] = {'A', 'B', 'C', 'D'};
	for(char grade : grades){
		cout << grade << endl;
	}

	return 0;
}