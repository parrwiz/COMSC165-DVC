/* Author: Parwiz Khan 
 * Professor: Prof. Tsai Peikun
 * Date: 10/10/2019
 * Description: This is a guessing game. The user has to guess a number between 1 and 100.
 * The program will tell the user whether their guess is too high, too low, or correct.
 */


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

 void play_game(){
      int guess;
 
     cout<<"try and guess it"<<endl;
     int number = rand() % 101;
     cout<<"whats your guess: ";
    while (true)
    {
        cin>>guess;
        if (guess == number){
            cout<<"you guessed it!"<<endl;
            break;

        }
        else if (guess < number){
            cout<<"low: ";
        }
        else{
            cout<<"high: ";
        }
    }
    
    

 }
int main()
{
      int choice;
    srand(time(NULL));
    cout<<"*******************************************"<<endl;
    cout<<"* Hello and welcome to the guessing game! *"<<endl;
    cout<<"* I have chosen a number between 1-100.   *\n*         Can you guess it?               *"<<endl;
    cout<<"*******************************************"<<endl;
    cout<<"Press 1 to play"<<endl;
    cout<<"Press 2 to quit"<<endl;
    cin>>choice;
  
    switch (choice)
    {
    case 1:
        play_game();
        break;
    
    case 2:
        cout<<"Goodbye!"<<endl;
        break;
    }
    int guess;
    

    
  return 0;

}