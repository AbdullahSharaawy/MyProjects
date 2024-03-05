/*program : Players choose a symbol, either X or O. In their turn, they drop the symbol from top of the 
board (number 6) until it settles in the bottom empty cell,The first player to connect 4 symbols 
horizontally, vertically or diagonally wins.*/
//Auther : Abdullah Adel Eid Sharaawy
//ID : 20230522
//Sectin : No Section
//Version : V 1.0
//Data : 2/3/2024
#include<iostream>
#include<string>
#include<limits>
using namespace std;

short ReadColumn();
//function to fill player option in the table
void FiilTabale(char board[6][7],char sympol)
{
    int Column;

    Column=ReadColumn();
            for(short i=5 ; i>=0 ; i-- )
    {
        if(board[i][Column-1]==' ')
        {
            board[i][Column-1]=sympol;
            break;
        }
        //reapet  loop if column has not space
        else if(i==0 )
        {
            if(board[i][Column-1]=='X' || board[i][Column-1]=='O')
            {
            cout<<"chose another column! \n";
            FiilTabale( board, sympol);
            }
        }
    }
}
//function to read number of column from user
short ReadColumn()
{
    short Column;
    // loop until user enters tru value
    while (true)
    {
      cin>>Column;
   //conditiom to check input
   //input must be number from 1 to 7

    if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "please enter  Number from 1 to 7\n";
            continue;
        }
         if(Column>7 || Column<1)
         {
            cout << "please enter  Number from 1 to 7\n";
            continue;
         }
//loop to fill player option in the table
  
        return Column;
    }

}
//this function to display the board of game 
void DisplayBoard(char board[6][7])
{
    //loop to show the header of table
    for(short j=1 ;j<=7;j++)
    {
        cout<<j<<" | ";
    }
    cout<<endl;
    //loop to show the table
    for(short i=0 ;i<6;i++)
   {
    for(short j=0 ;j<7;j++)
    {
        cout<<board[i][j]<<" | ";
    }
    cout<<endl;
   }

}
//function to know who won in the game
bool WhoWon(char board[6][7])
{
    //we can know who won from this loop if we found four elements are similar in specefic row
     for(short i=0 ; i<6 ; i++)
     {
        //if board[i][3]!='X' or board[i][3]!='O' exsit from the loop 
        if(board[i][3]=='X' || board[i][3]=='O')
    {
        if(board[i][3]==board[i][2] && board[i][3]==board[i][1] && board[i][3]==board[i][0])
        {
            
                    if(board[i][3]=='X')cout<<"Player1 Wins \n";

                    else if(board[i][3]=='O')cout<<"Player2 Wins \n";
                    return true;
                    break;  
        }
        
             if(board[i][3]==board[i][4] && board[i][3]==board[i][5] && board[i][3]==board[i][6])
        {
            
                    if(board[i][3]=='X')cout<<"Player1 Wins \n";

                    else if(board[i][3]=='O')cout<<"Player2 Wins \n";
                    return true;
        }
             if(board[i][3]==board[i][4] && board[i][3]==board[i][5] && board[i][3]==board[i][2])
        {
            
                    if(board[i][3]=='X')cout<<"Player1 Wins \n";

                    else if(board[i][3]=='O')cout<<"Player2 Wins \n";
                    return true;
        }
        if(board[i][3]==board[i][4] && board[i][3]==board[i][1] && board[i][3]==board[i][2])
        {
            
                    if(board[i][3]=='X')cout<<"Player1 Wins \n";

                    else if(board[i][3]=='O')cout<<"Player2 Wins \n";
                    return true;
        }
        }
     }
    //we can know who won from this loop if we found four elements are similar in specefic cloumn
     for(short i=0 ; i<6 ; i++)
     {
        //if board[i][3]!='X' or board[i][3]!='O' exsit from the loop
        if(board[3][i]=='X' || board[3][i]=='O')
        {
            if(board[3][i]==board[2][i] && board[3][i]==board[4][i] && board[3][i]==board[5][i])
            {
        
                    if(board[3][i]=='X')cout<<"Player1 Wins \n";

                    else if(board[3][i]=='O')cout<<"Player2 Wins \n";
                    return true;
            }
     
        if(board[3][i]==board[2][i] && board[3][i]==board[1][i] && board[3][i]==board[0][i])
        {
           
                    if(board[3][i]=='X')cout<<"Player1 Wins \n";

                    else if(board[3][i]=='O')cout<<"Player2 Wins \n";
                    return true;
        }
        if(board[3][i]==board[2][i] && board[3][i]==board[1][i] && board[3][i]==board[4][i])
        {
           
                    if(board[3][i]=='X')cout<<"Player1 Wins \n";

                    else if(board[3][i]=='O')cout<<"Player2 Wins \n";
                    return true;
        }
     }
     }
     //we can know who won from this loop if we found four elements are similar in specefic  diagonal
     for(short i=0 ; i<7 ; i++)
     {
        //if board[i][3]!='X' or board[i][3]!='O' exsit from the loop
        if(board[3][i]=='X' || board[3][i]=='O')
        {
        if(board[3][i]==board[2][i+1] && board[3][i]==board[1][i+2] && board[3][i]==board[0][i+3])
        {
             if(board[3][i]=='X')cout<<"Player1 Wins \n";

                    else if(board[3][i]=='O')cout<<"Player2 Wins \n";
                    return true;
        }
        if(board[3][i]==board[2][i-1] && board[3][i]==board[1][i-2] && board[3][i]==board[0][i-3])
        {
             if(board[3][i]=='X')cout<<"Player1 Wins \n";

                    else if(board[3][i]=='O')cout<<"Player2 Wins \n";
                    return true;
        }
        
         if(board[3][i]==board[4][i-1] && board[3][i]==board[1][i+2] && board[3][i]==board[2][i+1])
        {
             if(board[3][i]=='X')cout<<"Player1 Wins \n";

                    else if(board[3][i]=='O')cout<<"Player2 Wins \n";
                    return true;
        }
         if(board[3][i]==board[4][i-1] && board[3][i]==board[5][i-2] && board[3][i]==board[2][i+1])
        {
             if(board[3][i]=='X')cout<<"Player1 Wins \n";

                    else if(board[3][i]=='O')cout<<"Player2 Wins \n";
                    return true;
        }
        if(board[3][i]==board[4][i+1] && board[3][i]==board[1][i-2] && board[3][i]==board[2][i-1])
        {
             if(board[3][i]=='X')cout<<"Player1 Wins \n";

                    else if(board[3][i]=='O')cout<<"Player2 Wins \n";
                    return true;
        } 
        if(board[3][i]==board[4][i+1] && board[3][i]==board[5][i+2] && board[3][i]==board[2][i-1])
        {
             if(board[3][i]=='X')cout<<"Player1 Wins \n";

                    else if(board[3][i]=='O')cout<<"Player2 Wins \n";
                    return true;
        }          
        }                                                           
     }
 return false;
}
void StartGame(char board[6][7])
{
    cout<<"Welcome to Connect4 Game!! \n";

    DisplayBoard( board);

    
//exist from this loop if we found the winer
  while (true)
  {
    cout<<"Player1: enter Number of Column ! \n";

    FiilTabale( board,'X');
    DisplayBoard(board);

    if(WhoWon( board))break;

    cout<<"Player2: enter Number of Column ! \n";

    FiilTabale( board,'O');
    DisplayBoard(board);

    if(WhoWon( board))break;
  }
     
}
int main()
{
   char board[6][7];
   //loop to store space in each element in the table(array)
   for(short i=0 ;i<6;i++)
   {
    for(short j=0 ;j<7;j++)board[i][j]=' ';
   }
   
   StartGame( board);
}