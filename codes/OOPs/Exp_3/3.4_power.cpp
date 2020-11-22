#include <iostream>
using namespace std;

int power(int n1, int n2);

int main() {
  int base, a, result;

  cout << "Enter base number: ";
  cin>> base;

  do{
    cout<< "Enter power number (Positive only): ";
    cin>>a;
  }while(a < 0);

  cout << base << " raised to "<< a << " is " << power(base, a) << endl;

  return 0;
}

int power(int base, int a) 
{
    if (a != 0)
        return (base * power(base, a - 1));
    else
        return 1;
}

