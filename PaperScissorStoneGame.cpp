#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
// enum choice{stone , paper,scissors};

// enum enresult{win=1 ,faul=2 ,equivlance=3};

        int read_positive_number()
{
    int N;
    do
    {
    cout <<"How Many Rounds 1 to 10 ?"<<endl;

    cin>>N;

    }while(N<=0);
    return N;
}
int generate_rand_number(int minimum,int maximum)
{
    
return ( rand() % (maximum - minimum + 1) + minimum);
}
void ChoocingAnsewr(string &HisChoice,string &ComputerChoice ,int &your_choice ,int &computer_choice)
{

    cout<<"your choice: [1]:stone ,[2]:paper ,[3]:scissors ?\n";

        cin>>your_choice;

        computer_choice=generate_rand_number(1,3); 

        if(your_choice==1 ){HisChoice="stone";}

        else if(your_choice==2 ){HisChoice="paper";}

        else{HisChoice="scissors";}

        if(computer_choice==1 ){ComputerChoice="stone";}

        else if(computer_choice==2 ){ComputerChoice="paper";}

        else{ComputerChoice="scissors";}

        

}
void TheWiner(int your_choice ,int computer_choice, int &Computer ,int &Player ,int &NoWiner)
{
    string winer;
    if((your_choice ==2) && (computer_choice==3))
    {
        winer=" [ Computer ] ";
        cout<<"\a";
        Computer++;
    }
    
   else if((your_choice ==1) && (computer_choice==2))
    {
        winer=" [ Computer ] ";
         cout<<"\a";
        Computer++;
    }
   else if((your_choice==2) && (computer_choice==1))
    {
        winer=" [ Player ] ";
        Player++;
    }
   else if((your_choice ==3) && (computer_choice==1))
    {
        winer=" [ Computer ] ";
         cout<<"\a";
        Computer++;
    }
   else if((your_choice ==3) && (computer_choice==2))
    {
        winer=" [ Player ] ";
        Player++;
    }
   else if((your_choice ==1) && (computer_choice==3))
    {
        winer=" [ Player ]";
        Player++;
    }
    else {
        winer=" [ No Winer ]";
        NoWiner++;
         }
cout<<"Round Winer    :"<<winer<<endl<<endl;

}
void Round(int N ,string &HisChoice ,string &ComputerChoice ,int &Computer ,int &Player ,int &NoWiner ,short &i)
{
    int your_choice ,computer_choice;
    
    for( i=1;i<=N;i++)
    {
        
        
        cout<<"Round ["<<i<<"] begins:"<<endl<<endl;

        ChoocingAnsewr(HisChoice, ComputerChoice ,your_choice , computer_choice );

        cout<<"____________________Round["<<i<<"]_____________________"<<endl<<endl;
        cout<<"player1  choice: "<<HisChoice<<endl;
        cout<<"computer choice: "<<ComputerChoice<<endl;
        TheWiner( your_choice , computer_choice,  Computer , Player , NoWiner);
    }
}
string FinalResult(int Computer ,int Player ,int NoWiner)
{
    string Winer;
    if(Computer>Player){Winer="[ Computer ]";}

   else if(Computer<Player){Winer="[ Player1 ]";}

   else {Winer="[ No Winer ]";}
   return Winer;
}
void GameOver(int Computer ,int Player ,int NoWiner ,short i )
{
    cout<<"                ______________________________________________________"<<endl<<endl;
    cout<<"                                 +++ G a m e  O v e r +++             "<<endl<<endl;
    cout<<"                ______________________________________________________"<<endl<<endl;
    cout<<"                ______________________ [Game Results]_________________"<<endl<<endl;
    cout<<"                Game Rounds         : "<<i-1<<endl;
    cout<<"                Player1 won times   : "<<Player<<endl; 
    cout<<"                computer won times  : "<<Computer<<endl;
    cout<<"                Draw times          : "<<NoWiner<<endl;
    cout<<"                Final Winer         : "<<FinalResult( Computer , Player , NoWiner)<<endl<<endl;
    cout<<"                ______________________________________________________"<<endl<<endl;
}
bool again()
{
    char YorN;
    cout<<"Do you want play again more ? Y/N ?";
    cin>>YorN;
    cout<<endl;
    switch (YorN)
    {
    case 'y':
        return true;
        break;
    case 'Y':
        return true;
    case 'n':
        return false;
    default:
        return false;
        break;
    }
    
}
int main()
{
    srand((unsigned)time(NULL));
    
    do{
    int Computer=0 , Player=0 , NoWiner=0;
    short i;
    string HisChoice;
    string ComputerChoice;
    Round(read_positive_number(),HisChoice,ComputerChoice ,Computer , Player , NoWiner ,i);
    GameOver( Computer , Player , NoWiner , i );
    }while(again());
    return 0;
}