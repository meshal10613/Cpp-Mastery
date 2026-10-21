#include<iostream>
using namespace std;

class Pizza{
	public:
		string topping1;
		string topping2;

	Pizza(){

	}

	Pizza(string topping1){
		this->topping1 = topping1;
	}

	Pizza(string topping1, string topping2){
		this->topping1 = topping1;
		this->topping2 = topping2;
	}
};

int main(){
	//? Overloaded Constructors are multiple constructors with same name but different parameters allows for varying arguments when instantiating an object
	Pizza pizza1;
	Pizza pizza2("pepperoni");
	Pizza pizza3("mashrooms", "pepperoni");

	cout << pizza2.topping2;

	return 0;
}