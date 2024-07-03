
#include <string>
#include <vector>
#include <fstream>
#include<iomanip>
#include<sstream>
#include <limits>
#include <iostream>
using namespace std;
string FailuerType;
enum enTransictionMenu{deposit=1,QuickDraw=2,NormalDraw=3,check_balance=4,LogOut=5};
enum enQuickDraw{_20=1,_50=2,_100=3,_200=4,_400=5,_600=6,_800=7,_1000=8,_Exist=9,};
struct sData
{
    string PinCode,AccountNumber,Name,Phone,AccountBalance;
};
sData CurrentUser;
void PrintYourAccount(sData ClientData)
{
            cout<<"----------------------------------------------------\n";
            cout<<"Account Balance : "<<ClientData.AccountBalance<<endl;
            cout<<"----------------------------------------------------\n";
}
bool IsAccountNumberExist(vector <sData> &stDataOfClients, string account_number)
{
   
   
    for(int i=0 ; i<stDataOfClients.size() ; i++)
    {
        if(account_number==stDataOfClients[i].AccountNumber)
        {
            return true;
        }
    }
    return false;
}
string lower_all_string(string &sWord)
{
    for(int i=0 ; i<sWord.length() ; i++)
    { sWord[i]=tolower(sWord[i]); }
    return sWord;
}

void SaveDataInFile(vector <sData> &stDataOfClients)
{
    fstream UpdateData;
    UpdateData.open("MyFile.txt", ios::out);//write mode without append 
    
    for(int i=0 ; i<stDataOfClients.size() ; i++)
    {
        
         if(UpdateData.is_open())
        {
            UpdateData<<stDataOfClients[i].AccountNumber<<"#//#";
            UpdateData<<stDataOfClients[i].PinCode<<"#//#";
            UpdateData<<stDataOfClients[i].Name<<"#//#";
            UpdateData<<stDataOfClients[i].Phone<<"#//#";
            UpdateData<<stDataOfClients[i].AccountBalance<<endl;
        }
        //
    }
     UpdateData.close();
}

void ReadLoginData(vector <sData> &stDataOfClients)
{
    
    cout<<"\n\nPlease enter AccountNumber ? ";
        cin>>CurrentUser.AccountNumber;
        cout<<"\nPlease enter Pin code ? ";
         cin>>CurrentUser.PinCode;                 
}
void UpdateData(vector<sData> &vDataOfClient);
vector<string> ReciveDataFromFile(string FileName);
sData StoreDataInStruct( vector <string> vWords);
vector<string> split(string sWord ,string delimiter=" ");
vector<sData> StoreDataOfClients( vector<string> sDataOfClients ,string delimiter=" ");
string join_string(vector <string> &Vector,string delimiter=" ");
void main_menu( vector <sData> &vDataOfClients);
void Login( vector <sData> &vDataOfClients);
void TransactionsMenuScreen()
{
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<setw(40)<<"Main Menue Screen\n";
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<"\t  "<<"[1] Deposit.\n";
    cout<<"\t  "<<"[2] Quick Withdraw.\n";
    cout<<"\t  "<<"[3] Normal Withdraw.\n";
    cout<<"\t  "<<"[4] check balance.\n";
    cout<<"\t  "<<"[5] LogOut.\n";
     for(short i=0 ; i<60 ; i++){cout<<"=";}
     cout<<endl;
}
void QuickWithDrawScreen()
{
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<setw(40)<<"Quick With Draw\n";
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<"\t  "<<"[1] 20."<<"            [2] 50.\n";
    cout<<"\t  "<<"[3] 100."<<"           [4] 200.\n";
    cout<<"\t  "<<"[5] 400."<<"           [6] 600.\n";
    cout<<"\t  "<<"[7] 800."<<"           [8] 1000.\n";
    cout<<"\t  "<<"[9] Exist.\n";
     for(short i=0 ; i<60 ; i++){cout<<"=";}
     cout<<endl;
}

