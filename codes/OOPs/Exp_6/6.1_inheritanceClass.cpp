#include <iostream>
#include <cstring>
using namespace std;

class BasicInfo{
  char name[20], gender[2];
  int empID;

  public:
  int getdata(){
    cout<<"Name please: ";
    cin>>name;

    cout<<"Emp Id please: ";
    cin>>empID;

    cout<<"Gender please: ";
    cin>>gender;
 
    return 0;
  }

  void putdata(){
    cout<<name<<endl<<empID<<endl<<gender<<endl;
  }
};

class DeptInfo : public BasicInfo{
  char deptName[10], designation[5];
  int salary;

  public:
  void getinfo(){
    cout<<"Department: ";
    cin>>deptName;
    
    fflush(stdin);

    cout<<"Designation: ";
    cin>>designation;
    
    cout<<"salary: ";
    cin>>salary;
  }

  void putinfo(){
    cout<<deptName<<endl<<designation<<endl<<salary<<endl;
  }
};

class LoanInfo : public BasicInfo{
  char LoanType[20];
  int amount;

  public:
  void getLoanInfo(){
    cout<<"Loan type: ";
    cin>>LoanType;

    cout<<"Amount: ";
    cin>>amount;
  }

  void putLoanInfo(){
    cout<<LoanType<<endl<<amount<<endl;
  }
};


int main() {
  DeptInfo E1;
  LoanInfo E2;

  E1.getdata();
  E1.getinfo();
  E2.getdata();
  E2.getLoanInfo();
  
  E1.putdata();
  E1.putinfo();
  E2.putdata();
  E2.putLoanInfo();
}
