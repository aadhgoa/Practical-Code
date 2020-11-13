#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int num;

    cout<<"Enter a decimal number: "<<endl;
    cin>>num;

    cout<<num<<" in hexadecimal is: "<<hex<<num<<endl<<dec<<num<<" in octal is: "<<oct<<num<<endl<<setbase(10)<<num<<" in decimal is: "<<num<<endl;

}