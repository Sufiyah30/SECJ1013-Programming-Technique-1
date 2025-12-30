/*
NOR FATIHAH BINTI OTHMAN (A25CS0296)
NOR AIN FAHIRA BINTI MUHAMAD FARIQ (A25CS0295)
NORSUFIYAH ALIYAH BINTI MD JOHAIMI (A24SC0215)
18 DECEMBER 2025
*/


#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

//FUNCTION KIRA BMR
float calculateBMR(char gender,int weight,int height,int age){
    float BMR;
    if(gender=='M')
        BMR=(10*weight)+(6.25*height)-(5*age)+5;
    else if (gender=='F')
        BMR=(10*weight)+(6.25*height)-(5*age)-161;
    
    return BMR;
}

int main(){
    
    char data;
    //REPEATITION FOR TENTUKAN DATA
    do{

    int age;
    char gender;
    int height,weight;
    float BMR;
    

    cout<<"Basal Metabolic Rate (BMR) Calculator"<<endl;
    cout<<endl;

    //REPEATITION FOR AGE
    do{
        cout<<"Age[15-80] : ";
        cin>>age;

    }while(age <15 || age >80);

    //REPEATITION FOR GENDER
    do{

        cout<<"Gender [F @ M]: ";
        cin>>gender;
        gender=toupper(gender);

    }while(gender!='F' && gender!='M');
    
    cout<<"Height(cm): ";
    cin>>height;
    cout<<"Weight(kg): ";
    cin>>weight;

    BMR=calculateBMR(gender,weight,height,age);

    cout<<endl;
    cout<<"BMR = "<<BMR<<" Calories/ day (using Mifflin-St Jeor Equation)"<<endl;
    cout<<endl;
    cout<<"Daily calorie needs based on activity level"<<endl;
    cout<<"\n";

    cout<<"Activity Level\t\t\t\t\t\tCalorie"<<endl;

    float sedentary,exercise1,exercise2,dailyExercise,intenseExercise;
    int veryIntense;

    sedentary=ceil(BMR*1.2); //ceil tu sbb nak bundar number cth 40.5 --> 41
    exercise1=ceil(BMR*1.375);
    exercise2=ceil(BMR*1.4649);
    dailyExercise=ceil(BMR*1.549);
    intenseExercise=ceil(BMR*1.7248);
    veryIntense=(BMR*1.901);

    cout<<"Sedentary: little or no exercise\t\t\t"<<sedentary<<endl;
    cout<<"Exercise 1-3 times/week\t\t\t\t\t"<<exercise1<<endl;
    cout<<"Exercise 4-5 times/week\t\t\t\t\t"<<exercise2<<endl;
    cout<<"Daily exercise or intense exercise 3-4 times/week\t"<<dailyExercise<<endl;
    cout<<"Intense exercise 6-7 times/week\t\t\t\t"<<intenseExercise<<endl;
    cout<<"Very intense exercise daily, or physical job\t\t"<<veryIntense<<endl;

    cout<<endl;
    cout<<"Exercise: 15-30 minutes of elevated heart rate activity."<<endl;
    cout<<"Intense exercise: 45-120 minutes of elevated heart rate activity."<<endl;
    cout<<"Very intense exercise: 2+ hours of elevated heart rate activity."<<endl;
    cout<<endl;

    cout<<"Do you want to enter other data? [Y @ N]: ";
    cin>>data;
    data=toupper(data);
    cout<<endl;
    
    }while(data!='N');

    cout<<"Thank you :)";
}