#include <iostream>

using namespace std;

class box{
  int breath;
  int height;
  int width;
  float volume;

public:
  void getbhw(int, int, int );
  void setbhw();
  void calculate();
};

void box ::getbhw(int b, int h, int w){
  breath = b;
  height = h;
  width = w;
}

void box::setbhw(){
  
  cout<<"Length: "<<breath<<"\nHeight: "<<height<<"\nWidth:  "<<width<<endl;
  cout<<"Volume: "<<volume<<endl;
}

void box::calculate(){
  volume = breath * height * width;
}

int main(){
  box x;
  int b, h, w;

  cout<<"Enter the value for base and height: ";

  cin>> b>> h>> w;

  x.getbhw(b, h, w);
  x.calculate();
  x.setbhw();
}

