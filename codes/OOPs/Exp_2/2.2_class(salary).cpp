#include <iostream>
#include <string>
using namespace std;

class employee{
  string first_name, last_name;;
  int salary;
  int annual_income;

  public:
  void get(string,string,int);
  void set();
  void calculate();
};

void employee::get(string first, string last, int amount){
  first_name = first;
  last_name = last;
  salary= amount;
}

void employee::set(){
  cout<<"\nFirst Name: "<<first_name<<"\nLast Name: "<<last_name<<"\nMonthly Salary: "<<salary<<endl;
  cout<<"\nAnnual Income: "<<annual_income;
}


void employee::calculate(){
  annual_income = salary * 12;
}

int main() {
  
  employee e;
  string first, last;
  int amount;

  cout<<"\nEnter First Name:";
  cin>>first;

  cout<<"\nEnter Last Name: ";
  cin>>last;

  cout<<"\nEnter Monthly Salary: ";
  cin>>amount;

  e.get(first, last, amount);

  e.calculate();

  e.set();

}