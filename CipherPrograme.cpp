// File    :  CS112_A2_T4_20_20230522
// Purpose : a program containing 3 programs to cipher and decipher any text and the option to choose between them
// Author  : Abdullah Adel Eid Sharaawy ,Section 20 20230522
// Who did which cipher : Abdullah Adel Eid Sharaawy did all these ciphers
// Email   : abdallahsharawy200@gmail.com
// ID      : 20230522  
// Version : v1.0
// Date    : 19/03/2024
/*
     pseudo code
Function StartTHeProgram()
    enCipherType CipherType
    declare choise=0
    display "Which Cipher do you like to choose?"
    display "1- Rail_fence Cipher"
    display "2- Polybius Square Cipher"
    display "3- Baconian Cipher"
    display "4- Exist"
    do
        display "please enter a number from 1 to 4! "
        read choise
    switch (choise)
    case 1:
       StartRail_fenceCipher()    
        End Swithch
    case 2:
        StartPolybiusSquareCipher()
        End Swithch
    case 3:
        StartBaconianCipher()
        End Swithch
    case 4:
        End  Function
Function  ProcessingText( text)
Fnction ProcessingText( text)
    declare new_text=””
     for i = 0  to   length of text-1  
        if(isspace(text[i]) or isdigit(text[i]) or ispunct(text[i])) then continue
        add text[i] to new_text
    return new_text
End Function
Function print_matrix( matrix[][] ,  key, n_columns, original_text)
    n_columns= length of text that ProcessingText(original_text)  will return it 
     for r=0 to key-'0'-1 
          for  c=0 to n_columns-1 
               display "  ",matrix[r][c],"  "
           end for
     end for  
End Function 
 Function ReadText( message)
    Declare text=””
    Display message
    Read text
    return text
 End Function

Function ReadKey(message)
    declare key=’’
    declare n_key=0
    do
         display message
         read n_key
     while (n_key!=3 and n_key!=4)
     if n_key==3 then return '3'
     end if
     else return '4'
      end else
End Function
 Function InputMatrixWithStars(matrix[][] ,  key, n_columns)
       declare counter=0,sign=1
       declare index=0,R=0
       matrix[0][0]='*'                 
        for  c=0  to n_columns-1 
             if R==0 and c==0 then continue
             else if((add one to counter)==key-'0') then
                sign=sign * -1
                counter=1
             end else
             R= R+sign*1
             matrix[R][c]='*'
        end for
       for  r=0 to key-'0'-1 
             for c=0 to n_columns-1
                    If matrix[r][c]!='*' then matrix[r][c]='-'
                    End if
 End Function
Function InputMatrixWithCharactersV1(matrix[][] ,  key,int n_columns, text)
     declare index=0
      for c=0 to n_columns-1 
            for  r=0 to key-'0'-1
                   if(matrix[r][c]=='*') then
                        matrix[r][c]=text[index]
                        add one to index
                   end if
            end for
      end for
End Function
 Function InputMatrixWithCharactersV2(matrix[][] ,  key,int n_columns, text)
     declare index=0
      for r=0 to key-'0'-1 
            for  c=0 to n_columns-1
                   if(matrix[r][c]=='*') then
                        matrix[r][c]=text[index]
                        add one to index
                   end if
            end for
      end for
End Function
Function CipherText(matrix[][] ,  key, n_columns, text)
    InputMatrixWithStars(matrix ,  key, n_columns)
    InputMatrixWithCharactersV1(matrix ,  key, n_columns, text)
     declare cipher_text=""
     for r=0 to key-'0'-1 
            for  c=0 to n_columns-1
                    if(isalpha(matrix[r][c])) then
                           cipher_text+=matrix[r][c]
                    end if
            end for
     end for  
     return cipher_text
End Function
Function DecipherText(matrix[][] ,  key, n_columns, text)
    InputMatrixWithStars(matrix ,  key, n_columns)
    InputMatrixWithCharactersV2(matrix ,  key, n_columns, text)
     declare decipher_text=""
        for c=0 to n_columns-1 
            for  r=0 to key-'0'-1
                    if(isalpha(matrix[r][c])) then
                           decipher_text= decipher_text +matrix[r][c]
                    end if
            end for
        end for   
     return decipher_text
 End Function
Function StartRail_fenceCipher()
      declare original_text=””,new_text=””
      declare key=’’
      declare choise=0
      declare n_columns
      display"Welcome to Rail-fence Cipher"
      key=ReadKey("please enter your key! 3/4 ")
     original_text=ReadText("Please enter the message :  ")
    n_columns=length of original_text
     declare matrix=[][]
    display "What do you like to do today?"
    display "1- Cipher a message "
    display "2- Decipher a message "
    display "3- End"
    do
          display "please enter a number from 1 to 3! "
          read choise
     while (choise!=1 and choise!=2 and choise!=3 )
    switch (choise)
           case 1:
                new_text=CipherText( matrix ,  key,     n_columns,ProcessingText(original_text))
                print_matrix( matrix ,  key, n_columns,original_text)
                display "Plain:  ",original_text
                display "Cipher:  ",new_text
           end switch
           case 2:
                new_text=DecipherText( matrix ,  key, n_columns,ProcessingText(original_text));
                print_matrix( matrix ,  key, n_columns,original_text);
                display "Plain:  "<<original_text<<endl;
                display "Decipher:  "<<new_text<<endl;
           end switch
           case 3:
                StartTHeProgram()
           end switch
    StartRail_fenceCipher()
End Function
 Function  IsValidText( text)
     For  i=0  to length of text 
            If(!isdigit(text[i]) and !isspace(text[i])) then
                 text=ReadText("please enter a valid text! ")
                  i=0
                  continue
            end if
     end for
     return text
End Function
 Function CipherText(string text)
     declare cipher_text=""
     for  i=0  to length of text-1
           if(toupper(text[i])=='A') cipher_text= cipher_text +"aaaaa"
           else if (toupper(text[i])=='B') cipher_text= cipher_text +"aaaab"
           else if (toupper(text[i])=='C') cipher_text= cipher_text +"aaaba"
           else if (toupper(text[i])=='D') cipher_text= cipher_text +"aaabb"
           else if (toupper(text[i])=='E') cipher_text= cipher_text +"aabaa"
           else if (toupper(text[i])=='F') cipher_text= cipher_text +"aabab"
           else if (toupper(text[i])=='G') cipher_text= cipher_text +"aabba"
           else if (toupper(text[i])=='H') cipher_text= cipher_text +"aabbb"
           else if (toupper(text[i])=='I') cipher_text= cipher_text +"abaaa"
           else if (toupper(text[i])=='J') cipher_text= cipher_text +"abaab"
           else if (toupper(text[i])=='K') cipher_text= cipher_text +"ababa"
           else if (toupper(text[i])=='L') cipher_text= cipher_text +"ababb"
           else if (toupper(text[i])=='M') cipher_text= cipher_text +"abbaa"
           else if (toupper(text[i])=='N') cipher_text= cipher_text +"abbab"
           else if (toupper(text[i])=='O') cipher_text= cipher_text +"abbba"
           else if (toupper(text[i])=='P') cipher_text= cipher_text +"abbbb"
           else if (toupper(text[i])=='Q') cipher_text= cipher_text +"baaaa"
           else if (toupper(text[i])=='R') cipher_text= cipher_text +"baaab"
           else if (toupper(text[i])=='S') cipher_text= cipher_text +"baaba"
           else if (toupper(text[i])=='T') cipher_text= cipher_text +"baabb"
           else if (toupper(text[i])=='U') cipher_text= cipher_text +"babaa"
           else if (toupper(text[i])=='V') cipher_text= cipher_text +"babab"
           else if (toupper(text[i])=='W') cipher_text= cipher_text +"babba"
           else if (toupper(text[i])=='X') cipher_text= cipher_text +"babbb"
           else if (toupper(text[i])=='Y') cipher_text= cipher_text +"bbaaa"
           else if (toupper(text[i])=='Z') cipher_text= cipher_text +"bbaab"
           else cipher_text= cipher_text + text[i]
    end for
    return cipher_text
End Function
 Function DecipherText( text)
    declare decipher_text="",five_characters=””;
    decalare n_char=length of text
    while(true)
        if(text=="") then
            end while
        end if
        else if(!isalpha(text[0])) then
            decipher_text= decipher_text+text[0]
            text.erase(0,1)
            continue
        end else if
        five_characters= five_characters+text.substr(0,5)
        text.erase(0,5)
        if(five_characters=="aaaaa")decipher_text= decipher_text+'A'
        else if (five_characters=="aaaab")decipher_text= decipher_text+'B'
        else if (five_characters=="aaaba") decipher_text= decipher_text+'C'
        else if (five_characters=="aaabb") decipher_text= decipher_text+'D'
        else if (five_characters=="aabaa") decipher_text= decipher_text+'E'
        else if (five_characters=="aabab") decipher_text= decipher_text+'F'
        else if (five_characters=="aabba") decipher_text= decipher_text+'G'
        else if (five_characters=="aabbb") decipher_text= decipher_text+'H'
        else if (five_characters=="abaaa") decipher_text= decipher_text+'I'
        else if (five_characters=="abaab") decipher_text= decipher_text+'J'
        else if (five_characters=="ababa") decipher_text= decipher_text+'K'
        else if (five_characters=="ababb") decipher_text= decipher_text+'L'
        else if (five_characters=="abbaa") decipher_text= decipher_text+'M'
        else if (five_characters=="abbab") decipher_text= decipher_text+'N'
        else if (five_characters=="abbba") decipher_text= decipher_text+'O'
        else if (five_characters=="abbbb") decipher_text= decipher_text+'P'
        else if (five_characters=="baaaa") decipher_text= decipher_text+'Q'
        else if (five_characters=="baaab") decipher_text= decipher_text+'R'
        else if (five_characters=="baaba") decipher_text= decipher_text+'S'
        else if (five_characters=="baabb") decipher_text= decipher_text+'T'
        else if (five_characters=="babaa") decipher_text= decipher_text+'U';
        else if (five_characters=="babab") decipher_text= decipher_text+'V';
        else if (five_characters=="babba") decipher_text= decipher_text+'W';
        else if (five_characters=="babbb") decipher_text= decipher_text+'X';
        else if (five_characters=="bbaaa") decipher_text= decipher_text+'Y';
        else if (five_characters=="bbaab") decipher_text= decipher_text+'Z';
        five_characters="";
    end for
    return decipher_text
End Function
Function StartBaconianCipher()
    declare original_text=””,new_text=””
    declare choise=0
    display "Welcome to Baconian Cipher"
    display "What do you like to do today?"
    display "1- Cipher a message "
    display "2- Decipher a message "
    display "3- End"
    do
        display "please enter a number from 1 to 3! "
        read choise
        if(to_string(choise).find(' ')!=to_string(choise).npos)continue
     while (choise!=1 and choise!=2 and choise!=3 )
    switch (choise)
    case 1:
        original_text=ReadText("Please enter the message to cipher:  ")
        new_text=CipherText(original_text)
        display "Plain:  ",original_text
        display "Cipher:  ",new_text
        end switch
    case 2:
        original_text=ReadText("Please enter the message to decipher:  ");
        new_text=DecipherText(original_text);
        display  "Plain:  ",original_text
        display  "Decipher:  ",new_text
        end switch
    case 3:
        StartTHeProgram()
    StartBaconianCipher()
End Function
Function IsValidKey( text)
    if(length of text!=5) then 
         return false
    end if
    for i=0 to length of text -1
         if(isalpha(text[i]) or ispunct(text[i]) or isspace(text[i])) then 
             return false
         enf if 
         for j=0 to length of text -1
            if(text[i]==text[j] and i!=j) then 
              return false
            end if
         end for
    end for
    return true
End Function           
 Function read_key( message)
    declare key=””
    display message
    read key
    while (!IsValidKey( key))
        display "Please enter a valid Key consist from five digits! "
       read key
    end while
    return key
End Function
 Function CipherText( text, key, matrix[6][6])
    declare cipher_text=""
    declare found=false
   for i=0 to length of text
        found=false
        if (isdigit(text[i]) or isspace(text[i]) or ispunct(text[i])) then
            cipher_text= cipher_text+text[i]
        end if
        else
            for r=0 to 5    
               for c=0 to 5
                   if(toupper(text[i])==matrix[r][c])
                       cipher_text = cipher_text + matrix[r][0]
                       cipher_text = cipher_text + matrix[0][c]
                       found=true
                      end for 
                   end if  
                   else if(toupper(text[i])=='J')then
                       cipher_text = cipher_text + matrix[2][0]
                       cipher_text = cipher_text + matrix[0][4]
                       found=true
                       end for
                   end if
                end for
                if(found) then break 
            end for
     end for 
    return cipher_text
 End Function
Function DecipherText( text, key, matrix[6][6])
    declare decipher_text=""
    declare sub_text,first_digit,second_digit;
       for i=0 to length of text increase i with 2
            if ( isspace(text[i]) or ispunct(text[i]) or isalpha(text[i])) then
                decipher_text= decipher_text+text[i]
                i=i-1
            end if
            else
                sub_text=stoi(text.substr(i,2))
                first_digit=sub_text/10 
                second_digit=sub_text%10
            for c=0 to 5
                if(second_digit==(matrix[0][c]-'0'))then
                    for r=0 to 5
                        if(first_digit==(matrix[r][0]-'0'))
                               decipher_text= decipher_text+matrix[r][c];
                               break
                          end if
                    end for
                end if
            end for
        end else
    end for
    return decipher_text
End Function
Function StartPolybiusSquareCipher()
    declare original_text,new_text,key=””
    declare choise=0
     display "Welcome to Polybius Square Cipher"
     key=read_key("please enter the key! ")
    char matrix[6][6]={{' ',key[0],key[1],key[2],key[3],key[4]},
                       {key[0],'A',   'B',   'C',   'D',   'E'},
                       {key[1],'F',   'G',   'H',   'I',   'K'},
                       {key[2],'L',   'M',   'N',   'O',   'P'},
                       {key[3],'Q',   'R',   'S',   'T',   'U'},
                       {key[4],'V',   'W',   'X',   'Y',   'Z'}}
    display "What do you like to do today?"
    display "1- Cipher a message "
    display "2- Decipher a message "
    display "3- End"
    do
        display "please enter a number from 1 to 3! "
        read choise
     while (choise!=1 and choise!=2 and choise!=3 )
    switch (choise)
    case 1:
        original_text=ReadText("Please enter the message to cipher:  ")
        new_text=CipherText(original_text,key,matrix)
        display "Plain:  ",original_text
        display "Cipher:  ",new_text
        End switch
    
    case 2:
        original_text=ReadText("Please enter the message to decipher:  ")
        new_text=DecipherText(IsValidText(original_text),key,matrix)
        display "Plain:  ",original_text
        display "Decipher:  ",new_text
        End switch
    case 3:
        StartTHeProgram()
    End switch
    StartPolybiusSquareCipher()
Function StartTHeProgram()
Begain
    StartTHeProgram()
End
*/
#include<iostream>
#include<limits>
#include<string>
using namespace std;
enum enchoises{ Cipher=1  , Decipher=2 ,  End=3};
enum enchoise_version{ CipherV1=1 , CipherV2=2 , DecipherV1=3 , DecipherV2=4 ,  EndAtbash=5};
enum enCipherType{  Rail_fence=1 , PolybiusSquare=2 , Baconian=3 ,Atbash=4,  Exist=5};
void StartTHeProgram();
string ProcessingText(string text);
void print_matrix(char **matrix , char key,int n_columns,string original_text);
string ReadText(string message);
string ProcessingText(string text);
char ReadKey(string message);
 void InputMatrixWithStars(char **matrix , char key,int n_columns);
 void InputMatrixWithCharactersV1(char **matrix , char key,int n_columns,string text);
 void InputMatrixWithCharactersV2(char **matrix , char key,int n_columns,string text);
 string CipherText(char **matrix , char key,int n_columns,string text);
 string DecipherText(char **matrix , char key,int n_columns,string text);
 void StartRail_fenceCipher();
 string CipherTextV1(string text);
