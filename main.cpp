#include <iostream>
#include <cstdio>   //input and output libraries from C language
#include <iomanip>  //output manipulation ("setw(20)" <- prints output on 20 characters size
#include <math.h>   //using M_PI value from this library

//using as default std namespace
using namespace std;

//declaring namespaces with values
namespace colegue1{
    char name[10]="adam";
    int age=23;
}

namespace colegue2{
    char name[10]="peter";
    int age=24;
}

void circle_field(){
    float c=0,field=0;

    cout<<"Enter radius value:";
    cin>>c;
    field=M_PI*pow(c,2);

    //using c++ cout stream and stream manipulators to print out values
    cout<<"Circle field of given radius: "<<c<<" is equal to: "<<left<<setfill('#')<<setw(20)<<fixed<<setprecision(2)<<field<<endl;
    //using c printf function to print values
    printf("Circle field of given radius: %.2f is equal to: %20.2f \n\n",c,field);
}

//using structures
struct date{
int day;
int month;
int year;
};

struct worker{
char name[15];
char surname[15];
float hourRate;
float hourCount;
date employmentDate;
};


worker readData(){
    worker p;
    cout<<"Name:";
    cin>>p.name;
    cout<<"Surname:";
    cin>>p.surname;
    cout<<"Hour rate:";
    cin>>p.hourRate;
    cout<<"Hour count:";
    cin>>p.hourCount;
    cout<<"Date:"<<endl<<"Year:";
    cin>>p.employmentDate.year;
    cout<<"Month:";
    cin>>p.employmentDate.month;
    cout<<"Day:";
    cin>>p.employmentDate.day;
    return p;
}

float countWage(worker p){
return p.hourCount*p.hourRate;
}

void display(worker p){
cout<<setw(20)<<p.name<<setw(20)<<p.surname<<setw(20)<<p.hourCount<<setw(20)<<p.hourRate<<setw(20)<<countWage(p)<<endl;
}


int main()
{
    //function call
    circle_field();

    char name[10]="name"; 
    int age=0;

    //using scanf and printf to read and write values
    printf("Input name:");
    scanf("%s",name); //reading string (%s), cant use (%c) to read char array
    printf("Input age:");
    scanf("%d",&age);

    //printing values from std namespace
    printf("%20s %5d\n",name, age); //classic C way
    cout<<setw(20)<<name<<setw(5)<<age<<endl;   //Cpp way

    //printing values from colegue1 and colegue2 namespaces
    cout<<"Colegue1 namespace:"<<colegue1::name<<" "<<colegue1::age<<endl;
    cout<<"Colegue2 namespace:"<<colegue2::name<<" "<<colegue2::age<<endl;

    //differences between C and Cpp in io streams
    char sign;
    int number;
    float realNumber;
    double numberDoublePrecision;
    char arrayOfSigns[20];  //C dont have String variable - uses Cstrings instead

    //classic C steams manipulation
    printf("Enter character:");
    scanf("%c",&sign);
    printf("Enter integer value:");
    scanf("%i",&number);
    printf("Enter decimal value (extension after comma):");
    scanf("%f",&realNumber);
    printf("Enter double precision value (extension after comma):");
    scanf("%lf",&numberDoublePrecision);
    printf("Enter string value:");
    scanf("%s",arrayOfSigns);   //cant use reference
    
    //printing values using printf() function
    printf("%.2f\n",realNumber);
    printf("%.2lf\n",numberDoublePrecision);
    printf("%20s\n",arrayOfSigns);
    printf("%-20s\n",arrayOfSigns);

    //printing Cstring using printf
    for(int a=0;a<3;a++){
        for(int b=0;b<3;b++){printf("%d\t",number);}
        printf("\n");
    }

    //using Cpp io streams (so much easier and dont have to use reference every time)
    /*
    cout<<"Enter character:";
    cin>>sign;
    cout<<endl<<"Enter integer value";
    cin>>number;
    cout<<endl<<"Enter decimal value (extension after comma):";
    cin>>realNumber;
    cout<<endl<<"Enter double precision value (extension after comma):";
    cin>>numberDoublePrecision;
    cout<<endl<<"Enter string value:";
    cin>>arrayOfSigns;

    //printing variable values using Cpp streams
    cout<<setprecision(2)<<realNumber<<endl;
    cout<<setprecision(2)<<numberDoublePrecision<<endl;
    cout<<setfill('#')<<setw(20)<<arrayOfSigns<<endl;
    cout<<setw(-20)<<arrayOfSigns<<endl;

    for(int a=0;a<3;a++){
        for(int b=0;b<3;b++){
            cout<<number<<"\t";
        }
        cout<<endl;
    }
    */

    //structures array
    worker p[3];
    for(int a=0;a<3;a++){
    p[a]=readData();
    display(p[a]);
    }

    return 0;
}
