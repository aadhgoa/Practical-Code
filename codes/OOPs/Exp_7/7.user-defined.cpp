#include<iostream>
using namespace std;
ostream& bell(ostream& output)
{
    return output<<'\a';
}
ostream& carriageReturn(ostream& output)
{
    return output<<'\r';
}
ostream& tab(ostream& output)
{
    return output<<'\t';
}
ostream& endLine(ostream& output)
{
    return output<<'\n'<<flush;
}

int main()
{
     cout<<"testing the tab manipulator: "<<endLine <<'a'<<tab<<'b'<<tab<<'c'<<endLine;
     cout<<"testing carriageReturn and bell:"<<endLine<<"***";
     cout<<bell;
     cout<<carriageReturn<<"-----"<<endLine; 
    }