string CipherTextV2(string text);
void start_atbash_cipher();
 string IsValidText(string text);
 string CipherText(string text);
 string DecipherText(string text);
 void StartBaconianCipher();
 bool IsValidKey(string text);
 string read_key(string message);
 string CipherText(string text,string key,char matrix[6][6]);
string DecipherText(string text,string key,char matrix[6][6]);
void StartPolybiusSquareCipher();

void StartTHeProgram();
int main()
{
  StartTHeProgram();
}
string ProcessingText(string text);
void print_matrix(char **matrix , char key,int n_columns,string original_text)
{
    n_columns=ProcessingText(original_text).length();
    cout<<endl;
     for(int r=0; r<key-'0' ; r++)
    {
        for(int c=0 ; c<n_columns ; c++)
        {
            cout<<"  "<<matrix[r][c]<<"  ";
        }
    cout<<endl;
    }   
    cout<<endl; 
}
//the key is contains a five digits only and It is not allowed to repeat a specific number
bool IsValidKey(string text)
{
    if(text.length()!=5)return false;
    
    for(int i=0 ; i<text.length() ; i++)
    {
        //condition to check if it contains a alpha or space or punctuations
         if(isalpha(text[i]) || ispunct(text[i]) || isspace(text[i]))return false;
         //this loop to check on the repeating
         for(int j=0 ; j<text.length() ; j++)
         {
            if(text[i]==text[j] and i!=j)return false;
         }
    }
    return true;
}                                                                                                                                                         