void DepositScreen()
{
    cout<<endl;
      for(short i=0 ; i<60 ; i++){cout<<"_";}
    cout<<endl;
    cout<<setw(40)<<"Deposite Screen\n";
    for(short i=0 ; i<60 ; i++){cout<<"_";}
    cout<<endl<<endl;
}

void NormalWithDrawScreen()
{
    cout<<endl;
      for(short i=0 ; i<60 ; i++){cout<<"_";}
    cout<<endl;
    cout<<setw(40)<<"Normal WithDraw\n";
    for(short i=0 ; i<60 ; i++){cout<<"_";}
    cout<<endl;
}
bool ValidationAmountDraw(int amount)
{
     if (amount>stoi(CurrentUser.AccountBalance))
     {
        cout<<"enter amount less than or equal your account balance\n!";
        return false;
     }
     return true;
}

void NormalWithDraw(vector <sData> &vDataOfClients)
{
    NormalWithDrawScreen();
    char YorN;
    int Dep;
    PrintYourAccount(CurrentUser);
    do
    {
        cout<<"\n\nplease enter Amount multiple 5's ? ";
        cin>>Dep;
   
    } while (Dep%5!=0 && ValidationAmountDraw(Dep));
    
        cout<<"Are you sure you want perform this action, y/n ? ";
    cin.ignore(100,'\n');
    cin.get(YorN);
    if(YorN=='y' || YorN=='Y')
    {
        CurrentUser.AccountBalance=to_string(stoi(CurrentUser.AccountBalance)+Dep*(-1));
        cout<<"\nyour account balance is "<<CurrentUser.AccountBalance<<endl;
         UpdateData(vDataOfClients);
        SaveDataInFile(vDataOfClients);
        vDataOfClients=StoreDataOfClients( ReciveDataFromFile("MyFile.txt") ,"#//#");
    }
char c;
cout<<"press any key (character) to go to back menue.......";
cin.ignore(100,'\n');
cin.get(c);
}
void QuickWithDraw(vector <sData> &vDataOfClients)
{
    char YorN;
    char n;
    PrintYourAccount(CurrentUser);
    do
    {
        cout<<"\n\nchoose what do you want to do from [1] to [8] ? ";
        cin.ignore(100,'\n');
        cin.get(n);
   
    } while (n!='1' && n!='2' && n!='3' && n!='4' && n!='6' && n!='5' && n!='7' && n!='8' && n!='9' );
    
    
    if(n==9) main_menu(vDataOfClients);

    cout<<"Are you sure you want perform this action, y/n ? ";
    cin.ignore(100,'\n');
    cin.get(YorN);
    if(YorN=='y' || YorN=='Y')
    {
        
    switch ((enTransictionMenu)(n-'0'))
    {
    case _20:
        CurrentUser.AccountBalance=to_string(stoi(CurrentUser.AccountBalance)+20*(-1));

        break;
    case _50:
        CurrentUser.AccountBalance=to_string(stoi(CurrentUser.AccountBalance)+50*(-1));

        break;
    case _100:
        CurrentUser.AccountBalance=to_string(stoi(CurrentUser.AccountBalance)+100*(-1));

        break;
    case _200:
        CurrentUser.AccountBalance=to_string(stoi(CurrentUser.AccountBalance)+200*(-1));

        break;
    case _400:
        CurrentUser.AccountBalance=to_string(stoi(CurrentUser.AccountBalance)+400*(-1));

        break;
    case _600:
        CurrentUser.AccountBalance=to_string(stoi(CurrentUser.AccountBalance)+600*(-1));

        break;
    case _800:
        CurrentUser.AccountBalance=to_string(stoi(CurrentUser.AccountBalance)+800*(-1));
        break;
    case _1000:
        CurrentUser.AccountBalance=to_string(stoi(CurrentUser.AccountBalance)+1000*(-1));
        break;
    default:
        break;
    }    
        if(stoi(CurrentUser.AccountBalance)<0) 
        {
            cout<<"enter amount less than or equal your account balance\n!";
            QuickWithDraw(vDataOfClients);
        }
        cout<<"\nyour account balance is "<<CurrentUser.AccountBalance<<endl;
         UpdateData(vDataOfClients);
        SaveDataInFile(vDataOfClients);
        vDataOfClients=StoreDataOfClients( ReciveDataFromFile("MyFile.txt") ,"#//#");
    }
char c;
cout<<"press any key (character) to go to back menue.......";
cin.ignore(100,'\n');
cin.get(YorN);
}
void Deposit(vector <sData> &vDataOfClients)
{   
    char YorN;
    int Dep;
    PrintYourAccount(CurrentUser);
    cout<<"\n\nplease enter Deposite Amount ? ";
    cin>>Dep;
    if (Dep<0)
    {
        cout<<"enter positive number! \n";
        Deposit(vDataOfClients);
    }
    cout<<"Are you sure you want perform this action, y/n ? ";
    cin.ignore(100,'\n');
    cin.get(YorN);
    if(YorN=='y' || YorN=='Y')
    {
        CurrentUser.AccountBalance=to_string(stoi(CurrentUser.AccountBalance)+Dep);
        cout<<"\nyour account balance is "<<CurrentUser.AccountBalance<<endl;
        UpdateData(vDataOfClients);
        SaveDataInFile(vDataOfClients);
        vDataOfClients=StoreDataOfClients( ReciveDataFromFile("MyFile.txt") ,"#//#");
    }
    char c;
cout<<"press any key (character) to go to back menue.......";
cin.ignore(100,'\n');
cin.get(c);
}
void CheckBalance(vector <sData> &vDataOfClients)
{
   for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<setw(40)<<"check balance\n";
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<"your balance is "<<CurrentUser.AccountBalance<<endl;
   }

