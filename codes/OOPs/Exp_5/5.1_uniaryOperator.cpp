#include <iostream>

using namespace std;

class abc{
  int m, n;
  public:
  abc(){
    cout<<"Enter your numbers: ";
    cin>>m>>n;
  }

  void show(){
    cout<<"m: "<<m<<endl;
    cout<<"n: "<<n<<endl;
  }

  void operator-(){
    m = -m;
    n = -n;
  }
};

int main() {
  abc x;
  x.show();
  -x;
  x.show();
}