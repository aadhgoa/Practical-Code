#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    double root2 = sqrt(2.0);
    int places;

    cout<<"Square root of 2 with precision 0-9."<<endl<<"Precision set by ios_base member function "<<"precision: "<<endl;

    cout<<fixed;

    for(places = 0; places <= 9; places++){
        cout.precision(places);
        cout<<root2<<endl;
    }

    cout<<"\nPrscision set by stream manipulator "<<"set precision: "<<endl;
    for(places = 0; places <= 9; places++){
        cout<<setprecision(places)<<root2<<endl;
    }

}