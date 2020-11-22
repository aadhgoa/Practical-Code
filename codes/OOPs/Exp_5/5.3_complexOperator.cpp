#include<iostream>
using namespace std;

class complex
{
float real,img;
public:
complex()
{
real=0;
img=0;
}
complex(float r,float i)
{
real=r;
img=i;
}
void show ()
{
cout<<real<<"+i"<<img<<endl;
}
complex operator+(complex &p)
{
complex w;
w.real=real+p.real;
w.img=img+p.img;
return w;
}
complex operator-(complex &p)
{
complex w;
w.real=real-p.real;
w.img=img-p.img;
return w;
}
friend complex operator*(complex &p,complex &q);
friend complex operator/(complex &p,complex &q);

};
complex operator*(complex &p,complex &q)
{
complex w;
w.real=p.real*q.real;
w.img=p.img*q.img;
return w;
}
complex operator/(complex &p,complex &q)
{
complex w;
w.img=q.img/p.img;
w.real=q.real/p.real;

return w;
}

int main()
{
cout<<"OVERLOADING + OPERATOR USING MEMBER FUNCTION \n";
complex s(3,4);
complex t(4,5);
complex m;
m=s.operator+(t);
s.show();
t.show();
cout<<"---------------"<<endl;
m.show();
cout<<endl<<endl;

cout<<"OVERLOADING - OPERATOR USING MEMBER FUNCTION \n";
complex a(5,8);
complex b(2,4);
complex c;
c=a.operator-(b);
a.show();
b.show();
cout<<"---------------"<<endl;
c.show();
cout<<endl<<endl;

cout<<"OVERLOADING * OPERATOR USING MEMBER FUNCTION \n";
complex e(3,4);
complex f(4,5);
complex g;
g=operator*(e,f);
e.show();
f.show();
cout<<"---------------"<<endl;
g.show();
cout<<endl<<endl;

cout<<"OVERLOADING / OPERATOR USING MEMBER FUNCTION \n";
complex h(4,6);
complex i(2,6);
complex j;
h=i/j;
i.show();
j.show();
cout<<"---------------"<<endl;
h.show();
cout<<endl<<endl;

return 0;
}