#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class employee{
protected:
string name,gndr,address;
int id,age,cntctno;
public:
virtual void setdata()=0;
virtual void display()=0;
};
class boss;
class upperstaff: public employee{
 private:
    int leave,hrswrked,slry;
    string position;
    public:
    upperstaff(){
        leave=hrswrked=0;
        position="";
    }
    void salary(boss&);
    void setdata(){
        int ch;
        cout<<endl<<"enter employee name:";
    cin>>name;
cout<<endl<<"enter age:";
cin>>age;
cout<<endl<<"enter gender:";
cin>>gndr;
cout<<endl<<"enter id:";
cin>>id;
cout<<endl<<"enter address:";
cin>>address;
cout<<endl<<"enter contact:";
cin>>cntctno;
        cout<<endl<<"enter days absent:";
        cin>>leave;
        cout<<endl<<"enter hours worked in a day:";
        cin>>hrswrked;
        cout<<endl<<"select your post in upper management:"<<endl<<"1.management\n2.security\n3.adminstration\n4.other";
        cin>>ch;
while(position==""){        
switch (ch)
{
case 1:
    position="management";
    break;
case 2:
position="security";
break;
case 3:
position="adminstration";
break;
case 4:
cout<<endl<<"specify your post";
cin>>position;
break;
}}
/*incase boss doesnt specify payrate*/
if(position=="adminstration"){
    slry=(hrswrked*90)*(30-leave);
}else if(position=="security"){
    slry=(hrswrked*80)*(30-leave);
}else if(position=="management"){
    slry=(hrswrked*95)*(30-leave);
}else{
    slry=(hrswrked*85)*(30-leave);
}
}
void display(){
    cout<<endl<<"name:"<<name;
    cout<<endl<<"ID:"<<id;
    cout<<endl<<"age"<<age;
    cout<<endl<<"gender:"<<gndr;
    cout<<endl<<"address:"<<address;
    cout<<endl<<"contact:"<<cntctno;
    cout<<endl<<"position:"<<position;
    cout<<endl<<"salary:"<<slry;
}
};
class lowerstaff:public employee{
private:
int leave,shifts,slry;
string position;
public:
lowerstaff(){
    leave=shifts=0;
    position="";
}
void salary(boss&);
void setdata(){
    int ch;
    cout<<endl<<"enter employee name:";
    cin>>name;
cout<<endl<<"enter age:";
cin>>age;
cout<<endl<<"enter gender:";
cin>>gndr;
cout<<endl<<"enter id:";
cin>>id;
cout<<endl<<"enter address:";
cin>>address;
cout<<endl<<"enter contact:";
cin>>cntctno;
    cout<<endl<<"enter no of days absent:";
    cin>>leave;
    cout<<endl<<"enter no of shifts in a day:";
    cin>>shifts;
     cout<<endl<<"select your post in staff:"<<endl<<"1.reception\n2.cleaning staff\n3.kitchen staff\n4.other";
        cin>>ch;
while(position==""){
switch (ch)
{
case 1:
    position="reception";
    break;
case 2:
position="cleaning staff";
break;
case 3:
position="kitchen staff";
break;
case 4:
cout<<endl<<"specify your post";
cin>>position;
break;
default:
cout<<endl<<"sorry wrong input!make correct choice";
cin>>ch;
break;
}}
/*incase boss doesnt specify payrate*/
if(position=="reception"){
    slry=(shifts*90)*(30-leave);
}else if(position=="cleaning staff"){
    slry=(shifts*80)*(30-leave);
}else if(position=="kitchen staff"){
    slry=(shifts*95)*(30-leave);
}else{
    slry=(shifts*85)*(30-leave);
}
  } 
void display(){
    cout<<endl<<"name:"<<name;
    cout<<endl<<"ID:"<<id;
    cout<<endl<<"age"<<age;
    cout<<endl<<"gender:"<<gndr;
    cout<<endl<<"address:"<<address;
    cout<<endl<<"contact:"<<cntctno;
    cout<<endl<<"position:"<<position;
    cout<<endl<<"salary:"<<slry;
}
};
class boss{
private:
int bonus,uspayrt,lspayrt;
public:
void set(){
    cout<<endl<<"enter rate of pay per hour of upperstaff";
    cin>>uspayrt;
    cout<<endl<<"enter minimum wage of lowerstaff";
    cin>>lspayrt;
    cout<<endl<<"enter bonus for upperstaff:";
    cin>>bonus;
}
friend void upperstaff::salary(boss& b);
friend void lowerstaff::salary(boss& b);
};
void upperstaff::salary(boss& b){
    if(position=="management"){
slry=(4*b.uspayrt*hrswrked)*(30-leave);
    }else if (position=="adminstration")
    {
slry=(3*b.uspayrt*hrswrked)*(30-leave);        
    }else if(position=="security"){
slry=(2*b.uspayrt*hrswrked)*(30-leave);
    }else{
        slry=(b.uspayrt*hrswrked)*(30-leave);
    }    
}
void lowerstaff::salary(boss &b){
    if(position=="reception"){
slry=(4*b.uspayrt*shifts)*(30-leave);
    }else if (position=="kitchen staff")
    {
slry=(3*b.uspayrt*shifts)*(30-leave);        
    }else if(position=="cleaning staff"){
slry=(2*b.uspayrt*shifts)*(30-leave);
    }else{
        slry=(b.uspayrt*shifts)*(30-leave);
    }    
}
class employeemenu:public upperstaff,public lowerstaff,public boss{
public:
void empmenu(){
int ch;
boss b;upperstaff u;lowerstaff l;
 cout<<endl<<"WELCOME TO EMPLOYEE SECTOR OF HOTEL MANAGEMENT SYSTEM";
for(;ch!=4;){        
cout<<endl<<"Choose an option:\n1.SET EMPLOYEE DATA\n2.GENERATE SALARY \n3.DISPLAY EMPLOYEE RECORDS\n4. EXIT";
cin>>ch;
int op,cond=0;
switch(ch)
{
case 1:
{int opcond=0;
    cout<<endl<<"Select your position in staff:\n1. boss\n2. upperstaff\n3. lowerstaff";
    cin>>op;
for(;opcond!=1;){
    if(op==1){
b.set();
opcond=1;
cond=1;
cout<<endl<<"employee data has been successfully saved!";
        cout<<endl<<"press any key to continue";
        getch();
system("cls");
    }else if(op==2){
        u.setdata();
        opcond=1;
        op=1;
        cout<<endl<<"employee data has been successfully saved!";
        cout<<endl<<"press any key to continue";
        getch();
        system("cls");        
    }else if(op==3){
        l.setdata();
        opcond=1;
        op=2; 
        cout<<endl<<"employee data has been successfully saved!";
        cout<<endl<<"press any key to continue";
        getch();
        system("cls");       
    }else{
        cout<<endl<<"Wrong input!make correct choice";
        cin>>op;
    }}
        break;
}
case 2:
{
    if(op==1){
        system("cls");
        cout<<endl<<"************UPPERSTAFF EMPLOYEE SALARY RECIEPT***************";
if(cond==1){
u.salary(b);}
u.display();
}else if(op==2){
    system("cls");
    cout<<endl<<"**************LOWERSTAFF EMPLOYEE SALARY RECIEPT*************";
if(cond==1){
l.salary(b);}
l.display();
}
break;
}
case 3:
{
    /*display past saved records through filing*/
    cout<<endl<<"*************EMPLOYEE RECORDS**************";
    break;
}
case 4:{
break;
}
default:
cout<<endl<<"sorry!wrong input";
cout<<endl<<"press any key to continue";
getch();
    break;
}
}
}
};
