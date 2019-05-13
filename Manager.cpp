#include "Manager.h"

void Manager::Menu()
{
    int choice;

    while(1){
        cout<<"1. Game Start"<<endl;
        cout<<"2. Program exit"<<endl;
        cout<<" >> ";
        cin >> choice;

        if(choice == 1){
            Play();
            GameCount++;
        }
        else if(choice == 2){
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
    Referee referee;
    referee.Set_Start();
    
}