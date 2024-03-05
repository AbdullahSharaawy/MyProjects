/*program : Number scrabble is played with the list of numbers between 1 and 9. Each player takes 
turns picking a number from the list. Once a number has been picked, it cannot be picked 
again. If a player has picked three numbers that add up to 15, that player wins the game.
However, if all the numbers are used and no player gets exactly 15, the game is a draw*/
//Auther : Abdullah Adel Eid Sharaawy
//ID : 20230522
//Sectin : No Section
//Version : V 1.0
//Data : 2/3/2024
#include<iostream>
#include<string>
#include<vector>
#include<limits>
using namespace std;
vector<int> used_numbers;
vector <int> doesnot_used_numbers={1,2,3,4,5,6,7,8,9};
bool IsFoundInVector(vector<int> used_numbers,int number)// check that the number in vector
{
  for(int element : used_numbers)
  {
    if(element==number)return true;
  }
  return false;
}
//this function to print the list where player will choose a number from it
//doesnot_used_numbers is list store the numbers where player will choose a number from it
//used_numbers is list store the numbers that it was picked from player
void PrintList()
{
  vector <int>::iterator iter1;
  vector <int>::iterator iter2;
  cout<<"[ ";
  for(iter1=doesnot_used_numbers.begin() ; iter1!=doesnot_used_numbers.end() ; iter1++ )
  {
     bool used=false;

        for(iter2=used_numbers.begin() ; iter2!=used_numbers.end() ; iter2++)
  {
      if(*iter1==*iter2)
      {
        used=true;
        break;
      }
  }
  if(!used && *iter1!=doesnot_used_numbers.back())cout<<*iter1<<" , ";
  else if(!used && *iter1==doesnot_used_numbers.back())cout<<*iter1<<"";    
  }
  cout<<" ]! ";
}
// function to get a number from a player,
// check that the number is valid, that's it's from 1 to 9
// and check that it's not already picked
// if the number is not valid or not from 1 to 9 or already picked
// ask the user again for a valid number

int get_valid_number(string message)
{
       int number = 0;
    while (true)
    {
        cout << message;
        PrintList();
        cin >> number;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "please enter a valid number\n";
            continue;
        }
        else if (number <= 0 || number > 9)
        {
            cout << "please enter a valid number\n";
            continue;
        }
        else if (IsFoundInVector(used_numbers, number))
        {
            cout << "number already picked choose another number\n";
            continue;
        }
        // add number to used numbers and return it
        used_numbers.push_back(number);
        return number;
    }

   
   }
int main()
{
int first_player_sum = 0;
int second_player_sum = 0;
int num1=0,num2=0;

while (true)
{
  // get number from first player
  num1 = get_valid_number("first player ,please enter a number from this list: ");
  // add the number to the first_player_sum
  first_player_sum += num1;
  // if the first_player_sum is 15
  // the first player wins and the game ends
  if (first_player_sum == 15)
  {
     cout<<"first player wins!!";
    break;
  }
  // since used_numbers can only have numbers from 1 through 9
  // and can not have repeations, if it has 9 elements
  // thoose elements must be number 1 through 9 (not necessarily in order)
  // so all numbers are picked so the game is a draw and ends
  if (used_numbers.size() == 9)
  {
      cout<<"all numbers picked! the game is a draw!";
    break;
  }
  // get number from second player
  num2 = get_valid_number("second player ,please enter a number from this list: ");
  // add the number to the second_player_sum
  second_player_sum += num2;
  // if the second_player_sum is 15
  // the second player wins and the game ends
  if (second_player_sum == 15)
    {
      cout<<"second player wins!!";
      break;
    }
  // if all numbers are picked, the game is a draw and the game ends
  if (used_numbers.size() == 9)
  {
     cout<<"all numbers picked! the game is a draw!";
    break;
  }
  }
}