void main_menu( vector <sData> &vDataOfClients)//for transication menu
{
    TransactionsMenuScreen();
    short option;
    cout<<"Choose What do you want to do ? [1 to 4] ? ";
    cin>>option;
    switch ((enTransictionMenu)option)
    {
    
    case enTransictionMenu::deposit:
        DepositScreen();
        Deposit(vDataOfClients);
        break;
    case enTransictionMenu::NormalDraw:
        NormalWithDraw(vDataOfClients);
        break;
    case enTransictionMenu::QuickDraw:
        QuickWithDrawScreen();
        QuickWithDraw(vDataOfClients);
        break;
    case enTransictionMenu::check_balance:
        CheckBalance(vDataOfClients);
        char c;
        cout<<"press any key (character) to go to back menue.......";
        cin.ignore(100,'\n');
        cin.get(c);
        break;
    case enTransictionMenu::LogOut:
         Login(vDataOfClients);
    
    }
    main_menu(vDataOfClients);
}



vector<string> ReciveDataFromFile(string FileName)
{
    fstream ClientsData;
    vector<string> vData;
    string line;
    ClientsData.open(FileName, ios::in);
    if (ClientsData.is_open()) {
        while (getline(ClientsData, line))
        {
            vData.push_back(line);
        }
        ClientsData.close();
    }else cout<<"error in opening file\n";

    return vData;
}
sData StoreDataInStruct( vector <string> vWords)
{
    sData DataOfClient;
    DataOfClient.AccountNumber=vWords[0];
     DataOfClient.PinCode=vWords[1];
     DataOfClient.Name=vWords[2];
     DataOfClient.Phone=vWords[3];
     DataOfClient.AccountBalance=vWords[4];
     return DataOfClient;
}

vector<string> split(string sWord ,string delimiter)//to convert data of client that exist in file to words in vector
{
    vector <string> vWords;
    string word;
    int pos;
    while((pos=sWord.find(delimiter))!=sWord.npos)
    {
         word=sWord.substr(0,pos);
         if(word!="")vWords.push_back(word);
         sWord.erase(0,pos+delimiter.length()); 
    }
     if(sWord!="")vWords.push_back(sWord);
     
     return vWords;
}
vector<sData> StoreDataOfClients( vector<string> sDataOfClients ,string delimiter)
{
     vector <sData> stDataOfClients;
     vector <string> vWords;
     sData DataOfClient;
    for(int i=0 ; i<sDataOfClients.size() ; i++)
    {
      vWords=split( sDataOfClients[i] ,delimiter);
      DataOfClient=StoreDataInStruct( vWords);
      stDataOfClients.push_back(DataOfClient);
    }
    return stDataOfClients;
}


