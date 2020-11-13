#include <iostream>
using namespace std;

int main(){

    const int SIZE = 10;
    char buffer1[SIZE];
    char buffer2[SIZE];
    char buffer3[SIZE];

    cout<<"Enter a sentence: ";
    cin>>buffer1;

    cout <<"\nThe string read with cin was: "<<buffer1<<endl<<endl;

    cin.get(buffer2, SIZE);
    cout <<"The string read with cin.get was: "<<buffer2<<endl;

    cin.getline(buffer3, SIZE);
    cout<<"\nThe string read with cin.getline was: "<<buffer3<<endl;

    return 0;
}