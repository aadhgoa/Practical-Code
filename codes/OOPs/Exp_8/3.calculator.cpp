#include<iostream>

using namespace std;

template <class T>

class calcualtor{
    private:
    T num1, num2;

    public:
    calcualtor(T n1, T n2){
        num1 = n1;
        num2 = n2;
    }

    void displayResult(){
        cout<<"Numbers are: "<<num1<<" and "<<num2<<","<<endl;
        cout<<"Additon is: "<<add()<<endl;
        cout<<"Suntraction is: "<<subtract()<<endl;
        cout<<"Product is: "<<multiply()<<endl;
        cout<<"Division is: "<<divide()<<endl;
    }

    T add(){ return num1 + num2;}

    T subtract(){ return num1 - num2;}

    T multiply(){ return num1 * num2;}

    T divide(){ return num1 / num2;}
};

int main(){

    int num1, num2;
    cout<<"Enter 2 integer numbers: ";

    cin>>num1>>num2;
    calcualtor<int> intcalc(num1, num2);


    float num3, num4;
    cout<<"Enter 2 floating numbers: ";

    cin>>num3>>num4;
    calcualtor<float> floatcalc(num3, num4);
    

    cout<<"Integer Results: "<<endl;
    intcalc.displayResult();

    cout<<endl<<"Float Results: "<<endl;
    floatcalc.displayResult();
}