//this function to read the key of encryption from the user
//To decipher the message, you must enter the same key used to encrypt it
//the sender who ciphers the message and the receiver who decipher it BOTH must know the same key
string read_key(string message)
{
    string key;
    cout<<message;
    getline(cin,key);
    while (!IsValidKey( key))
    {
        cout<<"Please enter a valid Key consist from five digits! ";
       getline(cin,key);
    } 
    
    return key;
}
//The Polybius square is a table that allows someone to convert letters into numbers.
//It consists of a grid, typically 5x5 or 6x6, where each cell contains a unique pair of coordinates (row and column)
//The letters of the alphabet are placed in the grid based on their position (e.g., A at (1,1), B at (1,2), C at (1,3), and so on)
//if the key is 1 ,2 ,3,4,5 then
//Plain: ABCDEFGHIJKLMNOPQRSTUVWXYZ ,Cipher: ZYXWVUTSRQPONMLKJIHGFEDCBA  
//this funcion to do all previous notes 
string CipherText(string text,string key,char matrix[6][6])
{
    string cipher_text="";
    bool found=false; 
    
    //this loop to convert the character to digit
    for (int i = 0; i < text.length(); i++) {
        found=false;
        //this condition to ignore any space or digit or punctuation
        if (isdigit(text[i]) || isspace(text[i]) || ispunct(text[i])) {
            cipher_text+=text[i];
        }
        else
        {
            for(int r=0 ; r<6 ; r++ )
    {
         for(int c=0 ; c<6 ; c++ )
         {
               if(toupper(text[i])==matrix[r][c])
               {
                 cipher_text += matrix[r][0];
                 cipher_text += matrix[0][c];
                 found=true;
                break; 
               }
               //the position of I is same position of J
               else if(toupper(text[i])=='J')
               {
                 cipher_text += matrix[2][0];
                 cipher_text += matrix[0][4];
                 found=true;
                break; 
               }
         }
         if(found)break; 
    }
        }
    }
    return cipher_text;
}
//this function to Decryption text
string DecipherText(string text,string key,char matrix[6][6])
{
    string decipher_text="";
    //sub text is variable to store each two digit to decipher them
    short sub_text,first_digit,second_digit;
     //this loop to check on all characters in the text and decipher each two digit
    for (int i = 0; i < text.length(); i+=2) {
        //this condition to ignore any space or character or punctuation
        if ( isspace(text[i]) || ispunct(text[i]) || isalpha(text[i])) {
            decipher_text+=text[i];
            i-=1;
        }
        
        else
        {
            sub_text=stoi(text.substr(i,2)); 
            first_digit=sub_text/10; 
            second_digit=sub_text%10;
            //this loop to decipher each two digit 
            //each two digit express about one character 
            for(short c=0 ; c<6 ; c++)
            {
                if(second_digit==(matrix[0][c]-'0'))
                {
                    for(short r=0 ; r<6 ; r++)
                    {
                        if(first_digit==(matrix[r][0]-'0'))
                        {
                            //r is sympol for number row that equal first character that exist in sub_text
                            //c is sympol for number row that equal second character that exist in sub_text
                               decipher_text+=matrix[r][c];
                               break;
                        }
                    }
                }
            }
           
        }
    }
    return decipher_text;
}

