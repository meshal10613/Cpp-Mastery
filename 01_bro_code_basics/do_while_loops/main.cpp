#include<iostream>
using namespace std;

int main(){
    //? do-while loop executes code once then checks condition
    int number = 0;

    do{
        cout << number << endl;
        number++;
    }while(number <= 10);

    return 0;
}