#include <iostream>
#include <string>

using namespace std;

class person{
  string name;
  int age;

  public:
  person(string a, int num){
  
    name = a;
    age = num;
  }

  void showperson(){
    cout<<"The name of the player is "<<name<<endl;
    cout<<"The age of the player is "<<age<<endl;
  }
};

class footballplayer :public person{
  int goals;
  string team;

  public:
  footballplayer(int s, string r, int a, string t):
    person(r, s)
    {
      goals = a;
      team = t;
  }

  void showfootballplayer(){
    cout<<"Team: "<<team<<endl;
    cout<<"Goals: "<<goals<<endl;
  }
};

int main() {

  string name, team;
  int age, goals;

  cout<<"Enter player's name: ";
  cin>>name;

  cout<<"Enter player's team: ";
  cin>>team;
  
  cout<<"Enter player's age: ";
  cin>>age;
  
  cout<<"Enter player's goals: ";
  cin>>goals;
  
  footballplayer f(age, name, goals, team);
  cout<<"\n-----------------------------\n"<<endl;
  f.showperson();
  f.showfootballplayer();
}