//this funtion to show the menu for the user and to start the Cipher a message or decipher a message 
void StartPolybiusSquareCipher()
{
    enchoises choises;
    string original_text,new_text,key;
    short choise;
     cout<<"Welcome to Polybius Square Cipher\n";
    key=read_key("please enter the key! ");
    char matrix[6][6]={{' ',key[0],key[1],key[2],key[3],key[4]},
                       {key[0],'A',   'B',   'C',   'D',   'E'},
                       {key[1],'F',   'G',   'H',   'I',   'K'},
                       {key[2],'L',   'M',   'N',   'O',   'P'},
                       {key[3],'Q',   'R',   'S',   'T',   'U'},
                       {key[4],'V',   'W',   'X',   'Y',   'Z'}};
    cout<<"What do you like to do today?\n";
    cout<<"1- Cipher a message \n";
    cout<<"2- Decipher a message \n";
    cout<<"3- End\n";
    do
    {
        cout<<"please enter a number from 1 to 3! ";
        cin>>choise;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (choise!=1 && choise!=2 && choise!=3 );

    switch ((enchoises)choise)
    {
    case Cipher:
        original_text=ReadText("Please enter the message to cipher:  ");
        new_text=CipherText(original_text,key,matrix);
        cout<<"Plain:  "<<original_text<<endl;
        cout<<"Cipher:  "<<new_text<<endl;
        break;
    
    case Decipher:
        original_text=ReadText("Please enter the message to decipher:  ");
        new_text=DecipherText(IsValidText(original_text),key,matrix);
        cout<<"Plain:  "<<original_text<<endl;
        cout<<"Decipher:  "<<new_text<<endl;
        break;
    
    case End:
        StartTHeProgram();
        return;
    }
    
    StartPolybiusSquareCipher();
}

string CipherText(string text)
{
    string cipher_text="";
    for(int i=0 ; i<text.length() ; i++)
    {

        if(toupper(text[i])=='A')cipher_text+="aaaaa";
        else if (toupper(text[i])=='B')cipher_text+="aaaab";
        else if (toupper(text[i])=='C')cipher_text+="aaaba";
        else if (toupper(text[i])=='D')cipher_text+="aaabb";
        else if (toupper(text[i])=='E')cipher_text+="aabaa";
        else if (toupper(text[i])=='F')cipher_text+="aabab";
        else if (toupper(text[i])=='G')cipher_text+="aabba";
        else if (toupper(text[i])=='H')cipher_text+="aabbb";
        else if (toupper(text[i])=='I')cipher_text+="abaaa";
        else if (toupper(text[i])=='J')cipher_text+="abaab";
        else if (toupper(text[i])=='K')cipher_text+="ababa";
        else if (toupper(text[i])=='L')cipher_text+="ababb";
        else if (toupper(text[i])=='M')cipher_text+="abbaa";
        else if (toupper(text[i])=='N')cipher_text+="abbab";
        else if (toupper(text[i])=='O')cipher_text+="abbba";
        else if (toupper(text[i])=='P')cipher_text+="abbbb";
        else if (toupper(text[i])=='Q')cipher_text+="baaaa";
        else if (toupper(text[i])=='R')cipher_text+="baaab";
        else if (toupper(text[i])=='S')cipher_text+="baaba";
        else if (toupper(text[i])=='T')cipher_text+="baabb";
        else if (toupper(text[i])=='U')cipher_text+="babaa";
        else if (toupper(text[i])=='V')cipher_text+="babab";
        else if (toupper(text[i])=='W')cipher_text+="babba";
        else if (toupper(text[i])=='X')cipher_text+="babbb";
        else if (toupper(text[i])=='Y')cipher_text+="bbaaa";
        else if (toupper(text[i])=='Z')cipher_text+="bbaab";
       else cipher_text+=text[i];
    }
    return cipher_text;
}
string DecipherText(string text)
{
    string decipher_text="",five_characters;
    int n_char=text.length();
    while(true)
    {
        if(text=="")break;
        else if(!isalpha(text[0]))
        {
            decipher_text+=text[0];
            text.erase(0,1);
            continue;
        }
        five_characters+=text.substr(0,5);
        text.erase(0,5);
        if(five_characters=="aaaaa")decipher_text+='A';
        else if (five_characters=="aaaab")decipher_text+='B';
        else if (five_characters=="aaaba")decipher_text+='C';
        else if (five_characters=="aaabb")decipher_text+='D';
        else if (five_characters=="aabaa")decipher_text+='E';
        else if (five_characters=="aabab")decipher_text+='F';
        else if (five_characters=="aabba")decipher_text+='G';
        else if (five_characters=="aabbb")decipher_text+='H';
        else if (five_characters=="abaaa")decipher_text+='I';
        else if (five_characters=="abaab")decipher_text+='J';
        else if (five_characters=="ababa")decipher_text+='K';
        else if (five_characters=="ababb")decipher_text+='L';
        else if (five_characters=="abbaa")decipher_text+='M';
        else if (five_characters=="abbab")decipher_text+='N';
        else if (five_characters=="abbba")decipher_text+='O';
        else if (five_characters=="abbbb")decipher_text+='P';
        else if (five_characters=="baaaa")decipher_text+='Q';
        else if (five_characters=="baaab")decipher_text+='R';
        else if (five_characters=="baaba")decipher_text+='S';
        else if (five_characters=="baabb")decipher_text+='T';
        else if (five_characters=="babaa")decipher_text+='U';
        else if (five_characters=="babab")decipher_text+='V';
        else if (five_characters=="babba")decipher_text+='W';
        else if (five_characters=="babbb")decipher_text+='X';
        else if (five_characters=="bbaaa")decipher_text+='Y';
        else if (five_characters=="bbaab")decipher_text+='Z';
        five_characters="";
    }
  return decipher_text;
}
//this funtion to show the menu for the user and to start the Cipher a message or decipher a message 
void StartBaconianCipher()
{
    enchoises choises;
    string original_text,new_text;
    int choise;
    cout<<"Welcome to Baconian Cipher\n";
    cout<<"What do you like to do today?\n";
    cout<<"1- Cipher a message \n";
    cout<<"2- Decipher a message \n";
    cout<<"3- End\n";
    do
    {
        cout<<"please enter a number from 1 to 3! ";
        cin>>choise;
        if(to_string(choise).find(' ')!=to_string(choise).npos)continue;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (choise!=1 && choise!=2 && choise!=3 );

    switch ((enchoises)choise)
    {
    case Cipher:
        original_text=ReadText("Please enter the message to cipher:  ");
        new_text=CipherText(original_text);
        cout<<"Plain:  "<<original_text<<endl;
        cout<<"Cipher:  "<<new_text<<endl;
        break;
    
    case Decipher:
        original_text=ReadText("Please enter the message to decipher:  ");
        new_text=DecipherText(original_text);
        cout<<"Plain:  "<<original_text<<endl;
        cout<<"Decipher:  "<<new_text<<endl;
        break;
    
    case End:
        StartTHeProgram();
        return;
    }
    
    StartBaconianCipher();
}
//this function to read the text from the user
string ReadText(string message)
{
    string text;
    cout<<message;
    cin.ignore();
    getline(cin,text);
    return text;
}
//this function to remove any characer is not alpha from the text
string ProcessingText(string text)
{
    string new_text;
     for (int i = 0; i < text.length(); i++) {
        if(isspace(text[i]) or isdigit(text[i]) or ispunct(text[i]))continue;
        new_text+=text[i];
    }
    return new_text;
}
//The key for the railfence cipher is just the number of rails. To encrypt a piece of text
char ReadKey(string message)
{
    char key;
    short n_key;
    do
    {
    cout<<message;
    cin>>n_key;
    if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (n_key!=3 && n_key!=4);
    
    return (n_key==3)?'3':'4' ;
}
 //this function to Input Matrix With stars as diagonal
    void InputMatrixWithStars(char **matrix , char key,int n_columns)
{
    short counter=0,sign=1;
    int index=0,R=0;
    matrix[0][0]='*';                 
        for(int c=0 ; c<n_columns ;c++)
        {
              if(R==0 && c==0)continue;
             else if((++counter)==key-'0')
             {
                sign*=-1;
                counter=1;
             }
             R= R+sign*1;
             matrix[R][c]='*';
        }
    //this loop to store space in any cell is not has star as character
       for(int r=0; r<key-'0' ; r++)
    {
        for(int c=0 ; c<n_columns ; c++)
        {
            if(matrix[r][c]!='*')
            matrix[r][c]='-';
        }
    
    }    
    
}
//this function to Input Matrix With Characters as diagonal column by column
void InputMatrixWithCharactersV1(char **matrix , char key,int n_columns,string text)
{
    int index=0;
      for(int c=0 ; c<n_columns ; c++)
    {
            for(int r=0; r<key-'0' ; r++)
     {
            if(matrix[r][c]=='*')
            {
                  matrix[r][c]=text[index];
                  index++;
            }
        }
    }
}
//this function to Input Matrix With Characters as diagonal row by row
void InputMatrixWithCharactersV2(char **matrix , char key,int n_columns,string text)
{
    int index=0;
    for(int r=0; r<key-'0' ; r++)
    {
      for(int c=0 ; c<n_columns ; c++)
    
        {
            if(matrix[r][c]=='*')
            {
                matrix[r][c]=text[index];
                index++;
            }
        }
    }
}
//this function to cipher Text
string CipherText(char **matrix , char key,int n_columns,string text)
{
    InputMatrixWithStars(matrix ,  key, n_columns);
    InputMatrixWithCharactersV1(matrix ,  key, n_columns, text);
     string cipher_text="";
    for(int r=0; r<key-'0' ; r++)
    {
        for(int c=0 ; c<n_columns ; c++)
        {
            if(isalpha(matrix[r][c]))
            {
                  cipher_text+=matrix[r][c];
            }
        }
    }   

    return cipher_text;
}
//this function to Decipher Text 
string DecipherText(char **matrix , char key,int n_columns,string text)
{
    InputMatrixWithStars(matrix ,  key, n_columns);
    InputMatrixWithCharactersV2(matrix ,  key, n_columns, text);
     string decipher_text="";
        for(int c=0 ; c<n_columns ; c++)
            {
            for(int r=0; r<key-'0' ; r++)
                {
                    if(isalpha(matrix[r][c]))
                        {
                           decipher_text+=matrix[r][c];
                        }
                }
            }   

    return decipher_text;
}
//this funtion to show the menu for the user and to start the Cipher a message or decipher a message 
void StartRail_fenceCipher()
{
    enchoises choises;
    string original_text,new_text;
    char key;
    short choise;
    int n_columns;
     cout<<"Welcome to Rail-fence Cipher\n";
     key=ReadKey("please enter your key! 3/4 ");
     original_text=ReadText("Please enter the message :  ");
     //value of n_columns equal number of characters in the text 
    n_columns=original_text.length();
    //definition daynamic 2D array
     char **matrix=new char *[key-'0'];
    for(int i=0; i<key-'0' ; i++)
    {
        matrix[i]=new char [n_columns];
    }
    cout<<"What do you like to do today?\n";
    cout<<"1- Cipher a message \n";
    cout<<"2- Decipher a message \n";
    cout<<"3- End\n";
    do
    {
        cout<<"please enter a number from 1 to 3! ";
        cin>>choise;
        //if the input is invalid ask the user again 
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (choise!=1 && choise!=2 && choise!=3 );

    switch ((enchoises)choise)
    {
    case Cipher:
        new_text=CipherText( matrix ,  key, n_columns,ProcessingText(original_text));
         print_matrix( matrix ,  key, n_columns,original_text);
        cout<<"Plain:  "<<original_text<<endl;
        cout<<"Cipher:  "<<new_text<<endl;
        break;
    case Decipher:
        new_text=DecipherText( matrix ,  key, n_columns,ProcessingText(original_text));
        print_matrix( matrix ,  key, n_columns,original_text);
        cout<<"Plain:  "<<original_text<<endl;
        cout<<"Decipher:  "<<new_text<<endl;
        break;
    case End:
        StartTHeProgram();
        return;
    }
    
    StartRail_fenceCipher();
}
string IsValidText(string text)
{
    for(int i=0 ; i<text.length() ; i++)
    {
        if(!isdigit(text[i]) && !isspace(text[i]))
        {
            text=ReadText("please enter a valid text! ");
            i=0;
            continue;
        }
    }
    return text;
}
//The Atbash cipher is a very common, simple cipher. Basically, when encoded, an "A" becomes a "Z", "B" turns into "Y", etc.
//Plain: ABCDEFGHIJKLMNOPQRSTUVWXYZ ,Cipher: ZYXWVUTSRQPONMLKJIHGFEDCBA  
//this funcion to do all previous notes 
string CipherTextV1(string text)
{
    string cipher_text="";
    for (int i = 0; i < text.length(); i++) {
        if (isdigit(text[i]) || isspace(text[i]) || ispunct(text[i])) {
            continue;
        }
        else
        {
            //convert any small character to capital
            text[i] = toupper(text[i]);
            cipher_text += char('Z' - (text[i] - 'A'));
        }
    }
    return cipher_text;
}
//this function  that divides the alphabet into 2 halves and does the same thing on each half separate.
 //example: Plain: ABCDEFGHIJKLMNOPQRSTUVWXYZ & Cipher: MLKJIHGFEDCBA ZYXWVUTSRQPON
string CipherTextV2(string text) {
    string cipher_text="";
    for (int i = 0; i < text.length(); i++) {
        if (isdigit(text[i]) || isspace(text[i]) || ispunct(text[i])) {
            continue;
        }
        //if the character between A and M,then do this 
         else if(toupper(text[i])>=65 && toupper(text[i])<=77) 
        {
            text[i] = toupper(text[i]);
            cipher_text += char('M' - (text[i] - 'A'));
        }
        //if the character between N and Z,then do this
        else
        {
            text[i] = toupper(text[i]);
            cipher_text += char('Z' - (text[i] - 'N'));
        }
    }
    return cipher_text;
}
//this funtion to show the menu for the user and to start the Cipher a message or decipher a message 
void start_atbash_cipher()
{
    enchoise_version choises;
    string original_text,new_text;
    int choise;
    cout<<"Welcome to atbash cipher\n";
    cout<<"What do you like to do today?\n";
    cout<<"1- Cipher a message V1.0\n";
    cout<<"2- Cipher a message V2.0\n";
    cout<<"3- Decipher a message V1.0\n";
    cout<<"4- Decipher a message V2.0\n";
    cout<<"5- End\n";
    do
    {
        cout<<"please enter a number from 1 to 5! ";
        cin>>choise;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (choise!=1 && choise!=2 && choise!=3  && choise!=4  && choise!=5);

    switch ((enchoise_version)choise)
    {
    case CipherV1:
        original_text=ReadText("Please enter the message to cipher:  ");
        new_text=CipherTextV1(original_text);
        cout<<"Plain:  "<<original_text<<endl;
        cout<<"Cipher:  "<<new_text<<endl;
        break;
    case CipherV2:
        original_text=ReadText("Please enter the message to cipher:  ");
        new_text=CipherTextV2(original_text);
        cout<<"Plain:  "<<original_text<<endl;
        cout<<"Cipher:  "<<new_text<<endl;
        break;
    case DecipherV1:
        original_text=ReadText("Please enter the message to decipher:  ");
        new_text=CipherTextV1(original_text);
        cout<<"Plain:  "<<original_text<<endl;
        cout<<"Decipher:  "<<new_text<<endl;
        break;
    case DecipherV2:
        original_text=ReadText("Please enter the message to decipher:  ");
        new_text=CipherTextV2(original_text);
        cout<<"Plain:  "<<original_text<<endl;
        cout<<"Decipher:  "<<new_text<<endl;
        break;
    case EndAtbash:
        StartTHeProgram();
        break;
    }
    
     StartTHeProgram();
}
void StartTHeProgram()
{
    enCipherType CipherType;
    int choise;
    cout<<"Which Cipher do you like to choose?\n";
    cout<<"1- Rail_fence Cipher\n";
    cout<<"2- Polybius Square Cipher\n";
    cout<<"3- Baconian Cipher\n";
    cout<<"4- Atbash Cipher\n";
    cout<<"5- Exist\n";
    do
    {
        cout<<"please enter a number from 1 to 4! ";
        cin>>choise;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (choise!=1 && choise!=2  && choise!=3  && choise!=4 && choise!=5);
    switch ((enCipherType)choise)
    {
    case Rail_fence:
       StartRail_fenceCipher();    
        break;
    case PolybiusSquare:
        StartPolybiusSquareCipher();
        break;
    case Baconian:
        StartBaconianCipher();
        break;
    case Atbash:
        start_atbash_cipher();
        break;
    case Exist:
        return;
        }
}

