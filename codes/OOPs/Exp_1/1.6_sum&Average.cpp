#include <iostream>

int main() {

  int a,b,sum;
  float average;
  std::cout << "Please enter 2 numbers\n";

  //taking input
  std::cin>>a;
  std:: cin>>b;

  //calculation 
  sum = a + b;
  average = (a + b)/2;

  //printing the sum
  std::cout<<"Sum is " <<sum<<".\n";
  std::cout<<"Average is " <<average<<".";
  return 0;
}