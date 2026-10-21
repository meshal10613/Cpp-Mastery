#include <iostream>
#include <string>
using namespace std;

struct Car
{
	string model;
	int year;
	string color;
};

void printCar(Car &car);
void paintCar(Car &car, string color);

int main()
{
	Car car1;
	Car car2;

	car1.model = "BMW";
	car1.year = 2024;
	car1.color = "black";

	car2.model = "Audi";
	car2.year = 2004;
	car2.color = "red";

	paintCar(car2, "gold");

	printCar(car1);
	printCar(car2);

	return 0;
}

void printCar(Car &car)
{
	cout << car.model << endl;
	cout << car.year << endl;
	cout << car.color << endl;
}

void paintCar(Car &car, string color){
	car.color = color;
}