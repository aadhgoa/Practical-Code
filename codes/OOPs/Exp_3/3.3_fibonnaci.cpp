#include <iostream>
using namespace std;


int main() {
  int n1 = 0, n2 = 1, n3, counter, number;

  cout << "Enter the number of elements: ";
  cin>>number;

  cout<< n1 <<" "<< n2 << " ";

  for(counter = 2; counter < number; ++counter){
    n3 = n1 + n2;
    cout << n3 << " ";
    n1 = n2;
    n2 = n3;
  }

  return 0;
}