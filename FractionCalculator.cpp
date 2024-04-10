// Purpose: In this application create a rational number calculator that is capable of taking two rational numbers and an operation to perform on them
// Version : v1.0
// Date    : 17/03/2024
#include<iostream>
#include<string>
#include<regex>
using namespace std;
string RecieveData()
{
cout<<"enter the numbers and operation:";
string input;
getline(cin,input);
regex validation("([ ]+)?-?([0-9]+)/?(-?[1-9]+)?[ ](['+' '/' '*']|-)[ ]-?([0-9]+)/?(-?[1-9]+)?([ ]+)?");
while(!regex_match(input,validation)){
    cout<<"enter valid numbers and operation:";
    getline(cin,input);
}
return input;
}
//this function to read the fractions and operation type from the user
void ReadData(string &first_fr,string &second_fr,char &opr )
{
    string num_str="";
    num_str=RecieveData();
    for(int i=0 ; i<num_str.length() ;i++)
            {
                if(ispunct(num_str[i]) && num_str[i-1]==' ' && num_str[i+1]==' ')
                {
                    opr=num_str[i];
                    first_fr=num_str.substr(0,i);
                    num_str=num_str.erase(0,i+1);
                    break;
                }  
            }
    second_fr=num_str;
}
//this function to convert fraction to double through separation the fraction to nominator and denominator
void handle_nominator_denominator(string number,int &nominator,int &denominator)
{
    //separate the fraction to nominator and denominator
    if(number.find('/')!=number.npos)
    {
        nominator=stoi(number.substr(0,number.find('/')));
        denominator=stoi(number.substr(number.find('/')+1,number.length()-number.find('/')+1));
    }
    else 
    {
        nominator=stoi(number);
        denominator=1;
    }

}
//this function to multiply the two fractions 
void multiplication_fractions(int nominator1,int denominator1,int nominator2,int denominator2)
{
    cout<<nominator1*nominator2<<"/"<<denominator1*denominator2;
}
//this function to sum the two fractions
void sum_fractions(int nominator1,int denominator1,int nominator2,int denominator2)
{
    if((denominator1*denominator2)==0)cout<<"Math Error"<<endl;
    else cout<<(nominator1*denominator2+nominator2*denominator1)<<"/"<<(denominator1*denominator2);
}
//this function to subtract the two fractions
void subtract_fractions(int nominator1,int denominator1,int nominator2,int denominator2)
{
    if(denominator1*denominator2==0)cout<<"Math Error"<<endl;
    else cout<<((nominator1*denominator2)-(nominator2*denominator1))<<"/"<<denominator1*denominator2;
}
//this function to divide the two fractions
void division_fractions(int nominator1,int denominator1,int nominator2,int denominator2)
{
    if(nominator2*denominator1==0)cout<<"Math Error"<<endl;
    else cout<<nominator1*denominator2<<"/"<<nominator2*denominator1;
}
//start the calculator
void calculator()
{
   string Number1,Number2; 
   int nominator1, denominator1;
   int nominator2, denominator2;
   char OperationType;
   ReadData(Number1,Number2,OperationType );
   //handle the denominator and the nominator from the first fraction and second fraction
   handle_nominator_denominator( Number1,nominator1, denominator1);
   handle_nominator_denominator( Number2,nominator2, denominator2);
   
   switch (OperationType)
   {
   case '+':
    cout<<Number1<<" "<<OperationType<<" "<<Number2<<" = ";
    sum_fractions( nominator1, denominator1, nominator2, denominator2);
    cout<<endl;
    break;
   case '-':
    cout<<Number1<<" "<<OperationType<<" "<<Number2<<" = ";
    subtract_fractions(nominator1, denominator1, nominator2, denominator2);
    cout<<endl;
    break;
   case '*':
    cout<<Number1<<" "<<OperationType<<" "<<Number2<<" = ";
    multiplication_fractions(nominator1, denominator1, nominator2, denominator2);
    cout<<endl;
    break;
   case '/':
    cout<<Number1<<" "<<OperationType<<" "<<Number2<<" = ";
    division_fractions(nominator1, denominator1, nominator2, denominator2);
    cout<<endl;
    break;
   default:
    break;
   }
}
// display front view for the program for the user
void StartPrograme()
{
    string choise;
    cout<<"Please enter a rational number operations (or exit):"<<endl;
    while (true)
    {
        cout<<"1] Start the calculator\n"<<"2] Exsit\n"<<"input 1 or 2 ! ";
         getline(cin,choise) ;
        //if choise not equal 1 or 2 then ask the user again
        if(choise != "1" && choise != "2")continue;
        else if(choise=="1")
        {
            calculator();
            StartPrograme();
            return;
        }
        else return;//if choise equal 2 exist from the program
    } 
}
int main()
{
    StartPrograme();
}