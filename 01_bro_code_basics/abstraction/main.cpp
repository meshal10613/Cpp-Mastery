#include <iostream>
using namespace std;

class Stove
{
private:
	int temperature = 0;

public:
	Stove(int temperature)
	{
		setTemperature(temperature);
	}

	int getTemperature()
	{
		return temperature;
	}

	void setTemperature(int temperature)
	{
		if (temperature < 0)
		{
			this->temperature = 0;
		}
		else if (temperature >= 10)
		{
			this->temperature = 10;
		}
		else
		{
			this->temperature = temperature;
		}
	}
};

int main()
{
	//? Abstarction is hiding unnecessary data from outside a class
	//* getter is a function that makes a private attribute READABLE
	//* setter is a function that makes a private attribute WRITEABLE
	Stove stove1(1000);

	cout << stove1.getTemperature();

	return 0;
}