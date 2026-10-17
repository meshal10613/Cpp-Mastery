#include<iostream>
using namespace std;

int main(){
    //? While loop executes code as long as condition is true
    string name;

    while(name.empty()){
        cout << "Enter your name: ";
        getline(cin, name);
    }

    cout << "Hello, " << name << endl;

    return 0;
}