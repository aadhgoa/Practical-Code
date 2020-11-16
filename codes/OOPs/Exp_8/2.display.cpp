#include <iostream>

using namespace std;

template <typename T, typename S>
void display(T &a, S &b){
    cout << a << " " << b << endl;
}

template <typename T>
void display(int &a, T &b){
    cout << a << " , " << b << endl;
}

int main(){
    int x = 3, z =6;
    float y = 5.71;
    char c = 'C';
    cout << "Displaying 2 numbers of different types,"<<endl<<endl;
    display(x,y);
    cout << "Displaying 1 template type variable and 1 built-in type,"<<endl<<endl;
    display(z,c);
    return 0;
}