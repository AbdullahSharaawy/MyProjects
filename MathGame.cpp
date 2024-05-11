#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

enum enlevel{Easy=1 ,Med=2 ,Hard=3 ,Mix=4};
enum enType{Add=1 ,Sub=2 ,Mul=3 ,Div=4 ,MIX=5};

struct stFinalGameResults
{
    int HowManyQuestions;
    enlevel Level;
    enType Type;
    int RightAnswers;
    int WrongAnsewrs;

};
int ReadHowManyQuestions()
{
     int QuestionsNumber=0;
    do
    {
        cout<<"How Many Questions to answer ? ";
        cin>>QuestionsNumber;
    } while (QuestionsNumber<=0);
    
    return QuestionsNumber;
}
enlevel ReadLevel()
{
    short level=0;
    do
    {
       cout<<"Enter Questions Level [1] Easy, [2] Mid, [3] Hard, [4] Mix ? ";
        cin>>level;
    } while (level>4 || level<1);
    return (enlevel)level;
    
}
enType ReadType()
{
    short type=0;
    do
    {
       cout<<"Enter Questions Type [1] Add, [2] Subb, [3] Mul, [4] Div, [5] Mix ? ";
        cin>>type;
    } while (type>5 || type<1);
    return (enType)type;
}
int generate_rand_number(int minimum,int maximum)
{
    
return ( rand() % (maximum - minimum + 1) + minimum);
}
int RandLevel (stFinalGameResults FinalGameResults)
{
    int Rand=0;
    switch (FinalGameResults.Level)
    {
    case enlevel::Med:
        Rand=generate_rand_number(10,50);
        break;
    case enlevel::Easy:
    Rand=generate_rand_number(1,10);
        break;
    case enlevel::Hard:
    Rand=generate_rand_number(50,100);
    break;
    case enlevel::Mix:
    Rand=generate_rand_number(1,100);
    break;
    
    }
    return Rand; 
    
}
bool AddNumbers( stFinalGameResults FinalGameResults )
{
    int N1 ,N2 ,Answer;
    
    N1=RandLevel (FinalGameResults);
    N2=RandLevel (FinalGameResults);
    cout<<N1<<endl;
    cout<<N2<<"  +"<<endl;
    cout<<"_________________"<<endl;
    cin>>Answer;
    if(Answer==N1+N2)
    {
        cout<<"Right Answer :-)"<<endl;
        return true;
    }
    else if(Answer!=N1+N2)
    {
        cout<<"Wrong Answer :-("<<endl;
        cout<<"The Wright Answer is : "<<N1+N2<<endl;
        return false;
    }
    
    
}
bool SubNumbers( stFinalGameResults FinalGameResults )
{
    int N1 ,N2 ,Answer;
    
    N1=RandLevel (FinalGameResults);
    N2=RandLevel (FinalGameResults);
    cout<<N1<<endl;
    cout<<N2<<"  -"<<endl;
    cout<<"_________________"<<endl;
    cin>>Answer;
    if(Answer==N1-N2)
    {
        cout<<"Right Answer :-)"<<endl;
        return true;
    }
    else if(Answer!=N1-N2)
    {
        cout<<"Wrong Answer :-("<<endl;
        cout<<"The Wright Answer is : "<<N1-N2<<endl;
        return false;
    }
    
    
}
bool DivNumbers( stFinalGameResults FinalGameResults )
{
    int N1 ,N2 ,Answer;
    
    N1=RandLevel (FinalGameResults);
    N2=RandLevel (FinalGameResults);
    cout<<N1<<endl;
    cout<<N2<<"  /"<<endl;
    cout<<"_________________"<<endl;
    cin>>Answer;
    if(Answer==N1/N2)
    {
        cout<<"Right Answer :-)"<<endl;
        return true;
    }
    else if(Answer!=N1/N2)
    {
        cout<<"Wrong Answer :-("<<endl;
        cout<<"The Wright Answer is : "<<N1/N2<<endl;
        return false;
    }
    
    
}
bool MulNumbers( stFinalGameResults FinalGameResults )
{
    int N1 ,N2 ,Answer;
    
    N1=RandLevel (FinalGameResults);
    N2=RandLevel (FinalGameResults);
    cout<<N1<<endl;
    cout<<N2<<"  *"<<endl;
    cout<<"_________________"<<endl;
    cin>>Answer;
    if(Answer==N1*N2)
    {
        cout<<"Right Answer :-)"<<endl;
        return true;
    }
    else if(Answer!=N1*N2)
    {
        cout<<"Wrong Answer :-("<<endl;
        cout<<"The Wright Answer is : "<<N1*N2<<endl;
        return false;
    } 
}
bool excuteOperation(stFinalGameResults FinalGameResults)
{
     switch (FinalGameResults.Type)
     {
     case enType::Add:
        return AddNumbers(FinalGameResults);
        break;
     case enType::Div:
        return DivNumbers(FinalGameResults);
        break;
    case enType::Mul:
        return MulNumbers(FinalGameResults);
        break;
    case enType::Sub:
        return SubNumbers(FinalGameResults);
        break;
     }

}

