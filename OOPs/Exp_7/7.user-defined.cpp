#include <iostream>
using namespace std;

ostream& endLine( ostream& output){
    return output <<"\n" <<flush;
}

int main(){
    cout<<"Testing: "<<endLine;
    return 0;
}