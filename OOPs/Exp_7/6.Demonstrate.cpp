#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int num = 12345;
    double x = 0.001234567, y = 1.946e9;
    bool booleanValue = true;

    cout<<"***********a**********"<<endl;
    cout<<"Brfore using showpoint"<<endl;
    cout<<"9.9900 prints as: "<<9.9900<<endl;
    cout<<"9.9000 prints as: "<<9.9000<<endl;
    cout<<"9.0000 prints as: "<<9.0000<<endl<<endl;

    cout<<showpoint<<"After using showpoint"<<endl;
    cout<<"9.9900 prints as: "<<9.9900<<endl;
    cout<<"9.9000 prints as: "<<9.9000<<endl;
    cout<<"9.0000 prints as: "<<9.0000<<endl;

    cout<<"**************b*************"<<endl;
    cout<<"Default is right justified: "<<setw(10)<<num<<endl;
    cout<<"\nUse std::left to left justified: "<<left<<setw(10)<<num<<endl;
    cout<<"\nUse std::right to right justified: "<<right<<setw(10)<<num<<endl;

    cout<<"**************c**************"<<endl;
    cout<<"\nDisplayed in default format: "<<x<<"\t"<<y<<endl;
    cout<<"\nDisplayed in scientific format: "<<scientific<<x<<"\t"<<y<<endl;
    cout<<"\nDisplayed in fixed format: "<<fixed<<x<<"\t"<<y<<endl;
    
    cout<<"**************d*************"<<endl;
    cout<<"booleanValue is "<<booleanValue<<endl;
    cout<<"booleanValue (after using boolalpha) is "<<boolalpha<<booleanValue<<endl<<endl;
    cout<<"switch booleanValue and use noboolalpha"<<endl;
    booleanValue = false;
    cout<<noboolalpha<<endl;

    cout <<"booleanValue is  "<<booleanValue<<endl;

    cout<<"booleanValue (after using boolalpha) is "<<boolalpha<<booleanValue<<endl;
    
}