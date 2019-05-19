#include "Referee.h"

Referee::Referee() : Difficulty(0), SetCount(0), Answer_array(nullptr), Return_value(nullptr)
{
}

Referee::~Referee()
{
    if(Answer_array != nullptr){
        delete Answer_array;
    }
    if(Return_value != nullptr){
        delete Return_value;
    }
}

bool Referee::PLAY_Solo(int Difficulty)
{
    SetCount = 0;
    SetDifficulty(Difficulty);      // Set the Answer array. (dynamic allocated)
    Array Guess_array(Difficulty);  // User's array. 
    bool result_flag = false;       // win <- true, lose <- false

    while(SetCount != 9){
    // 1 loop = 1 set of the game

        string guess;
        while(true){
            cout<<" >> Input your guess("<<Difficulty<<" numbers). 'help' to view help."<<endl;
            guess.clear(); // for "fflush"
            cout<<" >> "; cin >> guess;
            if(guess == "help"){
                ViewHelp();
            }
            else if(guess == "stop"){
                cout<<endl;
                return false;
            }
            else if(guess == "exit"){
                exit(1);
            }
            else if(guess.size() != Difficulty){
                cout<<" >> Please enter the correct number of your guess."<<endl;
            }
            else{
                if(Guess_array.SetArray(guess)){ // return false << the element was overlapping
                    break;
                    // if the "guess" was correct, then break and go to next step; check Answer_array
                }
            }
        }

        Return_value = Answer_array->Check(Guess_array);    
        if(Return_value->isOut()){
            cout<<" >> OUT. "<<endl;
        }
        else{
            if(Return_value->Strike() == Difficulty){ // user win
                result_flag = true;
                break;
            }
            cout<<" >> "<<Return_value->Strike()<<" STRIKE."<<endl;
            cout<<" >> "<<Return_value->Ball()<<" BALL."<<endl;
            Guess_array.clear();
        }
        SetCount++;
        cout<<endl;
        // one set is over
    }

    return result_flag;
}

bool Referee::PLAY_PVP(int difficulty)
{
    SetCount = 0;
    SetDifficulty(Difficulty);      // Set the Answer array.
    Array Guess_array(Difficulty);  // User's array.
    bool result_flag = false;       // win <- true, lose <- false


    /* */

    return result_flag;
}

bool Referee::PLAY_Computer(int difficulty)
{
    SetCount = 0;
    SetDifficulty(Difficulty);      // Set the Answer array.
    Array Guess_array(Difficulty);  // User's array.
    bool result_flag = false;       // win <- true, lose <- false


    /* */

    return result_flag;
}

void Referee::SetDifficulty(int difficulty)
{
    if(Answer_array != nullptr){ // delete previous Answer_array
        delete Answer_array;
    }
    Difficulty = difficulty;
    Answer_array = new Answer(Difficulty);
}

void Referee::ViewHelp() const
{   
    cout<<endl;
    cout<<" >> 'stop' - Stop this game and go to main menu."<<endl;
    cout<<" >> 'exit' - Program exit."<<endl;
    cout<<endl;
}