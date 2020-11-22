#include <iostream>
using namespace std;

class shape{
  protected:
  int base, height;

  public:
  void set_data(int num1, int num2){
    base = num1;
    height = num2;
  }

  virtual int area(){
    return 0;
  }
};

class Rectangle: public shape{
  public:
  int area(){
    return (base * height);
  }
};

class Triangle: public shape{
  public:
  int area(){
    return ((base*height)/2);
  }
};

int main() {

  int num1, num2;
  shape *rptr;
  shape *tptr;

  Rectangle Rect;
  Triangle Tria;

  rptr = &Rect;
  tptr = &Tria;

  cout<<"Enter the 2 sides of Rectangle: ";
  cin>>num1>>num2;

  rptr->set_data(num1, num2);
  cout<<"Area is Rectangle: "<<rptr->area()<<endl;

  cout<<"Enter the 2 sides of Triangle: ";
  cin>>num1>>num2;
  
  tptr->set_data(num1, num2);
  cout<<"Area is Triangle: "<<tptr->area()<<endl;
}