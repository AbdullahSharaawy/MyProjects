#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<iomanip>
#include <limits>
using namespace std;
enum enTHeOperationType{ShowClientList=1,AddNewClient=2,DeleteClient=3,UpdateClientInfo=4,FindClient=5,Transations=6,Exist=7};
enum enTransictionMenu{deposit=1,withDraw=2,totalBalances=3,mainMenu=4};
struct sData
{
    string PinCode,AccountNumber,Name,Phone,AccountBalance;
};
void StartPrograme();
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
    cout<<"\t  "<<"[7] Exist.\n";
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
            else{break;}
            
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
    cin>>YorN;
    if(YorN=='y' || YorN=='n')
    {
        SaveDataInFile(stDataOfClients);
        stDataOfClients=StoreDataOfClients( ReciveDataFromFile("MyFile.txt") ,"#//#");
    }
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
    cin>>YorN;
    if(YorN=='y' || YorN=='n')
    {
        SaveDataInFile(stDataOfClients);
        stDataOfClients=StoreDataOfClients( ReciveDataFromFile("MyFile.txt") ,"#//#");
    }
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
void main_menu( vector <sData> &stDataOfClients);
void main_menu2( vector <sData> &stDataOfClients)//for transication menu
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
        main_menu(stDataOfClients);
        break;
    
    }
}
void main_menu( vector <sData> &stDataOfClients)
{
    short option=0;
    cout<<"Choose What do you want to do ? [1 to 6] ? ";
    cin>>option;
    switch ((enTHeOperationType)option)
    {
    case enTHeOperationType::ShowClientList:
         PrintData( stDataOfClients);
         StartPrograme();
    case enTHeOperationType::UpdateClientInfo:
        UpdataClientInfoScreen();
        UpdataClientInfo(stDataOfClients);
        StartPrograme();
    case enTHeOperationType::AddNewClient:
        AddingNewDataScreen();
        AddingNewData(stDataOfClients);
        StartPrograme();
    case enTHeOperationType::DeleteClient:
        DeleteAccountScreen();
        DeleteAccount(stDataOfClients );
        StartPrograme();
    case enTHeOperationType::FindClient:
        find_client_screen();     
        find_client(stDataOfClients);
        StartPrograme();
    case enTHeOperationType::Transations:
        main_menu2(stDataOfClients);
        StartPrograme();    
    
    case enTHeOperationType::Exist:
      EndScreen();
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
    }

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
void StartPrograme()
{
     vector <sData> stDataOfClients;
     MainMenuScreen();
     stDataOfClients=StoreDataOfClients( ReciveDataFromFile("MyFile.txt") ,"#//#");
     main_menu(stDataOfClients);
}
int main()
{
    StartPrograme();
    return 0;
}
