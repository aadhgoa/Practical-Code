#include <iostream>

using namespace std;

class time{
  int min, hours;

  public:
  time(){
    hours = 3;
    min = 89;
  }

  void show(){
    cout<<"hours: "<<hours<<endl;
    cout<<"minutes: "<<min<<endl;
  }

  void operator++(){
    ++min;
    if(min >= 60){
      ++hours;
      min = min%60;
    }
  }
};

int main() {
  class time t;
  t.show();

  ++t;

  t.show();

  return 0;
}