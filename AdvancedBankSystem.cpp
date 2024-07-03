
#include <string>
#include <vector>
#include <fstream>
#include<iomanip>
#include<sstream>
#include <limits>
#include <iostream>
using namespace std;
string FailuerType;
enum enTHeOperationType{ShowClientList=1,AddNewClient=2,DeleteClient=3,UpdateClientInfo=4,FindClient=5,Transations=6,Mange_Users=7,Exist=8};
enum enTransictionMenu{deposit=1,withDraw=2,totalBalances=3,mainMenu=4};
enum enMangeUsuers{List=1,Add=2, Delete=3, Update=4, Find=5, Main_Menu=6};
struct sData
{
    string PinCode,AccountNumber,Name,Phone,AccountBalance;
};
struct PrivacyDate{
    string name, password,permissions;
};
struct sAccess{
    bool find,update,_Delete,manage,transaction,show,add;
};
string user_name;//who did login
void MainMenuScreen()
{
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<setw(40)<<"Main Menue Screen\n";
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<"\t  "<<"[1] Show Client List.\n";
    cout<<"\t  "<<"[2] Add New Client.\n";
    cout<<"\t  "<<"[3] Delete Client.\n";
    cout<<"\t  "<<"[4] Update Client Info.\n";
    cout<<"\t  "<<"[5] Find Client.\n";
    cout<<"\t  "<<"[6] transactions.\n";
    cout<<"\t  "<<"[7] Mange Users.\n";
    cout<<"\t  "<<"[8] Logout.\n";
     for(short i=0 ; i<60 ; i++){cout<<"=";}
     cout<<endl;
}
void PrintData( vector <sData> &stDataOfClients)
{
   cout<<"\n\t\t\t\t\t\tClient List ("<<stDataOfClients.size()<<") Client(s) \n";
   cout<<"___________________________________________________________________________________________________________________________________________\n\n";
   cout<<setw(15)<<"|"<<"Account Number"<<setw(10)<<"|"<<"Pin Code"<<setw(15)<<"|"<<"Client Name"<<setw(12)<<"|"<<"Phone"<<setw(30)<<"|Balance"<<endl;
    cout<<"__________________________________________________________________________________________________________________________________________\n\n";
    for(int i=0 ; i<stDataOfClients.size() ; i++)
    {
    cout<<setw(15)<<"|"<<stDataOfClients[i].AccountNumber<<setw(21)<<"|"<<stDataOfClients[i].PinCode<<setw(19)<<"|"<<stDataOfClients[i].Name<<setw(16)<<"|"<<stDataOfClients[i].Phone<<setw(20)<<"|"<<stDataOfClients[i].AccountBalance;
    cout<<endl;
    }
char c;
cout<<"press any key (character) to go to back menue.......";
cin.ignore(100,'\n');
cin.get(c);
}
void PrintData2( vector <sData> &stDataOfClients)//for menu of transactions
{
   cout<<"\n\t\t\t\t\t\tClient List ("<<stDataOfClients.size()<<") Client(s) \n";
   cout<<"___________________________________________________________________________________________________________________________________________\n\n";
   cout<<setw(15)<<"|"<<"Account Number"<<setw(40)<<"|"<<"Client Name"<<setw(12)<<"Balance"<<endl;
    cout<<"__________________________________________________________________________________________________________________________________________\n\n";
    for(int i=0 ; i<stDataOfClients.size() ; i++)
    {
    cout<<setw(15)<<"|"<<stDataOfClients[i].AccountNumber<<setw(40)<<"|"<<stDataOfClients[i].Name<<setw(12)<<"|"<<stDataOfClients[i].AccountBalance;
    cout<<endl;
    }
}
void PrintYourAccount(sData ClientData)
{
    cout<<"----------------------------------------------------\n";
    cout<<"Account Number : "<<ClientData.AccountNumber<<endl;
            cout<<"Pin Code : "<<ClientData.PinCode<<endl;
            cout<<"Name : "<<ClientData.Name<<endl;
            cout<<"Account Balance : "<<ClientData.AccountBalance<<endl;
            cout<<"----------------------------------------------------\n";
}
bool PrintAccountClient(vector <sData> &stDataOfClients, string account_number)
{
    cout<<"\n\nThe Following are The Client details:\n \n";
    for(int i=0 ; i<stDataOfClients.size() ; i++)
    {
        if(account_number==stDataOfClients[i].AccountNumber)
        {
            PrintYourAccount(stDataOfClients[i]); 
            return true;
        }
    }
    return false;
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
sData UpdateClientData(string account_number)//With out Account number
{
    sData DataOfClient;
    cout<<"Please Enter Client Data:\n\n";
    //cout<<"Enter Account Number? "; 
    DataOfClient.AccountNumber=account_number;
    cout<<"Enter PinCode? "; 
    cin>>DataOfClient.PinCode; 
    cout<<"Enter Name? "; 
    cin.ignore(1, '\n');
    getline(cin,DataOfClient.Name);
    cout<<"Enter Phone? "; 
    cin>>DataOfClient.Phone;
    cout<<"Enter Account Balance? "; 
    cin>>DataOfClient.AccountBalance; 
    cout<<endl<<endl;
    return DataOfClient;
}
sData AddClientData()//With  Account number
{
    sData DataOfClient;
    cout<<"\nPlease Enter Client Data:\n\n";
    cout<<"Enter Account Number? "; 
    cin>>DataOfClient.AccountNumber;
    cout<<"Enter PinCode? "; 
    cin>>DataOfClient.PinCode; 
    cout<<"Enter Name? "; 
    cin.ignore(1,'\n');
    getline(cin,DataOfClient.Name);
    cout<<"Enter Phone? "; 
    cin>>DataOfClient.Phone;
    cout<<"Enter Account Balance? "; 
    cin>>DataOfClient.AccountBalance; 
    cout<<endl<<endl;
    return DataOfClient;
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
void UpdateDataOfClient(vector <sData> &stDataOfClients, string account_number)
{
    
    for(sData &DataOfClient : stDataOfClients)
    {
        if(account_number==DataOfClient.AccountNumber)
        { 
            DataOfClient= UpdateClientData(account_number); 
        }
    }
    SaveDataInFile(stDataOfClients);
}
void DeleteAccountScreen()
{
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<setw(40)<<"Delete Client Screen\n";
    for(short i=0 ; i<60 ; i++){cout<<"=";}
}
string ReadAccountNumber(vector <sData> &stDataOfClients)
{
    string account_number;
    cout<<"\n\nPlease enter AccountNumber ? ";
        cin>>account_number;

 while(!IsAccountNumberExist(stDataOfClients, account_number))
                            {
                                cout<<"Client with ["<<account_number<<"] already doesn't exist, Enter another account number ? \n";
                                cout<<"\n\nPlease enter valid AccountNumber ? ";
                                cin>>account_number;
                            }
    return account_number;                        
}
void find_client_screen()
{
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<setw(40)<<"Find Client Screen\n";
    for(short i=0 ; i<60 ; i++){cout<<"=";}
}
void EndScreen()
{
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<setw(40)<<"Program Ends\n";
    for(short i=0 ; i<60 ; i++){cout<<"=";}
}
void find_client(vector <sData> &stDataOfClients)
{
    string account_number;
    account_number=ReadAccountNumber(stDataOfClients);
    PrintAccountClient(stDataOfClients,  account_number);
    char c;
cout<<"press any key (character) to go to back menue.......";
cin.ignore(100,'\n');
cin.get(c);
}
void DeleteAccount(vector <sData> &stDataOfClients )
{   
    string YorN;
    string account_number;
    fstream UpdateData;
    UpdateData.open("MyFile.txt", ios::out );//write mode without append 
    
       account_number=ReadAccountNumber(stDataOfClients);

        for(int i=0 ; i<stDataOfClients.size() ; i++)
    {
        if(account_number==stDataOfClients[i].AccountNumber)
        {
            PrintYourAccount(stDataOfClients[i]);
            cout<<"Are You sure delete this account number, [1]yes,[2]No";
            cin>>YorN;
            if(lower_all_string(YorN)=="yes")
            {  
            stDataOfClients.erase(i+stDataOfClients.begin());
            i--;
            } 
            else{
            UpdateData<<stDataOfClients[i].AccountNumber<<"#//#";
            UpdateData<<stDataOfClients[i].PinCode<<"#//#";
            UpdateData<<stDataOfClients[i].Name<<"#//#";
            UpdateData<<stDataOfClients[i].Phone<<"#//#";
            UpdateData<<stDataOfClients[i].AccountBalance<<endl;    
                }
            
        }
        else if(UpdateData.is_open())
        {
            UpdateData<<stDataOfClients[i].AccountNumber<<"#//#";
            UpdateData<<stDataOfClients[i].PinCode<<"#//#";
            UpdateData<<stDataOfClients[i].Name<<"#//#";
            UpdateData<<stDataOfClients[i].Phone<<"#//#";
            UpdateData<<stDataOfClients[i].AccountBalance<<endl;
        }
    }  
    UpdateData.close(); 
    char c;
cout<<"press any key (character) to go to back menue.......";
cin.ignore(100,'\n');
cin.get(c);

}
void AddingNewDataScreen()
{
      for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<setw(40)<<"Add New Clients Screen\n";
    for(short i=0 ; i<60 ; i++){cout<<"=";}
}
void AddingNewData(vector <sData> &stDataOfClients)
{
    sData DataOfClient;
    string YorN;
    do
    {
        DataOfClient= AddClientData(); 
    stDataOfClients.push_back(DataOfClient);
    SaveDataInFile(stDataOfClients);
    cout<<"Clients Added Successfully, do you Want add more Account clients ? 1]yes , 2]No ? ";
    cin>>YorN;
    } while (lower_all_string(YorN)=="yes");
    char c;
cout<<"press any key (character) to go to back menue.......";
cin.ignore(100,'\n');
cin.get(c); 
}
void UpdataClientInfoScreen()
{
    cout<<endl;
      for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<setw(40)<<"Update Client Info Screen\n";
    for(short i=0 ; i<60 ; i++){cout<<"=";}
}
void UpdataClientInfo(vector <sData> &stDataOfClients)
{
   string account_number;
      string YorN;
    do
    {
        account_number= ReadAccountNumber(stDataOfClients);
    cout<<endl;
     if(PrintAccountClient(stDataOfClients, account_number))//alse it checks on existing the account number
        {
             UpdateDataOfClient(stDataOfClients, account_number);
        }
    
    cout<<endl;    
    cout<<"Clients Added Successfully, do you Want add more Account clients ? 1]yes , 2]No ? ";
    cin>>YorN;
    } while (lower_all_string(YorN)=="yes");
    char c;
cout<<"press any key (character) to go to back menue.......";
cin.ignore(100,'\n');
cin.get(c);

}
vector<string> ReciveDataFromFile(string FileName);
sData StoreDataInStruct( vector <string> vWords);
vector<string> split(string sWord ,string delimiter=" ");
vector<sData> StoreDataOfClients( vector<string> sDataOfClients ,string delimiter=" ");
string join_string(vector <string> &Vector,string delimiter=" ");
void AddNewClientsScreen();
void AddNewClients(vector <sData> &stDataOfClients);

void TransactionsMenuScreen()
{
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<setw(40)<<"Main Menue Screen\n";
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<"\t  "<<"[1] Deposit.\n";
    cout<<"\t  "<<"[2] Withdraw.\n";
    cout<<"\t  "<<"[3] Total Balances.\n";
    cout<<"\t  "<<"[4] Main Menu.\n";
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
    cout<<endl;
}
void WithDrawScreen()
{
    cout<<endl;
      for(short i=0 ; i<60 ; i++){cout<<"_";}
    cout<<endl;
    cout<<setw(40)<<"WithDraw Screen\n";
    for(short i=0 ; i<60 ; i++){cout<<"_";}
    cout<<endl;
}
void WithDraw(vector <sData> &stDataOfClients)
{
    WithDrawScreen();
    char YorN;
    string account_number;
    int Dep;
    account_number=ReadAccountNumber(stDataOfClients);
    PrintAccountClient(stDataOfClients,  account_number);
    cout<<"\n\nplease enter Deposite Amount ? ";
    cin>>Dep;
    for(sData &ClientData : stDataOfClients)
    {
        if(account_number==ClientData.AccountNumber){ClientData.AccountBalance=to_string(stoi(ClientData.AccountBalance)+Dep*(-1));}
    }
    cout<<"Are you sure you want perform this action, y/n ? ";
    cin.ignore(100,'\n');
    cin.get(YorN);

    if(YorN=='y' || YorN=='Y')
    {
        SaveDataInFile(stDataOfClients);
        stDataOfClients=StoreDataOfClients( ReciveDataFromFile("MyFile.txt") ,"#//#");
    }
char c;
cout<<"press any key (character) to go to back menue.......";
cin >>c;
}
void Deposit(vector <sData> &stDataOfClients)
{
    DepositScreen();
    char YorN;
    string account_number;
    int Dep;
    account_number=ReadAccountNumber(stDataOfClients);
    PrintAccountClient(stDataOfClients,  account_number);
    cout<<"\n\nplease enter Deposite Amount ? ";
    cin>>Dep;
    for(sData &ClientData : stDataOfClients)
    {
        if(account_number==ClientData.AccountNumber)
        {ClientData.AccountBalance=to_string(stoi(ClientData.AccountBalance)+Dep);}
    }
    cout<<"Are you sure you want perform this action, y/n ? ";
    cin.ignore(100,'\n');
    cin.get(YorN);

    if(YorN=='y' || YorN=='Y')
    {
        SaveDataInFile(stDataOfClients);
        stDataOfClients=StoreDataOfClients( ReciveDataFromFile("MyFile.txt") ,"#//#");
    }
    char c;
cout<<"press any key (character) to go to back menue.......";
cin.ignore(100,'\n');
cin.get(c);

}
int TotalBalances(vector <sData> &stDataOfClients)
{
   int sum=0;
   for(sData Balance : stDataOfClients)
   {
    sum+=stoi(Balance.AccountBalance);
   }
   return sum;
}
void main_menu( vector <sData> &stDataOfClients,vector<PrivacyDate> &vPrivacyDate);
void main_menu2( vector <sData> &stDataOfClients,vector<PrivacyDate> &vPrivacyDate)//for transication menu
{
    TransactionsMenuScreen();
    short option;
    cout<<"Choose What do you want to do ? [1 to 4] ? ";
    cin>>option;
    switch ((enTransictionMenu)option)
    {
    
    case enTransictionMenu::deposit:
        Deposit(stDataOfClients);
        break;
    case enTransictionMenu::withDraw:
        WithDraw(stDataOfClients);
        break;
    case enTransictionMenu::totalBalances:
        PrintData2(stDataOfClients);
        cout<<"Total balances = "<<TotalBalances(stDataOfClients)<<endl;
        break;
    case enTransictionMenu::mainMenu:
        MainMenuScreen();
        main_menu(stDataOfClients,vPrivacyDate);
        break;
    
    }
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
PrivacyDate StoreDataInStruct_PrivacyDate( vector <string> vWords)
{
    PrivacyDate DataOfClient;
    DataOfClient.name=vWords[0];
     DataOfClient.password=vWords[1];
      DataOfClient.permissions=vWords[2];
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
vector<PrivacyDate> StoreDataOfClients_privacyDate( vector<string> sDataOfClients ,string delimiter)
{
     vector <PrivacyDate> stDataOfClients;
     vector <string> vWords;
     PrivacyDate DataOfClient;
    for(int i=0 ; i<sDataOfClients.size() ; i++)
    {
      vWords=split( sDataOfClients[i] ,delimiter);
      DataOfClient=StoreDataInStruct_PrivacyDate( vWords);
      stDataOfClients.push_back(DataOfClient);
    }
    return stDataOfClients;
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
void AddNewClientsScreen()
{
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<setw(40)<<"Update Client Info Screen\n";
    for(short i=0 ; i<60 ; i++){cout<<"=";}
}
void AddNewClients(vector <sData> &stDataOfClients)
{
    string account_number;
    cout<<"Enter your Account Number ! ";
    cin>>account_number;
    while(IsAccountNumberExist(stDataOfClients, account_number))
    {
        cout<<"client with ["<<account_number<<"] Already exists, enter another account number ? ";
        cin>>account_number;
    }

}
vector<string> ReciveDataFromFile(string FileName);
vector<PrivacyDate> StoreDataOfClients_privacyDate( vector<string> sDataOfClients ,string delimiter);
void LoginScreen();
PrivacyDate ReadPrivacyDate();
bool IsValidLogin(vector<PrivacyDate> vPrivacyDate,PrivacyDate stPrivacyDate);
void Login(vector<PrivacyDate> &vPrivacyDate, vector <sData> &stDataOfClients);
void MangeUsersScreen();
void PrintPrivacyData( vector <PrivacyDate> &stDataOfClients);
void AddScreen();
bool IsNameFound(vector<PrivacyDate> &vPrivacyDate, string name);
bool IsPasswordFound(vector<PrivacyDate> &vPrivacyDate, string password);
void access(string user_name);
void NewLogin(vector<PrivacyDate> &vPrivacyDate);
string ReadUserName(vector<PrivacyDate> &vPrivacyDate);
void find_client_privacydate(vector <PrivacyDate> &vPrivacyDate);
void print_client_privacydate(PrivacyDate sPrivacyDate);
sAccess recieve_access(string user_name);
bool have_full_access(vector<PrivacyDate> &vPrivacyDate,string user_name);
void DeleteAccount_privacydate(vector <PrivacyDate> &vPrivacyDate );
void UpdataClientPrivacyDataScreen();
void SaveDataInFile_PrivacyData(vector <PrivacyDate> &vPrivacyDate);
PrivacyDate UpdateClientData_PrivacyData(string user_name);
void UpdateDataOfClient_PrivacyData(vector <PrivacyDate> &vPrivacyDate, string user_name);
void UpdataClientPrivacyData(vector <PrivacyDate> &vPrivacyDate);
void MangeUsers( vector <sData> &stDataOfClients,vector<PrivacyDate> &vPrivacyDate);
void main_menu( vector <sData> &stDataOfClients, vector<PrivacyDate> &vPrivacyDate);
int main()
{
    vector <sData> stDataOfClients;
    vector<PrivacyDate> vPrivacyDate;
    vPrivacyDate=StoreDataOfClients_privacyDate( ReciveDataFromFile("UsersFile.txt") ,"#//#");
    stDataOfClients=StoreDataOfClients( ReciveDataFromFile("MyFile.txt") ,"#//#");
    Login( vPrivacyDate,stDataOfClients);
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
PrivacyDate ReadPrivacyDate()
{
    PrivacyDate stPrivacyDate;
    
    cout<<"Enter your Name: ";
    cin>>stPrivacyDate.name;
    user_name=stPrivacyDate.name;
    cout<<"Enter your Password: ";
    cin>>stPrivacyDate.password;
    return stPrivacyDate;
}
bool IsValidLogin(vector<PrivacyDate> vPrivacyDate,PrivacyDate stPrivacyDate)
{
      
     for (short i = 0; i < vPrivacyDate.size(); i++)
     {
        if(vPrivacyDate[i].name==stPrivacyDate.name && vPrivacyDate[i].password==stPrivacyDate.password)
        {
            FailuerType="";
            return true;
        }
        else if (vPrivacyDate[i].name!=stPrivacyDate.name && vPrivacyDate[i].password==stPrivacyDate.password){
            FailuerType="Invalid UserName\n";
        }
        else if (vPrivacyDate[i].name==stPrivacyDate.name && vPrivacyDate[i].password!=stPrivacyDate.password){
            FailuerType="Invalid Password\n";
        }
        else if (vPrivacyDate[i].name!=stPrivacyDate.name && vPrivacyDate[i].password!=stPrivacyDate.password){
            FailuerType="Invalid UserName/Password!\n";
        }
     }
   return false;      
}
void Login(vector<PrivacyDate> &vPrivacyDate,vector <sData> &stDataOfClients)
{
    PrivacyDate stPrivacyDate;
    LoginScreen();
    cout<<FailuerType<<endl;
    stPrivacyDate=ReadPrivacyDate();
    if (IsValidLogin(vPrivacyDate,stPrivacyDate))
    {
         main_menu( stDataOfClients,vPrivacyDate);
    }
    else {
        cin.ignore(1,'\n');
        Login(vPrivacyDate,stDataOfClients);
    }
}
void MangeUsersScreen()
{
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<setw(40)<<"Mange Users Menue Screen\n";
    for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<"\t  "<<"[1] List Users.\n";
    cout<<"\t  "<<"[2] Add New User.\n";
    cout<<"\t  "<<"[3] Delete User.\n";
    cout<<"\t  "<<"[4] Update User.\n";
    cout<<"\t  "<<"[5] Find User.\n";
    cout<<"\t  "<<"[6] Main Menue.\n";
     for(short i=0 ; i<60 ; i++){cout<<"=";}
     cout<<endl;
}
void PrintPrivacyData( vector <PrivacyDate> &stDataOfClients)
{
    char c;
   cout<<"\n\t\t\t\t\t\tUsers List ("<<stDataOfClients.size()<<") User(s) \n";
   cout<<"___________________________________________________________________________________________________________________________________________\n\n";
   cout<<setw(15)<<"|"<<"Name"<<setw(10)<<"|"<<"Password"<<setw(15)<<"|"<<"Permissions"<<endl;
    cout<<"__________________________________________________________________________________________________________________________________________\n\n";
    for(int i=0 ; i<stDataOfClients.size() ; i++)
    {
    cout<<setw(15)<<"|"<<stDataOfClients[i].name<<setw(21)<<"|"<<stDataOfClients[i].password<<setw(19)<<"|"<<stDataOfClients[i].permissions;
    cout<<endl;
    }
    cout<<"press any key to go to Back Menue..... ";
    cin.ignore(100,'\n');
    cin.get(c);
}
void AddScreen()
{
     cout<<endl;
      for(short i=0 ; i<60 ; i++){cout<<"_";}
    cout<<endl;
    cout<<setw(40)<<"Add New Screen\n";
    for(short i=0 ; i<60 ; i++){cout<<"_";}
    cout<<endl;
}
bool IsNameFound(vector<PrivacyDate> &vPrivacyDate, string name)
{
    for(int i=0 ; i<vPrivacyDate.size() ; i++)
    {
        if(name==vPrivacyDate[i].name)
        {
            return true;
        }
    }
    return false;
}
bool IsPasswordFound(vector<PrivacyDate> &vPrivacyDate, string password)
{
    for(int i=0 ; i<vPrivacyDate.size() ; i++)
    {
        if( password==vPrivacyDate[i].password)
        {
            return true;
        }
    }
    return false;
}
void access(string user_name)
{
    ofstream access;
    access.open(user_name);
    if (access.is_open())
    {
        char c;
        cout<<"note that 1 -> true/yes , 0 -> false/no \n";
        cout<<"Do you want give access to \n";
        cout<<"show client list ? 1/0! ";
        cin.ignore(100,'\n');
        cin.get(c);
        access<<c<<endl;
        cout<<"add new client ? 1/0! ";
        cin.ignore(100,'\n');
        cin.get(c);
        access<<c<<endl;
        cout<<"delete client ? 1/0! ";
        cin.ignore(100,'\n');
        cin.get(c);
        access<<c<<endl;
        cout<<"update client ? 1/0! ";
        cin.ignore(100,'\n');
        cin.get(c);
        access<<c<<endl;
         cout<<"find client  ? 1/0! ";
        cin.ignore(100,'\n');
        cin.get(c);
        access<<c<<endl;
        cout<<"transiction client ? 1/0! ";
        cin.ignore(100,'\n');
        cin.get(c);
        access<<c<<endl;
        cout<<"manage usesrs ? 1/0! ";
        cin.ignore(100,'\n');
        cin.get(c);
        access<<c;
        access.close();
    }else cout<<"error in opening file\n";
    
}
sAccess recieve_access(string user_name)
{
    ifstream access;
    sAccess Access;
    access.open(user_name);
    if (access.is_open())
    { 
        access>>Access.show;
        access>>Access.add;
        access>>Access._Delete;
        access>>Access.update;
        access>>Access.find;
        access>>Access.transaction;
        access>>Access.manage;
        access.close();
    }else cout<<user_name<<" has full access . \n";
    return Access;
}
void NewLogin(vector<PrivacyDate> &vPrivacyDate)
{
    fstream UsersFile;
    UsersFile.open("UsersFile.txt",ios::out | ios::app | ios::in);
    PrivacyDate stPrivacyDate;
    char c;
do{
    if (UsersFile.is_open())
    {
        AddScreen();
        cout<<"Adding New User\n";
        cout<<"Enter UserName: ";
        cin>>stPrivacyDate.name;
        if(IsNameFound(vPrivacyDate,stPrivacyDate.name))
        {
            cout<<"User With ["<<stPrivacyDate.name<<"] already Exist, Enter another user name! \n";
            UsersFile.close();
            NewLogin(vPrivacyDate);
        }
    while(true){    
        cout<<"Enter The Password: ";
        cin>>stPrivacyDate.password;
        if(IsPasswordFound(vPrivacyDate,stPrivacyDate.password))
        {
            cout<<"This Password ["<<stPrivacyDate.name<<"] already Exist, Enter another Password! \n";
            continue;
        }
        break;
    }
        UsersFile<<stPrivacyDate.name<<"#//#"<<stPrivacyDate.password;
        cout<<"Do you want give full access? Y/N! ";
        cin.ignore(100,'\n');
        cin.get(c);
        if (c=='Y' or c=='y')
        {
            UsersFile<<"#//#"<<"-1\n";
        }else
        { 
            UsersFile<<"#//#"<<"1\n";
            access(stPrivacyDate.name);
        }
        vPrivacyDate=StoreDataOfClients_privacyDate( ReciveDataFromFile("UsersFile.txt") ,"#//#");
        cout<<"User Added Succefully, Do you want to add monre users? Y/N! ";
        cin.ignore(100,'\n');
        cin.get(c);
    }
}while(c=='Y' or c=='y');                                                                                         
    UsersFile.close();
}
bool have_full_access(vector<PrivacyDate> &vPrivacyDate,string user_name)
{
    for(int i=0 ; i<vPrivacyDate.size() ; i++)
    {
        if(user_name==vPrivacyDate[i].name)
        {
            return vPrivacyDate[i].permissions=="-1" ? true : false;
        }
    }
    return false;
}
string ReadUserName(vector <PrivacyDate> &vPrivacyDate)
{
    string name;
cout<<"Enter user name ? ";
    cin.ignore();
    getline(cin,name);
        while (!IsNameFound(vPrivacyDate,name))
        {
            cout<<"Enter a valid user name! ";
            cin.ignore();
            getline(cin,name);
        }
    
    return name;
}
void print_client_privacydate(PrivacyDate sPrivacyDate)
{
     cout<<"user_name: "<<sPrivacyDate.name<<endl;
     cout<<"password: "<<sPrivacyDate.password<<endl;
     cout<<"permission: "<<sPrivacyDate.permissions<<endl;
}
void find_client_privacydate(vector <PrivacyDate> &vPrivacyDate)
{
    string user_name;
    user_name=ReadUserName(vPrivacyDate);
    for(int i=0 ; i<vPrivacyDate.size() ; i++)
    {
        if(user_name==vPrivacyDate[i].name)
        {
            print_client_privacydate(vPrivacyDate[i]);
        }
    }
}
void DeleteAccount_privacydate(vector <PrivacyDate> &vPrivacyDate )
{   
    string YorN;
    string user_name;
    fstream UpdateData;
    UpdateData.open("UsersFile.txt", ios::out  );//write mode without append 
    
       user_name=ReadUserName(vPrivacyDate);

        for(int i=0 ; i<vPrivacyDate.size() ; i++)
    {
        if(user_name==vPrivacyDate[i].name)
        {
            print_client_privacydate(vPrivacyDate[i]);
            cout<<"Are You sure delete this account , [1]yes,[2]No ";
            cin>>YorN;
            if(lower_all_string(YorN)=="yes"  or YorN=="1")
            {  
            vPrivacyDate.erase(i+vPrivacyDate.begin());
            i--;
            } 
            else if (UpdateData.is_open()){
            UpdateData<<vPrivacyDate[i].name<<"#//#";
            UpdateData<<vPrivacyDate[i].password<<"#//#";
            UpdateData<<vPrivacyDate[i].permissions<<"#//#\n";

            }
            
        }
        else if(UpdateData.is_open())
        {
            UpdateData<<vPrivacyDate[i].name<<"#//#";
            UpdateData<<vPrivacyDate[i].password<<"#//#";
            UpdateData<<vPrivacyDate[i].permissions<<"#//#\n";
        }
        else cout<<"Error in opening file\n";
    }  
   UpdateData.close(); 
}
void UpdataClientPrivacyDataScreen()
{
    cout<<endl;
      for(short i=0 ; i<60 ; i++){cout<<"=";}
    cout<<endl;
    cout<<setw(40)<<"Update Client Info Screen\n";
    for(short i=0 ; i<60 ; i++){cout<<"=";}
}
void SaveDataInFile_PrivacyData(vector <PrivacyDate> &vPrivacyDate)
{
    fstream UpdateData;
    UpdateData.open("UsersFile.txt", ios::out);//write mode without append 
    
    for(int i=0 ; i<vPrivacyDate.size() ; i++)
    {
        
         if(UpdateData.is_open())
        {
            UpdateData<<vPrivacyDate[i].name<<"#//#";
            UpdateData<<vPrivacyDate[i].password<<"#//#";
            UpdateData<<vPrivacyDate[i].permissions<<"#//#\n";
        }
        //
    }
     UpdateData.close();
}

PrivacyDate UpdateClientData_PrivacyData(string user_name)//With out Account number
{
    PrivacyDate DataOfClient;
    char c;
    DataOfClient.name=user_name;
    cout<<"______________________________\n";
    cout<<"\nEnter The new Password ? "; 
    cin>>DataOfClient.password;
    cout<<"do you want give him full access ? Y/N! "; 
    cin.ignore(100,'\n');
    cin.get(c);
    if(c=='Y' or c=='y')DataOfClient.permissions="-1";
    else 
    {
        DataOfClient.permissions="1";
        access(user_name);
    } 
    cout<<endl<<endl;
    return DataOfClient;
}

void UpdateDataOfClient_PrivacyData(vector <PrivacyDate> &vPrivacyDate, string user_name)
{
    
    for(PrivacyDate &DataOfClient : vPrivacyDate)
    {
        if(user_name==DataOfClient.name)
        {
            print_client_privacydate(DataOfClient);         
            DataOfClient= UpdateClientData_PrivacyData(user_name); 
        }
    }
    SaveDataInFile_PrivacyData(vPrivacyDate);
}

void UpdataClientPrivacyData(vector <PrivacyDate> &vPrivacyDate)
{
   string user_name;
      string YorN;
    do
    {
        user_name= ReadUserName(vPrivacyDate);
    cout<<endl;
     if(IsNameFound(vPrivacyDate,user_name))//alse it checks on existing the account number
        {
             UpdateDataOfClient_PrivacyData(vPrivacyDate, user_name);
        }
    
    cout<<endl;    
    cout<<"Clients Added Successfully, do you Want add more Account clients ? 1]yes , 2]No ? ";
    cin>>YorN;
    } while (lower_all_string(YorN)=="yes");
}
void MangeUsers( vector <sData> &stDataOfClients,vector<PrivacyDate> &vPrivacyDate)//for transication menu
{
    sAccess access;
    char c;
    MangeUsersScreen();
    access=recieve_access(user_name);
    short option;
    cout<<"Choose What do you want to do ? [1 to 6] ? ";
    cin>>option;
    switch ((enMangeUsuers)option)
    {
    
    case enMangeUsuers::List:
       if (access.show or have_full_access(vPrivacyDate,user_name) ) {
                PrintPrivacyData(vPrivacyDate);
            } else {
                cout << "You do not have access to list privacy data.\n";
               cout<<"press any key (character) to go to Back Menue..... ";
                cin.ignore(100,'\n');
                cin.get(c);
            }
        break;
    case enMangeUsuers::Add:
    if (access.add or have_full_access(vPrivacyDate,user_name)) {
                NewLogin(vPrivacyDate);
            } else {
                cout << "You do not have access to add privacy data.\n";
                cout<<"press any key (character) to go to Back Menue..... ";
                cin.ignore(100,'\n');
                cin.get(c);
   
            }
        break;
        case enMangeUsuers::Find:
    if (access.find or have_full_access(vPrivacyDate,user_name)) {
             find_client_privacydate(vPrivacyDate);
            } else {
                cout << "You do not have access to find privacy data.\n";
                cout<<"press any key (character) to go to Back Menue..... ";
                cin.ignore(100,'\n');
                cin.get(c);
            }
        break;
    case enMangeUsuers::Delete:
    if (access.find or have_full_access(vPrivacyDate,user_name)) {
             DeleteAccount_privacydate(vPrivacyDate);
            } else {
                cout << "You do not have access to delete privacy data.\n";
                cout<<"press any key (character) to go to Back Menue..... ";
                cin.ignore(100,'\n');
                cin.get(c);
   
            }
        break;
    case enMangeUsuers::Update:
    if (access.find or have_full_access(vPrivacyDate,user_name)) {
             UpdataClientPrivacyData(vPrivacyDate);
            } else {
                cout << "You do not have access to update privacy data.\n";
                cout<<"press any key to go to Back Menue..... ";
                cin.ignore(100,'\n');
                cin.get(c);
            }
        break;
         case enMangeUsuers::Main_Menu:
         main_menu( stDataOfClients, vPrivacyDate);
        break;
    }
    
}
void main_menu( vector <sData> &stDataOfClients, vector<PrivacyDate> &vPrivacyDate)
{
    MainMenuScreen();
    sAccess access;
    short option=0;
    cout<<"Choose What do you want to do ? [1 to 8] ? ";
    cin>>option;
    switch ((enTHeOperationType)option)
    {
    case enTHeOperationType::ShowClientList:
         PrintData( stDataOfClients);
         main_menu( stDataOfClients, vPrivacyDate);
    case enTHeOperationType::UpdateClientInfo:
        UpdataClientInfoScreen();
        UpdataClientInfo(stDataOfClients);
        stDataOfClients=StoreDataOfClients( ReciveDataFromFile("MyFile.txt") ,"#//#");
        main_menu( stDataOfClients, vPrivacyDate);
    case enTHeOperationType::AddNewClient:
        AddingNewDataScreen();
        AddingNewData(stDataOfClients);
        stDataOfClients=StoreDataOfClients( ReciveDataFromFile("MyFile.txt") ,"#//#");
        main_menu( stDataOfClients, vPrivacyDate);
    case enTHeOperationType::DeleteClient:
        DeleteAccountScreen();
        DeleteAccount(stDataOfClients );
        stDataOfClients=StoreDataOfClients( ReciveDataFromFile("MyFile.txt") ,"#//#");
        main_menu( stDataOfClients, vPrivacyDate);
    case enTHeOperationType::FindClient:
        find_client_screen();     
        find_client(stDataOfClients);
        main_menu( stDataOfClients, vPrivacyDate);
    case enTHeOperationType::Transations:
    access=recieve_access(user_name);
    if (access.transaction or have_full_access(vPrivacyDate,user_name)) {
             main_menu2(stDataOfClients,vPrivacyDate);//for transactions
        main_menu( stDataOfClients, vPrivacyDate);    
            } else {
                char c;
                cout << "You do not have access to transactions users data.\n";
                cout<<"press any key (character) to go to Back Menue..... ";
                cin.ignore(100,'\n');
                cin.get(c);
                main_menu( stDataOfClients, vPrivacyDate); 
            }
    case enTHeOperationType::Mange_Users:
    access=recieve_access(user_name);
    if (access.manage or have_full_access(vPrivacyDate,user_name)) {
             while (true)
    {
        MangeUsers( stDataOfClients,vPrivacyDate);
         vPrivacyDate=StoreDataOfClients_privacyDate( ReciveDataFromFile("UsersFile.txt") ,"#//#");
         MangeUsers( stDataOfClients,vPrivacyDate);
    }

            } else {
                char c;
                cout << "You do not have access to manage users data.\n";
                cout<<"press any key (character) to go to Back Menue..... ";
                cin.ignore(100,'\n');
                cin.get(c);
                main_menu( stDataOfClients, vPrivacyDate);  
            }
    case enTHeOperationType::Exist:
      //EndScreen();
      FailuerType="";
      Login(vPrivacyDate,stDataOfClients);
    }
}
