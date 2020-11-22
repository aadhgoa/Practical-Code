#include <iostream>
#include<iomanip>
using namespace std;

class fraction{
  float num, den;
  

  public:
  fraction(){
    cout<<"Enter the numbers: ";
    cin>>num>>den;
  }

  fraction(int x, int y);

  fraction(fraction &f1){
    num = f1.num;
    den = f1.den;
  }

  void display();

  void eval_function();

  friend void display(fraction x);
};

fraction :: fraction(int x, int y){
  num = x;
  den = y;
}

void fraction::eval_function(){
  float result = 0;
  result = num/den;

  cout<<setprecision(3)<<"\nThe value of the fraction is = "<<result<<endl;
}

void display(fraction x){
  cout<<"The fraction is (Numerator/Denominator): "<<x.num<<"/"<<x.den;
  
}

int main() {

  fraction f1; 
  cout<<"\nUsing Default Constructor."<<endl;
  
  display(f1);
  f1.eval_function();

  cout<<"\nUsing Parametric Constructor."<<endl;
  fraction f2(16, 3);
  
  display(f2);
  f2.eval_function();

  cout<<"\nUsing Copy Constructor."<<endl;
  fraction f3(f1);
  
  display(f3);
  f3.eval_function();

  cout<<"\nUsing Copy Constructor."<<endl;
  fraction f4 = f2;
  
  display(f4);
  f4.eval_function();
}