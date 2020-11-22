#include<iostream>

using namespace std;

int n = 0;

class box{
  int length, width, height;

  public:
  box(int a = 1, int b = 1, int c = 1){
    n += 1;

    cout<<"Constructor is called for " << n <<endl;
    length = a;
    width = b;
    height = c;
  }

  int volume(){
    return length*width*height;
  }

  ~box(){
    cout<<"Destructor is called for "<<n<<endl;
    n -= 1;
  }
};


int main(){
  {
    int i;
    box b1, b2(2), b3(4,2), b4(6,4,2);

    
    cout<<"\nThe volume of box 1 = "<<b1.volume()<<endl;


    cout<<"\nThe volume of box 2 = "<<b2.volume()<<endl;


    cout<<"\nThe volume of box 3 = "<<b3.volume()<<endl;


    cout<<"\nThe volume of box 4 = "<<b4.volume()<<endl<<endl;
    
  }

  {
    int length, width, height;


    cout<<"\nEnter length: ";
    cin>>length;

    cout<<"\nEnter width: ";
    cin>>width;

    cout<<"\nEnter height: ";
    cin>>height;

    box b5(length, width, height);

    cout<<"\nThe volume of box 5 = "<<b5.volume()<<endl<<endl;
  }

  cout<<endl<<"Sucessfully, reached the end.";
}