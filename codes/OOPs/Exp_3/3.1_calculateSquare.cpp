#include <iostream>
using namespace std;

int square (int num);
double  square (double  num);

int main() {
    int number_int;
    double number_double;

    cout << "Enter an integer: ";
    cin>> number_int;

    cout << "Enter an number: ";
    cin>> number_double;
    
    cout << "square of " << number_int << " = " << square(number_int )<< endl;
    cout << "square of " << number_double << " = " << square(number_double )<< endl;
    return 0;
}

int square (int num){
    return num * num;
}

double  square (double  num){
    return num * num;
}