string join_string(vector <string> &Vector,string delimiter)
{
       string sWord="";
       for(string &word : Vector)
       {
        sWord+=word+delimiter;
       }
       
       return sWord.substr(0,sWord.length()-delimiter.length());
}
void StoreClientData(vector<sData> &vDateOfClient);
vector<string> ReciveDataFromFile(string FileName);
void LoginScreen();
bool IsValidLogin(vector<sData> &vPrivacyDate,sData &stPrivacyDate);
void Login( vector <sData> &vDataOfClients);
bool IsPasswordFound(vector<sData> &vPrivacyDate, string password);
int main()
{
    vector <sData> stDataOfClients;
    stDataOfClients=StoreDataOfClients( ReciveDataFromFile("MyFile.txt") ,"#//#");
    Login( stDataOfClients);
    //NewLogin(vPrivacyDate);
    return 0;
}
void LoginScreen() {
  // Print top border
  cout << "_______________________________\n\n" ;

  // Print "Login Screen" centered
  cout << setw(20) << setfill(' ')  // Use spaces for centering
       << "Login Screen" << endl;

  // Print bottom border
cout << "_______________________________\n\n" ;

  // Add a return statement for clarity (optional)
  return;
}

bool IsValidLogin(vector<sData> &vPrivacyDate,sData &stPrivacyDate)
{
      
     for (short i = 0; i < vPrivacyDate.size(); i++)
     {
        if(vPrivacyDate[i].AccountNumber==stPrivacyDate.AccountNumber && vPrivacyDate[i].PinCode==stPrivacyDate.PinCode)
        {
            FailuerType="";
            return true;
        }
        else if (vPrivacyDate[i].AccountNumber!=stPrivacyDate.AccountNumber && vPrivacyDate[i].PinCode==stPrivacyDate.PinCode){
            FailuerType="Invalid account number\n";
        }
        else if (vPrivacyDate[i].AccountNumber==stPrivacyDate.AccountNumber && vPrivacyDate[i].PinCode!=stPrivacyDate.PinCode){
            FailuerType="Invalid pin code\n";
        }
        else if (vPrivacyDate[i].AccountNumber!=stPrivacyDate.AccountNumber && vPrivacyDate[i].PinCode!=stPrivacyDate.PinCode){
            FailuerType="Invalid account number/pin code!\n";
        }
     }
   return false;      
}
void Login(vector <sData> &vDataOfClients)
{
    LoginScreen();
    cout<<FailuerType<<endl;
    ReadLoginData(vDataOfClients);
    StoreClientData(vDataOfClients);
    if (IsValidLogin(vDataOfClients,CurrentUser))
    {
         StoreClientData(vDataOfClients);
         main_menu( vDataOfClients);
    }
    else {
        cin.ignore(1,'\n');
        Login(vDataOfClients);
    }
}
void StoreClientData(vector<sData> &vDataOfClient)
{
    for(int i=0 ; i<vDataOfClient.size() ; i++)
    {
        if( CurrentUser.PinCode==vDataOfClient[i].PinCode)
        {
            CurrentUser.Name=vDataOfClient[i].Name;
            CurrentUser.AccountBalance=vDataOfClient[i].AccountBalance;
            CurrentUser.Phone=vDataOfClient[i].Phone;
        }
    }          
}
void UpdateData(vector<sData> &vDataOfClient)
{
    for(sData &DataOfClient : vDataOfClient)
    {
        if (CurrentUser.PinCode==DataOfClient.PinCode)
        {
            DataOfClient=CurrentUser;
        }
        
    }
}