string NameLevel(stFinalGameResults FinalGameResults)
{
    string NameLevel[4]={"Easy","Mid", "Hard","Mix" };
    return NameLevel[FinalGameResults.Level-1];
}
string NameType(stFinalGameResults FinalGameResults)
{
    string NameLevel[5]={"+","-", "*","/", "Mix" };
    return NameLevel[FinalGameResults.Type-1];
}
void MixOperation(int QuestionNumber , stFinalGameResults FinalGameResults ,int &WrongTimes, int &RightTimes)
{
    for(QuestionNumber=1 ;QuestionNumber<=FinalGameResults.HowManyQuestions ;QuestionNumber++)
    {
        int N=0;
        N=generate_rand_number(1,4);
        FinalGameResults.Type=(enType)N;
        if(excuteOperation(FinalGameResults)){RightTimes++;}
        else{WrongTimes++;}
        cout<<"\n\n\n";
    }
}
stFinalGameResults PlayGame (stFinalGameResults FinalGameResults)
{   
    int WrongTimes=0, RightTimes=0;

    FinalGameResults.HowManyQuestions=ReadHowManyQuestions();
    FinalGameResults.Level=ReadLevel();
    FinalGameResults.Type= ReadType();
    cout<<"\n\n";
    for(int QuestionNumber=1 ;QuestionNumber<=FinalGameResults.HowManyQuestions ;QuestionNumber++)
    {
        cout<<"Question  ["<<QuestionNumber<<"/"<<FinalGameResults.HowManyQuestions<<"]"<<endl<<endl;
        if(FinalGameResults.Type == enType::MIX)
        {
            MixOperation( QuestionNumber , FinalGameResults , WrongTimes,  RightTimes);
            break;
        }
        else if(excuteOperation(FinalGameResults)){RightTimes++;}
        else{WrongTimes++;}
       cout<<"\n\n\n";
    }
    FinalGameResults.RightAnswers=RightTimes;
    FinalGameResults.WrongAnsewrs=WrongTimes;
    return FinalGameResults;
    }
    void ShowGameResults(stFinalGameResults FinalGameResults)
{
    cout<<"\n\n\n\n";
    cout<<"_______________________________________________________\n\n";
    if(FinalGameResults.RightAnswers>FinalGameResults.WrongAnsewrs){cout<<"Final Results is Victory : -)\n\n";}
    else if(FinalGameResults.RightAnswers<FinalGameResults.WrongAnsewrs){cout<<"Final Results is Fail : -(\n\n";}
    else{cout<<"Final Results is Draw : -)\n\n";}
    cout<<"Number of Questions : "<<FinalGameResults.HowManyQuestions<<endl;
    cout<<"Question Level      : "<<NameLevel(FinalGameResults)<<endl;
    cout<<"Operation Type      : "<<NameType(FinalGameResults)<<endl;
    cout<<"Number of Right Answers : "<<FinalGameResults.RightAnswers<<endl;
    cout<<"Number of Wrong Answers : "<<FinalGameResults.WrongAnsewrs<<endl<<endl;
    cout<<"_______________________________________________________\n\n";
}

int main()
{
    srand((unsigned)time(NULL));
    char YorN;
    do
    {
    stFinalGameResults FinalGameResults;
    FinalGameResults= PlayGame ( FinalGameResults);
     ShowGameResults( FinalGameResults);
     cout<<"Do You want play Again ? y/Y ?";
     cin>>YorN;
    } while (YorN=='y' || YorN=='Y');
     return 0;
}
