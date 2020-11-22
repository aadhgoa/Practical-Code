#include <iostream>
using namespace std;

class student{
  protected:
  int roll_number;

  public:
  void get_number(int num1){
    roll_number = num1;
  }

  void put_number(){
    cout<<"Roll No: "<<roll_number<<endl;
  }
};

class test: public student{
  protected:
  float part1, part2;

  public:
  void get_marks(float num1, float num2){
    part1 = num1;
    part2 = num2;
  }

  void put_marks(){
    cout<<"Marks obtained\n"<<"Part 1 = "<<part1<<"\n"<<"Part 2 = "<<part2<<endl;
  }
};

class sports{
  protected:
  float score;

  public:
  void get_score(float nums){
    score = nums;
  }

  void put_score(){
    cout<<"Sports: "<<score<<endl<<endl;
  }
};

class results :public test, public sports{
  float total;

  public:
  void display();
};

void results ::display(){
    total  = part1 + part2 + score;

    put_number();
    put_marks();
    put_score();

    cout<<"Total Score: "<<total<<endl;
  }


int main() {
  int roll_no;

  float marks1, marks2;
  results student_1;

  cout<<"Enter  Roll number: ";
  cin>>roll_no;

  student_1.get_number(roll_no);

  cout<<"Enter  2 marks: ";
  cin>>marks1>>marks2;

  student_1.get_marks(marks1, marks2);

  cout<<"Enter scores: ";
  cin>>marks1;
  student_1.get_score(marks1);

  student_1.display();

  return 0;
}