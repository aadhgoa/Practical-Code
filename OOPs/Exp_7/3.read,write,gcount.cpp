#include <iostream>
using namespace std;

int main(){
    const int SIZE = 80;
    char buffer [SIZE];

    cout << "Enter a sentence: "<<endl;

    cin.read(buffer, 20);

    cout<<endl<<"The sentence entered was: "<<endl;
    cout.write(buffer,cin.gcount());
    cout<<endl;
}