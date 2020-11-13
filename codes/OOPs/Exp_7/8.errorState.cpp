#include <iostream> 
using namespace std;

int main(){
   int intvalue;
     cout<<"BEFORE a bad input operaton."
         <<"\ncin.rdstate(): "<<cin.rdstate()
         <<"\ncin.eof(): "<<cin.eof()
         <<"\ncin.fail(): "<<cin.fail()
         <<"\ncin.bad(): "<<cin.bad()
         <<"\ncin.good(): "<<cin.good()<<endl;
     cout<<"\nExpects an integer, but enter a character: ";
         cin>>intvalue;
      cout<<endl;
        cout<<"AFTER a bad input."
         <<"\ncin.rdstate(): "<<cin.rdstate()
         <<"\ncin.eof(): "<<cin.eof()
         <<"\ncin.fail(): "<<cin.fail()
         <<"\ncin.bad(): "<<cin.bad()
         <<"\ncin.good(): "<<cin.good()<<endl<<endl;
     cin.clear();
         cout<<"AFTER cin.clear."
         <<"\ncin.rdstate(): "<<cin.rdstate()
         <<"\ncin.eof(): "<<cin.eof()
         <<"\ncin.fail(): "<<cin.fail()
         <<"\ncin.bad(): "<<cin.bad()
         <<"\ncin.good(): "<<cin.good()<<endl;
     
     return 0;
 }