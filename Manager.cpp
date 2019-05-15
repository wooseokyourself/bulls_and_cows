#include "Manager.h"

void Manager::Menu()
{
    int choice;

    while(1){
        cout<<" >> 1. Game Start"<<endl;
        cout<<" >> 2. Program exit"<<endl;
        cout<<" >> ";
        cin >> choice;

        if(choice == 1){
            int diff;
            while(true){
                cout<<" >> Choice difficulty (easy: 1 / normal: 2 / hard: 3)"<<endl;
                cout<<" >> "; cin >> diff;
                if(diff!=1 && diff!=2 && diff!=3){
                    cout<<" >> Invalid Difficulty. Choice again."<<endl;
                }
                else break;
            }
            Difficulty = diff + 2;
            Play();
            GameCount++;
        }
        else if(choice == 2){
            cout<<" >> Program exit."<<endl;
            break;
        }
        else{
            cout<<"SYSTEM : Invalid choice."<<endl;
        }
    }
    // 여기 while문 빠져나오면 프로그램 종료
}

void Manager::Play()
{
    if(Game.Start(Difficulty)){
        cout<<" >> You won!"<<endl;
    }
    else{
        cout<<" >> You lose!"<<endl;
    }
}