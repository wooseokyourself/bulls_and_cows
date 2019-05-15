#include "Referee.h"

Referee::Referee() : Difficulty(0), SetCount(0), Return_value(nullptr)
{
}

Referee::~Referee()
{
    delete Answer_array;
    if(Return_value == nullptr)
        delete Return_value;
}

bool Referee::Start(int Difficulty)
{
    SetDifficulty(Difficulty);      // Set the Answer array.
    Array Guess_array(Difficulty);  // User's array.
    bool result_flag = false;       // win <- true, lose <- false

    while(SetCount != 9){
    // 1 loop == 1 set of the game

        string guess;
        while(true){
            cout<<" >> Input your guess("<<Difficulty<<" numbers). 'help' to view help."<<endl;
            cout<<" >> "; cin >> guess;
            if(guess.size() > Difficulty){
                cout<<" >> error : So many."<<endl;
            }
            else if(guess == "help"){
                ViewHelp();
            }
            else if(guess == "stop"){
                cout<<endl;
                return false;
            }
            else if(guess == "exit"){
                exit(1);
            }
            else{
                if(Guess_array.SetArray(guess)){ // return false << the element was overlapping
                    break;
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
        // one set is over
    }

    return result_flag;
}

void Referee::SetDifficulty(int difficulty)
{
    Difficulty = difficulty;
    Answer_array = new Answer(Difficulty);
}

void Referee::ViewHelp() const
{   cout<<endl;
    cout<<" >> 'stop' - Stop this game and go to main menu."<<endl;
    cout<<" >> 'exit' - Program exit."<<endl;
    cout<<endl;
}